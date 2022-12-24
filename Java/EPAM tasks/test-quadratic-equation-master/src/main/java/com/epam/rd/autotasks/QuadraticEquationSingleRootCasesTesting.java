package com.epam.rd.autotasks;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;

import java.util.Arrays;
import java.util.Collection;

import static org.junit.Assert.assertEquals;

@RunWith(Parameterized.class)
public class QuadraticEquationSingleRootCasesTesting {
    protected QuadraticEquation quadraticEquation = new QuadraticEquation();

    @Parameterized.Parameters
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][]{
                { 2,  4, 2, -1 }, { 1, 12, 36, -6 },
                { 1, -6, 9,  3 }, { 2,  8,  8, -2 }
        });
    }

    private final double a;
    private final double b;
    private final double c;
    private final double expected;

    public QuadraticEquationSingleRootCasesTesting(double a, double b, double c, double expected) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.expected = expected;
    }

    @Test
    public void testSingleRootCase() {
        assertEquals(Double.toString(expected), quadraticEquation.solve(a, b, c));
    }
}