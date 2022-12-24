package com.epam.rd.autocode.observer.git;

public class GitRepoObservers {
    public static Repository newRepository() {
        return new ObservableRepository();
    }

    public static WebHook mergeToBranchWebHook(String branchName) {
        WebHookObserver hook = new WebHookObserver(new Branch(branchName));
        hook.setType(Event.Type.MERGE);
        return hook;
    }

    public static WebHook commitToBranchWebHook(String branchName) {
        WebHookObserver hook = new WebHookObserver(new Branch(branchName));
        hook.setType(Event.Type.COMMIT);
        return hook;
    }
}
