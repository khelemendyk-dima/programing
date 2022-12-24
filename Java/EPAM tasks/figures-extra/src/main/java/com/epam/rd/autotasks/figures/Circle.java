package com.epam.rd.autotasks.figures;

class Circle extends Figure {
    private final Point center;
    private final double radius;
    public Circle(final Point center, final double radius) {
        if (center == null
                || radius <= 0) {
            throw new IllegalArgumentException();
        }
        this.center = center;
        this.radius = radius;
    }

    @Override
    public Point centroid() {
        return center;
    }

    @Override
    public boolean isTheSame(Figure figure) {
        if (figure.getClass() != this.getClass()) {
            return false;
        }
        Circle obj = (Circle) figure;
        return Math.abs(center.getX() - obj.center.getX()) <= 0.000001
                && Math.abs(center.getY() - obj.center.getY()) <= 0.000001
                && Math.abs(radius - obj.radius) <= 0.000001;

    }
}
