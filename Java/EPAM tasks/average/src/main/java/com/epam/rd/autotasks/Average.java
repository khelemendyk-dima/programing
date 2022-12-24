package com.epam.rd.autotasks;

import java.util.Scanner;

public class Average {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Use Scanner methods to read input
        int totalSum = 0;
        int counter = 0;
        for (int currentNum = scanner.nextInt(); currentNum != 0; counter++) {
            totalSum += currentNum;
            currentNum = scanner.nextInt();
        }
        int average = totalSum / counter;
        System.out.println(average);
    }

}