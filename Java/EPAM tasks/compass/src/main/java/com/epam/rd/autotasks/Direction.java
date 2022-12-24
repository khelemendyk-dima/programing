package com.epam.rd.autotasks;

public enum Direction {
    N(0), NE(45), E(90), SE(135), S(180), SW(225), W(270), NW(315);

    Direction(final int degrees) {
        this.degrees = degrees;
    }

    private final int degrees;

    public int getDegrees() {
        return this.degrees;
    }

    public static Direction ofDegrees(int degrees) {
        if (degrees % 45 != 0) {
            return null;
        }
        return closestToDegrees(degrees);
    }

    public static Direction closestToDegrees(int degrees) {
        if (degrees > 360) {
            degrees %= 360;
        }
        if (degrees < 0) {
            degrees += 360;
        }
        if (degrees == 360) {
            return Direction.N;
        }
        Direction minDegree = Direction.N;
        Direction maxDegree = Direction.N;
        for (Direction degree : Direction.values()) {
            if (degree.getDegrees() == degrees) {
                return degree;
            }
            if (degree.getDegrees() < degrees) {
                minDegree = degree;
            } else {
                maxDegree = degree;
                break;
            }
        }
        if (degrees - minDegree.getDegrees() < 22) {
            return minDegree;
        } else {
            return maxDegree;
        }
    }

    public Direction opposite() {
        if (this.degrees + 180 == 360) {
            return Direction.N;
        } else if (this.degrees + 180 > 360) {
            return ofDegrees(this.degrees - 180);
        } else {
            return ofDegrees(this.degrees + 180);
        }
    }

    public int differenceDegreesTo(Direction direction) {
        if (this.degrees == 0 && direction.getDegrees() > 180) {
            return 360 - direction.getDegrees();
        }
        return Math.abs(direction.getDegrees() - this.degrees);
    }
}
