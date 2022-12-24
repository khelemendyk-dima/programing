package com.epam.rd.autotasks;

public class QuadraticEquation {
    public String solve(double a, double b, double c) {
        if (a == 0)
            throw new IllegalArgumentException();

        double discriminant = b * b - 4 * a * c;
        double x1 = (-b + Math.sqrt(discriminant)) / (2 * a);
        double x2 = (-b - Math.sqrt(discriminant)) / (2 * a);

        if (discriminant > 0)
            return x1 + " " + x2;
        else if (discriminant == 0)
            return Double.toString(x1);
        else
            return "no roots";
    }
}