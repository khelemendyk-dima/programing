package com.epam.rd.autotasks;

import java.util.Locale;
import java.util.Scanner;

public class QuadraticEquation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double c = scanner.nextDouble();
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            System.out.println("no roots");
        } else {
            double sqrtOfDiscriminant = Math.sqrt(discriminant);
            double root1 = (-b - sqrtOfDiscriminant) / (2 * a);
            double root2 = (-b + sqrtOfDiscriminant) / (2 * a);
            if (root1 == root2) {
                System.out.println(root1);
            } else {
                System.out.println(root1 + " " + root2);
            }
        }
    }
}