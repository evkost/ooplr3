#include "Pentagon.h"

Pentagon::Pentagon() : vertices(5) {}

Pentagon::Pentagon(const std::vector<Point>& verts) : vertices(verts) {}

Pentagon::Pentagon(const Pentagon& other) : vertices(other.vertices) {}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Point Pentagon::getGeometricCenter() const {
    double sumX = 0, sumY = 0;
    for (const auto& p : vertices) {
        sumX += p.x;
        sumY += p.y;
    }
    return Point{ sumX / vertices.size(), sumY / vertices.size() };
}

double Pentagon::getArea() const {
    double area = 0.0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        const Point& p1 = vertices[i];
        const Point& p2 = vertices[(i + 1) % vertices.size()];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return (area > 0) ? area / 2.0 : -area / 2.0;
}

void Pentagon::print(std::ostream& os) const {
    os << "Pentagon vertices:\n";
    for (const auto& p : vertices) {
        os << "(" << p.x << ", " << p.y << ")\n";
    }
}

void Pentagon::read(std::istream& is) {
    std::cout << "Enter 5 vertices of the pentagon (x y):\n";
    for (auto& p : vertices) {
        is >> p.x >> p.y;
    }
}

double Pentagon::toDouble() const {
    return getArea();
}

bool Pentagon::equals(const Figure& other) const {
    const Pentagon* o = dynamic_cast<const Pentagon*>(&other);
    if (!o) return false;
    return vertices == o->vertices;
}
