package com.epam.rd.autotasks;

public class TaskCarousel {
    private final Task[] tasks;
    private int numOfTasks = 0;
    private int currTask = 0;
    public TaskCarousel(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException();
        }
        tasks = new Task[capacity];
    }

    public boolean addTask(Task task) {
        if (task == null
                || task.isFinished()
                || isFull()) {
            return false;
        }
        int i = 0;
        while (tasks[i] != null) {
            if (tasks[i].isFinished()) {
                break;
            }
            i++;
        }
        tasks[i] = task;
        numOfTasks++;
        return true;
    }

    public boolean execute() {
        if (isEmpty()) {
            return false;
        }
        while (tasks[currTask].isFinished()) {
            currTask = (currTask + 1) % tasks.length;
        }
        tasks[currTask].execute();
        if (tasks[currTask].isFinished()) {
            numOfTasks--;
        } else if (numOfTasks > 1){
            currTask = (currTask + 1) % tasks.length;
        }
        return true;
    }

    public boolean isFull() {
        return tasks.length == numOfTasks;
    }

    public boolean isEmpty() {
        return numOfTasks == 0;
    }
}
