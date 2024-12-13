#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"
#include <vector>

class Rhombus : public Figure {
private:
    std::vector<Point> vertices;

public:
    Rhombus();
    Rhombus(const std::vector<Point>& verts);
    Rhombus(const Rhombus& other);
    Rhombus& operator=(const Rhombus& other);

    virtual Point getGeometricCenter() const override;
    virtual double getArea() const override;

    virtual void print(std::ostream& os) const override;
    virtual void read(std::istream& is) override;

    virtual double toDouble() const override;

    virtual bool equals(const Figure& other) const override;
};

#endif // RHOMBUS_H
