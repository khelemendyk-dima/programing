package com.epam.rd.autotasks.intersection;

public class Line {
    private final int k;
    private final int b;
    public Line(int k, int b) {
        this.k = k;
        this.b = b;
    }

    public Point intersection(Line other) {
        if (this.k == other.k) {
            return null;
        } else {
            int x = (other.b - this.b) / (this.k - other.k);
            int y = (this.k * other.b - other.k * this.b) / (this.k - other.k);
            return new Point(x, y);
        }
    }

}
