#include "Array.h"

Array::Array() {}

Array::~Array() {
    for (auto fig : figures) {
        delete fig;
    }
}

void Array::addFigure(Figure* fig) {
    figures.push_back(fig);
}

void Array::removeFigure(int index) {
    if (index >= 0 && index < figures.size()) {
        delete figures[index];
        figures.erase(figures.begin() + index);
    }
}

void Array::printAll() const {
    for (int i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i << ":\n";
        std::cout << *figures[i];
        Point center = figures[i]->getGeometricCenter();
        std::cout << "Geometric Center: (" << center.x << ", " << center.y << ")\n";
        std::cout << "Area: " << figures[i]->toDouble() << "\n\n";
    }
}

double Array::totalArea() const {
    double total = 0.0;
    for (const auto& fig : figures) {
        total += fig->toDouble();
    }
    return total;
}

int Array::size() const {
    return figures.size();
}
