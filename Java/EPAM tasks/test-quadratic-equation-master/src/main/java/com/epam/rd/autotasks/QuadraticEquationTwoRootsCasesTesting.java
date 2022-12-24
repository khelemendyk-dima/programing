package com.epam.rd.autotasks;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;

import java.util.Arrays;
import java.util.Collection;

import static org.junit.Assert.assertTrue;

@RunWith(Parameterized.class)
public class QuadraticEquationTwoRootsCasesTesting {
    protected QuadraticEquation quadraticEquation = new QuadraticEquation();

    @Parameterized.Parameters
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][]{
                { 1, -8, 12, "6.0 2.0" },  { 1, -2,  -3, "3.0 -1.0" },
                { 1, -3, -4, "4.0 -1.0" }, { 2, -1, -15, "3.0 -2.5" }
        });
    }

    private final double a;
    private final double b;
    private final double c;
    private final String expected;

    public QuadraticEquationTwoRootsCasesTesting(double a, double b, double c, String expected) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.expected = expected;
    }

    @Test
    public void testTwoRootsCase() {
        String res = quadraticEquation.solve(a, b, c);
        boolean resBool = expected.equals(res);
        if (resBool) {
            assertTrue(true);
        } else {
            String[] resM = res.split(" ");
            assertTrue(resM.length == 2 && expected.equals(resM[1] + " " + resM[0]));
        }
    }

}
