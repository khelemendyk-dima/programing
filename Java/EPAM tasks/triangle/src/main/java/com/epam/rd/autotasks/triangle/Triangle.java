package com.epam.rd.autotasks.triangle;

import static java.lang.Math.sqrt;
import static java.lang.StrictMath.pow;

class Triangle {
    final private double x1;
    final private double y1;
    final private double x2;
    final private double y2;
    final private double y3;
    final private double x3;
    final private double ab;
    final private double bc;
    final private double ac;
    public Triangle(Point a, Point b, Point c) {
        //TODO
        this.x1 = a.getX();
        this.y1 = a.getY();
        this.x2 = b.getX();
        this.y2 = b.getY();
        this.x3 = c.getX();
        this.y3 = c.getY();
        this.ab = sqrt(pow(x2 - x1, 2) + (pow(y2 - y1, 2)));
        this.bc = sqrt(pow(x3 - x2, 2) + (pow(y3 - y2, 2)));
        this.ac = sqrt(pow(x3 - x1, 2) + (pow(y3 - y1, 2)));
        if ((ab + bc <= ac)
                || (ac + bc <= ab)
                || (ab + ac <= bc)) {
            throw new IllegalArgumentException();
        }
    }

    public double area() {
        //TODO
        double semiP = (ab + bc + ac) / 2;
        return sqrt(semiP * (semiP - ab) * (semiP - bc) * (semiP - ac));
    }

    public Point centroid(){
        //TODO
        double x = (x1 + x2 + x3) / 3;
        double y = (y1 + y2 + y3) / 3;
        return new Point(x, y);
    }

}
