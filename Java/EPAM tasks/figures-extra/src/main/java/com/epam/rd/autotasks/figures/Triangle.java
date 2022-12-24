package com.epam.rd.autotasks.figures;


class Triangle extends Figure{
    private final Point a;
    private final Point b;
    private final Point c;
    Triangle(final Point a, final Point b, final Point c) {
        if (a == null || b == null || c == null) {
            throw new IllegalArgumentException();
        }
        Point ab = new Point(b.getX() - a.getX(), b.getY() - a.getY());
        Point ac = new Point(c.getX() - a.getX(), c.getY() - a.getY());
        double area = Math.abs((ab.getX() * ac.getY() - ab.getY() * ac.getX()) / 2);
        if (area == 0) {
            throw new IllegalArgumentException();
        }
        this.a = a;
        this.b = b;
        this.c = c;
    }
    @Override
    public Point centroid() {
        double x = (a.getX() + b.getX() + c.getX()) / 3;
        double y = (a.getY() + b.getY() + c.getY()) / 3;
        return new Point(x, y);
    }

    @Override
    public boolean isTheSame(Figure figure) {
        return false;
    }
}
