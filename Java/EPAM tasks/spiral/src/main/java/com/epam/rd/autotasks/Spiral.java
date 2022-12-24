package com.epam.rd.autotasks;

class Spiral {
    static int[][] spiral(int rows, int columns) {
        int[][] spiralArr = new int[rows][columns];

        int dir = 0;
        int currNum = 1;

        int t = 0;
        int l = 0;
        int b = rows - 1;
        int r = columns - 1;

        while (t <= b && l <= r) {
            if (dir == 0) {
                for (int i = l; i <= r; i++) {
                    spiralArr[t][i] = currNum;
                    currNum++;
                }
                t++;
            } else if (dir == 1) {
                for (int i = t; i <= b; i++) {
                    spiralArr[i][r] = currNum;
                    currNum++;
                }
                r--;
            } else if (dir == 2) {
                for (int i = r; i >= l; i--) {
                    spiralArr[b][i] = currNum;
                    currNum++;
                }
                b--;
            } else {
                for (int i = b; i >= t; i--) {
                    spiralArr[i][l] = currNum;
                    currNum++;
                }
                l++;
            }
            dir = (dir + 1) % 4;
        }
        return spiralArr;
    }
}
