#include <gtest/gtest.h>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Array.h"

TEST(PointTest, EqualityOperator) {
    Point p1{1.0, 2.0};
    Point p2{1.0, 2.0};
    Point p3{2.0, 3.0};

    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(TrapezoidTest, AreaCalculation) {
    std::vector<Point> verts = { {0,0}, {4,0}, {3,3}, {1,3} };
    Trapezoid t(verts);

    double expected_area = 9.0;
    EXPECT_DOUBLE_EQ(t.getArea(), expected_area);
}

TEST(RhombusTest, GeometricCenterCalculation) {
    std::vector<Point> verts = { {0,0}, {2,1}, {0,2}, {-2,1} };
    Rhombus r(verts);

    Point expected_center = {0.0, 1.0};
    Point calculated_center = r.getGeometricCenter();

    EXPECT_DOUBLE_EQ(calculated_center.x, expected_center.x);
    EXPECT_DOUBLE_EQ(calculated_center.y, expected_center.y);
}

TEST(PentagonTest, AreaCalculation) {
    std::vector<Point> verts = {
        {0, 0},
        {2, 0},
        {2, 2},
        {1, 3},
        {0, 2}
    };
    Pentagon p(verts);

    double expected_area = 5.0;
    double calculated_area = p.getArea();

    EXPECT_NEAR(calculated_area, expected_area, 0.01);
}

TEST(PentagonTest, GeometricCenterCalculation) {
    std::vector<Point> verts = {
        {0, 0},
        {2, 0},
        {2, 2},
        {1, 3},
        {0, 2}
    };
    Pentagon p(verts);

    Point expected_center = {1.0, 1.4};
    Point calculated_center = p.getGeometricCenter();

    EXPECT_NEAR(calculated_center.x, expected_center.x, 0.0001);
    EXPECT_NEAR(calculated_center.y, expected_center.y, 0.0001);
}

TEST(ArrayTest, AddAndRemoveFigures) {
    Array arr;
    EXPECT_EQ(arr.size(), 0);

    auto t = new Trapezoid({ {0,0}, {4,0}, {3,3}, {1,3} });
    arr.addFigure(t);
    EXPECT_EQ(arr.size(), 1);

    auto r = new Rhombus({ {0,0}, {2,1}, {0,2}, {-2,1} });
    arr.addFigure(r);
    EXPECT_EQ(arr.size(), 2);

    arr.removeFigure(0);
    EXPECT_EQ(arr.size(), 1);

    arr.removeFigure(0);
    EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array arr;

    Trapezoid* t = new Trapezoid({ {0,0}, {4,0}, {3,3}, {1,3} }); // Area = 9
    Rhombus* r = new Rhombus({ {0,0}, {2,1}, {0,2}, {-2,1} });    // Area = 4

    arr.addFigure(t);
    arr.addFigure(r);

    double expected_total_area = 13.0;
    EXPECT_DOUBLE_EQ(arr.totalArea(), expected_total_area);
}