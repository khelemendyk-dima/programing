package com.epam.rd.autotasks;

import java.util.Arrays;

class CycleSwap {
    static void cycleSwap(int[] array) {
        if (array.length == 0) {
            return;
        }
        int temp = array[array.length - 1];
        for (int i = array.length - 1; i > 0; i--) {
            array[i] = array[i - 1];
        }
        array[0] = temp;
    }

    static void cycleSwap(int[] array, int shift) {
        if ((array.length == shift) || (array.length == 0)) {
            return;
        }
        int[] tempArr = Arrays.copyOf(array, array.length);
        for (int i = 0; i < array.length; i++) {
            tempArr[(i + shift) % array.length] = array[i];
        }
        System.arraycopy(tempArr, 0, array, 0, array.length);
    }
}
