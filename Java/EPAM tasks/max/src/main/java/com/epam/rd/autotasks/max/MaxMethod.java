package com.epam.rd.autotasks.max;

public class MaxMethod {
    public static int max(int[] values) {
        int maxValue = Integer.MIN_VALUE;
        for (int value : values) {
            if (value > maxValue) {
                maxValue = value;
            }
        }
        return maxValue;
    }
}
