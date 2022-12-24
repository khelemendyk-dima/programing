package com.epam.rd.autotasks.max;

import java.util.OptionalInt;

public class MaxMethod {
    public static OptionalInt max(int[] values) {
        if (values == null || values.length == 0) {
            return OptionalInt.empty();
        }
        int max = Integer.MIN_VALUE;
        for (int val : values) {
            if (val > max) {
                max = val;
            }
        }
        return OptionalInt.of(max);
    }
}
