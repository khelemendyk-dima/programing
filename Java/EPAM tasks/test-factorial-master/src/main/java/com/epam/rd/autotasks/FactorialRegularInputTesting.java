package com.epam.rd.autotasks;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class FactorialRegularInputTesting {

    Factorial factorial = new Factorial();

    @Test
    void testRegularInput() {
        assertEquals("1", factorial.factorial("0"));
        assertEquals("1", factorial.factorial("1"));
        assertEquals("87178291200", factorial.factorial("14"));
    }

}
