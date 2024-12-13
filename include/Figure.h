#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class Figure {
public:
    virtual ~Figure() {}

    virtual Point getGeometricCenter() const = 0;
    virtual double getArea() const = 0;

    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& fig) {
        fig.read(is);
        return is;
    }

    virtual double toDouble() const = 0;

    virtual bool equals(const Figure& other) const = 0;

    bool operator==(const Figure& other) const {
        return equals(other);
    }
};

#endif // FIGURE_H
