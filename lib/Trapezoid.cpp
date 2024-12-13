#include "Trapezoid.h"

Trapezoid::Trapezoid() : vertices(4) {}

Trapezoid::Trapezoid(const std::vector<Point>& verts) : vertices(verts) {}

Trapezoid::Trapezoid(const Trapezoid& other) : vertices(other.vertices) {}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Point Trapezoid::getGeometricCenter() const {
    double sumX = 0, sumY = 0;
    for (const auto& p : vertices) {
        sumX += p.x;
        sumY += p.y;
    }
    return Point{ sumX / vertices.size(), sumY / vertices.size() };
}

double Trapezoid::getArea() const {
    double area = 0.0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        const Point& p1 = vertices[i];
        const Point& p2 = vertices[(i + 1) % vertices.size()];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return (area > 0) ? area / 2.0 : -area / 2.0;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid vertices:\n";
    for (const auto& p : vertices) {
        os << "(" << p.x << ", " << p.y << ")\n";
    }
}

void Trapezoid::read(std::istream& is) {
    std::cout << "Enter 4 vertices of the trapezoid (x y):\n";
    for (auto& p : vertices) {
        is >> p.x >> p.y;
    }
}

double Trapezoid::toDouble() const {
    return getArea();
}

bool Trapezoid::equals(const Figure& other) const {
    const Trapezoid* o = dynamic_cast<const Trapezoid*>(&other);
    if (!o) return false;
    return vertices == o->vertices;
}
