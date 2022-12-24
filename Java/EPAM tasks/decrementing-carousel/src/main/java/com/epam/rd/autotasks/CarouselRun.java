package com.epam.rd.autotasks;

public class CarouselRun {
    private final int[] array;
    private int currentEl = 0;
    CarouselRun(int[] array) {
        this.array = array;
    }

    public int next() {
        int i = 0;
        while (array[currentEl] == 0) {
            if (i == array.length) {
                return -1;
            }
            currentEl = (currentEl + 1) % array.length;
            i++;
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
