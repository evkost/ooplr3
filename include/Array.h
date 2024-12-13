#ifndef ARRAY_H
#define ARRAY_H

#include "Figure.h"
#include <vector>

class Array {
private:
    std::vector<Figure*> figures;

public:
    Array();
    ~Array();

    void addFigure(Figure* fig);
    void removeFigure(int index);
    void printAll() const;
    double totalArea() const;
    int size() const;
};

#endif // ARRAY_H
