package com.epam.rd.autocode.observer.git;

import java.util.*;
import java.util.stream.Collectors;

public class ObservableRepository implements Repository {
    private final List<WebHook> observers = new ArrayList<>();
    private final Set<Branch> branches = new HashSet<>();

    public ObservableRepository() { branches.add(new Branch("main")); }

    @Override
    public Branch getBranch(String name) {
        Branch outputBranch = null;
        Branch branchToGet = new Branch(name);
        for (Branch branch : branches) {
            if (branch.equals(branchToGet))
                outputBranch = branch;
        }
        return outputBranch;
    }

    @Override
    public Branch newBranch(Branch sourceBranch, String name) {
        if (branches.contains(new Branch(name)) || !branches.contains(sourceBranch))
            throw new IllegalArgumentException();

        Branch newBranch = new Branch(name);
        newBranch.addCommits(sourceBranch.getCommits());

        branches.add(newBranch);
        return newBranch;
    }

    @Override
    public Commit commit(Branch branch, String author, String[] changes) {
        Commit commit = new Commit(author, changes);
        branch.addCommits(commit);

        for (WebHook observer : observers) {
            if (observer.type() == Event.Type.COMMIT
                    && (branch.toString().equals(observer.branch()))) {
                observer.onEvent(new Event(observer.type(), branch, List.of(commit)));
            }
        }
        
        return commit;
    }

    @Override
    public void merge(Branch sourceBranch, Branch targetBranch) {
        List<Commit> commitsToEvent = getDistinctCommits(sourceBranch, targetBranch);
        
        if (commitsToEvent.isEmpty()) return;

        targetBranch.addCommits(commitsToEvent.toArray(Commit[]::new));
        
        for (WebHook observer : observers) {
            if (observer.type() == Event.Type.MERGE
                && targetBranch.toString().equals(observer.branch()))
                observer.onEvent(new Event(observer.type(), targetBranch, commitsToEvent));
        }
    }

    private static List<Commit> getDistinctCommits(Branch sourceBranch, Branch targetBranch) {
        List<Commit> oldCommits = Arrays.asList(sourceBranch.getCommits());
        List<Commit> newCommits = Arrays.asList(targetBranch.getCommits());

        return oldCommits.stream()
                .filter(commit -> !newCommits.contains(commit))
                .collect(Collectors.toList());
    }

    @Override
    public void addWebHook(WebHook webHook) {
        observers.add(webHook);
    }
}
