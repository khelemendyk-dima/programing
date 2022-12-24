package com.epam.rd.autotasks.matrices;
import java.util.Arrays;

public class MultiplyMatrix {
    public static int[][] multiply(int[][] matrix1, int[][] matrix2) {

        // Put your code here
        int[][] resMatrix = new int[matrix1.length][matrix2[0].length];
        for (int row = 0; row < resMatrix.length; row++) {
            for (int col = 0; col < resMatrix[row].length; col++) {
                int cell = 0;
                for (int i = 0; i < matrix2.length; i++) {
                    cell += matrix1[row][i] * matrix2[i][col];
                }
                resMatrix[row][col] = cell;
            }
        }
        return resMatrix;
    }

    public static void main(String[] args) {

        System.out.println("Test your code here!\n");

        // Get a result of your code

        int[][] a = {
                {0, 12345},
                {4509, 0},
                {3, 567} };

        int[][] b = {
                {653, 0, 25353},
                {0, 61, 6} };

        int[][] result = multiply(a, b);
        System.out.println(Arrays.deepToString(result).replace("],", "]\n"));
    }
}
