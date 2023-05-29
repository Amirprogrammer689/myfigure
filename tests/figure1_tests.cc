#include <gtest/gtest.h>
#include <figure1/figure1.h>

using namespace std;
using namespace Figures;

TEST(FigurePerimeterTest, TestForCircle) {
    auto P1 = Circle(Point(0, 0), Point(0, 4));
    EXPECT_EQ(P1.get_perimetr(), 25.12);
}

TEST(FigureAreaTest, TestForCircle) {
    auto S1 = Circle(Point(0, 0), Point(0, 4));
    EXPECT_EQ(S1.get_area(), 50.24);
}

TEST(FigurePerimeterTest, TestForTriangle) {
    auto P2 = Triangle(Point(0, 0), Point(0, 3), Point(4, 0));
    EXPECT_EQ(P2.get_perimetr(), 6);
}

TEST(FigureAreaTest, TestForTriangle) {
    auto S2 = Triangle(Point(0, 0), Point(0, 3), Point(4, 0));
    EXPECT_EQ(S2.get_area(), 6);
}

TEST(FigurePerimeterTest, TestForRectangle) {
    auto P3 = Rectangle(Point(0, 0), Point(3,9));
    EXPECT_EQ(P3.get_perimetr(), 24);
}

TEST(FigureAreaTest, TestForRectangle) {
    auto S3 = Rectangle(Point(0, 0), Point(3, 9));
    EXPECT_EQ(S3.get_area(), 27);
}

TEST(FigureMinRectTests, TestForMinCircle) {
    auto Rect1 = Circle(Point(0, 9), Point(3, 9));
    EXPECT_EQ(Rect1.get_min_rectangle()->get_left_bottom_point().get_x(), 0);
    EXPECT_EQ(Rect1.get_min_rectangle()->get_right_top_point().get_y(), 9);
}

TEST(FigureMinRectTests, TestForMinRectangle) {
    auto Rect2 = Rectangle(Point(-4, 0), Point(0, 4));
    EXPECT_EQ(Rect2.get_min_rectangle()->get_left_bottom_point().get_x(), -4);
    EXPECT_EQ(Rect2.get_min_rectangle()->get_right_top_point().get_y(), 4);
}

TEST(FigureMinRectTests, TestForMinTriangle) {
    auto Rect3 = Triangle(Point(0, 0), Point(3, 4), Point(3, 0));
    EXPECT_EQ(Rect3.get_min_rectangle()->get_left_bottom_point().get_x(), 0);
    EXPECT_EQ(Rect3.get_min_rectangle()->get_right_bottom_point().get_y(), 4);
}

