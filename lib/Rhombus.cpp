#include "Rhombus.h"

Rhombus::Rhombus() : vertices(4) {}

Rhombus::Rhombus(const std::vector<Point>& verts) : vertices(verts) {}

Rhombus::Rhombus(const Rhombus& other) : vertices(other.vertices) {}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Point Rhombus::getGeometricCenter() const {
    double sumX = 0, sumY = 0;
    for (const auto& p : vertices) {
        sumX += p.x;
        sumY += p.y;
    }
    return Point{ sumX / vertices.size(), sumY / vertices.size() };
}

double Rhombus::getArea() const {
    double area = 0.0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        const Point& p1 = vertices[i];
        const Point& p2 = vertices[(i + 1) % vertices.size()];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return (area > 0) ? area / 2.0 : -area / 2.0;
}

void Rhombus::print(std::ostream& os) const {
    os << "Rhombus vertices:\n";
    for (const auto& p : vertices) {
        os << "(" << p.x << ", " << p.y << ")\n";
    }
}

void Rhombus::read(std::istream& is) {
    std::cout << "Enter 4 vertices of the rhombus (x y):\n";
    for (auto& p : vertices) {
        is >> p.x >> p.y;
    }
}

double Rhombus::toDouble() const {
    return getArea();
}

bool Rhombus::equals(const Figure& other) const {
    const Rhombus* o = dynamic_cast<const Rhombus*>(&other);
    if (!o) return false;
    return vertices == o->vertices;
}
