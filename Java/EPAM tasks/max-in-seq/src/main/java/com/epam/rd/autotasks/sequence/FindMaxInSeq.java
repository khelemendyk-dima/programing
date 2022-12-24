package com.epam.rd.autotasks.sequence;
import java.util.Scanner;

public class FindMaxInSeq {
    public static int max() {

        // Put your code here
        Scanner scanner = new Scanner(System.in);
        int max = Integer.MIN_VALUE;
        int currentNum = scanner.nextInt();
        while (currentNum != 0) {
            if (currentNum > max) {
                max = currentNum;
            }
            currentNum = scanner.nextInt();
        }
        return max;
    }

    public static void main(String[] args) {

        System.out.println("Test your code here!\n");

        // Get a result of your code

        System.out.println(max());
    }
}
