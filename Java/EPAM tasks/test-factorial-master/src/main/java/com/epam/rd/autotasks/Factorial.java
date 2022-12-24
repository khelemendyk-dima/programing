package com.epam.rd.autotasks;

import java.math.BigInteger;

public class Factorial {
    public String factorial(String n) {
        int number = Integer.parseInt(n);

        if (number < 0)
            throw new IllegalArgumentException();

        BigInteger result = new BigInteger("1");

        for (int i = 1; i <= number; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }

        return result.toString();
    }
}
