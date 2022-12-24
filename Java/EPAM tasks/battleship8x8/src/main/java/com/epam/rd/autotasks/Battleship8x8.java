package com.epam.rd.autotasks;

import java.math.BigInteger;

public class Battleship8x8 {
    private final long ships;
    private long shots = 0L;

    public Battleship8x8(final long ships) {
        this.ships = ships;
    }

    public boolean shoot(String shot) {
        int letter = Math.abs(shot.charAt(0) - 72);
        int digit = Math.abs(shot.charAt(1) - 56);
        int shotField = digit * 8 + letter;

        BigInteger shipsFields = new BigInteger(Long.toString(ships));
        BigInteger shotsFields = new BigInteger(Long.toString(shots));
        BigInteger newShotFields = shotsFields.setBit(shotField);
        shots = newShotFields.longValue();
        return shipsFields.testBit(shotField) && newShotFields.testBit(shotField);
    }

    public String state() {
        BigInteger shipsF = new BigInteger(Long.toString(ships));
        BigInteger shotsF = new BigInteger(Long.toString(shots));
        StringBuilder sb = new StringBuilder(64);
        for (int i = 63; i >= 0; i--) {
            if (!shipsF.testBit(i) && !shotsF.testBit(i)) {
                sb.append('.');
            } else if (!shipsF.testBit(i) && shotsF.testBit(i)) {
                sb.append('×');
            } else if (shipsF.testBit(i) && !shotsF.testBit(i)) {
                sb.append('☐');
            } else if (shipsF.testBit(i) && shotsF.testBit(i)) {
                sb.append('☒');
            }
            if (i % 8 == 0) {
                sb.append('\n');
            }
        }
        return sb.toString();
    }
}