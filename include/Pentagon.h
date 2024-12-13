#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <vector>

class Pentagon : public Figure {
private:
    std::vector<Point> vertices;

public:
    Pentagon();
    Pentagon(const std::vector<Point>& verts);
    Pentagon(const Pentagon& other);
    Pentagon& operator=(const Pentagon& other);

    virtual Point getGeometricCenter() const override;
    virtual double getArea() const override;

    virtual void print(std::ostream& os) const override;
    virtual void read(std::istream& is) override;

    virtual double toDouble() const override;

    virtual bool equals(const Figure& other) const override;
};

#endif // PENTAGON_H
