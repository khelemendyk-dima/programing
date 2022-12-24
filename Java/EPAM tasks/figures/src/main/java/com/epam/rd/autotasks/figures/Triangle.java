package com.epam.rd.autotasks.figures;

class Triangle extends Figure{
    private final Point a;
    private final Point b;
    private final Point c;
    Triangle(final Point a, final Point b, final Point c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    @Override
    public double area() {
        Point ab = new Point(b.getX() - a.getX(), b.getY() - a.getY());
        Point ac = new Point(c.getX() - a.getX(), c.getY() - a.getY());
        return Math.abs((ab.getX() * ac.getY() - ab.getY() * ac.getX()) / 2);
    }
    @Override
    public String pointsToString() {
        return a.toString() + b.toString() + c.toString();
    }
    @Override
    public Point leftmostPoint() {
        if (a.getX() < b.getX() && a.getX() < c.getX()) {
            return a;
        } else if (b.getX() < c.getX()) {
            return b;
        } else {
            return c;
        }
    }

}
