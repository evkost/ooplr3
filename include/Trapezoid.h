#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"
#include <vector>

class Trapezoid : public Figure {
private:
    std::vector<Point> vertices;

public:
    Trapezoid();
    Trapezoid(const std::vector<Point>& verts);
    Trapezoid(const Trapezoid& other);
    Trapezoid& operator=(const Trapezoid& other);

    virtual Point getGeometricCenter() const override;
    virtual double getArea() const override;

    virtual void print(std::ostream& os) const override;
    virtual void read(std::istream& is) override;

    virtual double toDouble() const override;

    virtual bool equals(const Figure& other) const override;
};

#endif // TRAPEZOID_H
