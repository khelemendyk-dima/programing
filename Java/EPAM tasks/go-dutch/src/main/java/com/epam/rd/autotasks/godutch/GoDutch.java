package com.epam.rd.autotasks.godutch;

import java.util.Scanner;

public class GoDutch {

    public static void main(String[] args) {
        //Write code here
        Scanner scanner = new Scanner(System.in);
        int billTotal = scanner.nextInt();
        int numberOfFriends = scanner.nextInt();
        if (billTotal < 0) {
            System.out.println("Bill total amount cannot be negative");
        } else if (numberOfFriends <= 0) {
            System.out.println("Number of friends cannot be negative or zero");
        } else {
            int billWithTips = billTotal + billTotal / 10;
            int partToPay = billWithTips / numberOfFriends;
            System.out.println(partToPay);
        }
    }
}
