package com.epam.rd.autotasks;

public class CarouselRun {
    protected final int[] array;
    protected int currentEl = 0;
    CarouselRun(final int[] array) {
        this.array = array;
    }
    public int next() {
        if (isFinished()) {
            return -1;
        }
        while (array[currentEl] == 0) {
            currentEl = (currentEl + 1) % array.length;
        }
        int res = array[currentEl];
        array[currentEl]--;
        currentEl = (currentEl + 1) % array.length;
        return res;
    }

    public boolean isFinished() {
        for (int el : array) {
            if (el != 0) {
                return false;
            }
        }
        return true;
    }

}