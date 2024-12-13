#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Array.h"
#include <iostream>

int main() {
    Array figures;
    int choice;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Add Trapezoid\n";
        std::cout << "2. Add Rhombus\n";
        std::cout << "3. Add Pentagon\n";
        std::cout << "4. Print All Figures\n";
        std::cout << "5. Calculate Total Area\n";
        std::cout << "6. Remove Figure by Index\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 7) {
            break;
        }

        switch (choice) {
            case 1: {
                auto* t = new Trapezoid();
                std::cin >> *t;
                figures.addFigure(t);
                break;
            }
            case 2: {
                auto* r = new Rhombus();
                std::cin >> *r;
                figures.addFigure(r);
                break;
            }
            case 3: {
                auto* p = new Pentagon();
                std::cin >> *p;
                figures.addFigure(p);
                break;
            }
            case 4: {
                figures.printAll();
                break;
            }
            case 5: {
                std::cout << "Total Area: " << figures.totalArea() << "\n";
                break;
            }
            case 6: {
                int index;
                std::cout << "Enter the index of the figure to remove: ";
                std::cin >> index;
                figures.removeFigure(index);
                std::cout << "Figure removed.\n";
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
