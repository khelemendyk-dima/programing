package com.epam.rd.autotasks.segments;

import static java.lang.Math.sqrt;
import static java.lang.StrictMath.pow;

class Segment {
    public double x1;
    public double y1;
    public double x2;
    public double y2;
    public Segment(Point start, Point end) {
        if (start.getX() == end.getX()
                && start.getY() == end.getY()) {
            throw new IllegalArgumentException();
        }
        x1 = start.getX();
        y1 = start.getY();
        x2 = end.getX();
        y2 = end.getY();
    }

    double length() {
        return sqrt(pow(x2 - x1, 2) + (pow(y2 - y1, 2)));
    }

    Point middle() {
        double x = (x1 + x2) / 2;
        double y = (y1 + y2) / 2;
        return new Point(x, y);
    }

    Point intersection(Segment another) {
        double x3 = another.x1;
        double y3 = another.y1;
        double x4 = another.x2;
        double y4 = another.y2;
        double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4))
                / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
        double u = ((x1 - x3) * (y1 - y2) - (y1 - y3) * (x1 - x2))
                / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
        if (t >= 0 && t <= 1 && u >=0 && u <= 1) {
            double x = x1 + t * (x2 - x1);
            double y = y1 + t * (y2 - y1);
            return new Point(x, y);
        }
        return null;
    }

}
