package com.epam.rd.autotasks.meetstrangers;

import java.io.IOException;
import java.util.Scanner;

public class HelloStrangers {
    public static void main(String[] args) throws IOException {
        //Write a program, asks for a number - amount of strangers to meet.
        //Then reads stranger names line by line and prints line by line "Hello, ...".
        Scanner scanner = new Scanner(System.in);
        int amountOfStrangers = scanner.nextInt();
        if (amountOfStrangers == 0) {
            System.out.println("Oh, it looks like there is no one here");
        } else if (amountOfStrangers < 0) {
            System.out.println("Seriously? Why so negative?");
        } else {
            String[] strangerNames = new String[amountOfStrangers];
            scanner.nextLine();
            for (int i = 0; i < amountOfStrangers; i++) {
                strangerNames[i] = scanner.nextLine();
            }
            for (int i = 0; i < amountOfStrangers; i++) {
                System.out.println("Hello, " + strangerNames[i]);
            }
        }
    }
}
