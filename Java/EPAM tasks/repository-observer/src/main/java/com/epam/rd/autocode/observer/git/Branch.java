package com.epam.rd.autocode.observer.git;

import java.util.Arrays;
import java.util.LinkedHashSet;
import java.util.Objects;
import java.util.Set;

public class Branch {

    private final String name;
    private final Set<Commit> commits = new LinkedHashSet<>();

    public Branch(final String name) {
        Objects.requireNonNull(name);
        this.name = name;
    }

    public void addCommits(Commit ... commits) {
        this.commits.addAll(Arrays.asList(commits));
    }

    public Commit[] getCommits() {
        return this.commits.toArray(Commit[]::new);
    }
    @Override
    public boolean equals(final Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        final Branch branch = (Branch) o;
        return name.equals(branch.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }

    @Override
    public String toString() {
        return name;
    }
}
