package com.epam.rd.autotasks.arithmeticexpressions;

public class Variable implements Expression {
    private final String name;
    private int value;
    public Variable(String name, int value) {
        if (name == null) {
            throw new IllegalArgumentException();
        }
        this.name = name;
        this.value = value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    @Override
    public int evaluate() {
        return this.value;
    }

    @Override
    public String toExpressionString() {
        return this.name;
    }
}
