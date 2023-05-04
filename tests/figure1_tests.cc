#include <gtest/gtest.h>
#include <figure1/figure1.h>

using namespace std;
using namespace Figures;

TEST(FigurePerimeterTest, TestForCircle) {
    Point _central_point; Point _circle_point;
    _central_point = Point(0, 0);
    _circle_point = Point(0, 4);
    Figure Circle1 = Figure(Circle, _central_point, _circle_point);
    double P1 = Circle1.P();
    EXPECT_EQ(P1, 25.12);
}

TEST(FigureAreaTest, TestForCircle) {
    Point _central_point; Point _circle_point;
    _central_point = Point(0, 0);
    _circle_point = Point(0, 4);
    Figure Circle1 = Figure(Circle, _central_point, _circle_point); 
    double S1 = Circle1.S();
    EXPECT_EQ(S1, 50.24);
}

TEST(FigurePerimeterTest, TestForTriangle) {
    Point _left_bottom_point; Point _right_top_point; Point _right_bottom_point;
    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(0, 3);
    _right_bottom_point = Point(4, 0);
    Figure Triangle1 = Figure(Triangle, _left_bottom_point, _right_top_point, _right_bottom_point);
    double P2 = Triangle1.P();
    EXPECT_EQ(P2, 6);
}

TEST(FigureAreaTest, TestForTriangle) {
    Point _left_bottom_point; Point _right_top_point; Point _right_bottom_point;
    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(0, 3);
    _right_bottom_point = Point(4, 0);
    Figure Triangle1 = Figure(Triangle, _left_bottom_point, _right_top_point, _right_bottom_point);
    double S2 = Triangle1.S();
    EXPECT_EQ(S2, 6);
}

TEST(FigurePerimeterTest, TestForRectangle) {
    Point _left_bottom_point;
    Point _right_top_point;
    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(3, 9);
    Figure f = Figure(Rectangle, _left_bottom_point, _right_top_point);
    EXPECT_EQ(f.P(), 24);
}

TEST(FigureAreaTest, TestForRectangle) {
    Point _left_bottom_point; Point _right_top_point;
    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(3, 9);
    Figure Rectangle1 = Figure(Rectangle, _left_bottom_point, _right_top_point);
    double S3 = Rectangle1.S();
    EXPECT_EQ(S3, 27);
}

TEST(FigureMinRectTests, TestForMinCircle) {
    Point _left_bottom_point; Point _right_top_point;
    _left_bottom_point = Point(-4, 0);
    _right_top_point = Point(0, 4);
    Figure Circle2 = Figure(Circle, _left_bottom_point, _right_top_point);
    EXPECT_EQ(Circle2.get_min_rectangle().get_left_bottom_point().get_x(), -4);
    EXPECT_EQ(Circle2.get_min_rectangle().get_right_top_point().get_y(), 4);
}

TEST(FigureMinRectTests, TestForMinRectangle) {
    Point _left_bottom_point; Point _right_top_point;
    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(3, 9);
    Figure Rectangle2 = Figure(Rectangle, _left_bottom_point, _right_top_point);
    EXPECT_EQ(Rectangle2.get_min_rectangle().get_left_bottom_point().get_x(), 0);
    EXPECT_EQ(Rectangle2.get_min_rectangle().get_right_top_point().get_y(), 9);
}

TEST(FigureMinRectTests, TestForMinTriangle) {
    Point _left_bottom_point; Point _right_top_point; Point _right_bottom_point;
    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(3, 4);
    _right_bottom_point = Point(3, 0);
    Figure Triangle2 = Figure(Triangle, _left_bottom_point, _right_bottom_point, _right_top_point);
    EXPECT_EQ(Triangle2.get_min_rectangle().get_left_bottom_point().get_x(), 0);
    EXPECT_EQ(Triangle2.get_min_rectangle().get_right_top_point().get_y(), 4);
}

