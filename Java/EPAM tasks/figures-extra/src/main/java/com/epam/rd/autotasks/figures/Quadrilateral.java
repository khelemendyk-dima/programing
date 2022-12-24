package com.epam.rd.autotasks.figures;

class Quadrilateral extends Figure {
    private final Point a;
    private final Point b;
    private final Point c;
    private final Point d;
    public Quadrilateral(final Point a, final Point b, final Point c, final Point d) {
        if (a == null || b == null || c == null || d == null) {
            throw new IllegalArgumentException();
        }
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        if (centroid() == null) {
            throw new IllegalArgumentException();
        }
    }

    @Override
    public Point centroid() {
        Triangle triangle = new Triangle(a, b, c);
        Point p1 = triangle.centroid();

        triangle = new Triangle(a, c, d);
        Point p2 = triangle.centroid();

        triangle = new Triangle(a, b, d);
        Point p3 = triangle.centroid();

        triangle = new Triangle(b, c, d);
        Point p4 = triangle.centroid();

        double x1 = p1.getX();
        double y1 = p1.getY();
        double x2 = p2.getX();
        double y2 = p2.getY();
        double x3 = p3.getX();
        double y3 = p3.getY();
        double x4 = p4.getX();
        double y4 = p4.getY();

        double divider = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

        double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / divider;
        double u = ((x1 - x3) * (y1 - y2) - (y1 - y3) * (x1 - x2)) / divider;

        if (t >= 0 && t <= 1 && u >=0 && u <= 1) {
            double x = x1 + t * (x2 - x1);
            double y = y1 + t * (y2 - y1);
            return new Point(x, y);
        }
        return null;
    }

    @Override
    public boolean isTheSame(Figure figure) {
        if (figure.getClass() != this.getClass()) {
            return false;
        }
        Quadrilateral obj = (Quadrilateral) figure;
        Point[] main = new Point[]{a, b, c, d};
        Point[] another = new Point[]{obj.a, obj.b, obj.c, obj.d};
        int counter = 0;
        for (Point point : main) {
            for (Point value : another) {
                if (Math.abs(point.getX() - value.getX()) <= 0.000001
                        && Math.abs(point.getY() - value.getY()) <= 0.000001) {
                    counter++;
                }
            }
        }
        return counter == 4;
    }
}
