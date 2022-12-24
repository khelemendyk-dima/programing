package com.epam.rd.autotasks;

public class CarouselRun {
    protected final int[] array;
    protected int currentEl = 0;
    CarouselRun(final int[] array) {
        this.array = array;
    }
    protected int findCurrentEl() {
        int i = 0;
        while (array[currentEl] == 0) {
            if (i == array.length) {
                return -1;
            }
            currentEl = (currentEl + 1) % array.length;
            i++;
        }
        return 0;
    }
    public int next() {
        if (findCurrentEl() == -1) {
            return -1;
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
