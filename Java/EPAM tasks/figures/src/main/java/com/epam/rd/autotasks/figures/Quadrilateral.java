package com.epam.rd.autotasks.figures;

class Quadrilateral extends Figure {
    private final Point a;
    private final Point b;
    private final Point c;
    private final Point d;
    public Quadrilateral(final Point a, final Point b, final Point c, final Point d) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }

    @Override
    public double area() {
        Point ac = new Point(c.getX() - a.getX(), c.getY() - a.getY());
        Point bd = new Point(d.getX() - b.getX(), d.getY() - b.getY());
        return Math.abs((ac.getX() * bd.getY() - ac.getY() * bd.getX()) / 2);
    }

    @Override
    public String pointsToString() {
        return a.toString() + b.toString() + c.toString() + d.toString();
    }

    @Override
    public Point leftmostPoint() {

        if (a.getX() < b.getX() && a.getX() < c.getX() && a.getX() < d.getX()) {
            return a;
        } else if (b.getX() < c.getX() && b.getX() < d.getX()) {
            return b;
        } else if (c.getX() < d.getX()) {
            return c;
        } else {
            return d;
        }
    }
}
