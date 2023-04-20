#include <gtest/gtest.h>

#include <figure1/figure1.h>

using namespace std;

TEST(FigurePerimeterTest, TestForCircle){
    Point points[3] = { {0,0}, {0,3}, {6,0} };
    Figure Circle1(Circle, points);
    double P1 = Circle1.P();
    EXPECT_NEAR(P1, 18.84, PI);
}

TEST(FigureAreaTest, TestForCircle) {
    Point points[3] = { {0,0}, {0,3}, {6,0} };
    Figure Circle1(Circle, points);
    double S1 = Circle1.S();
    EXPECT_NEAR(S1, 9.42, PI);
}

TEST(FigurePerimeterTest, TestForTriangle) {
    Point points[3] = { {0,0}, {0,3}, {6,0} };
    Figure Triangle1(Triangle, points);
    double P1 = Triangle1.P();
    EXPECT_NEAR(P1, 7.8541, PI);
}

TEST(FigureAreaTest, TestForTriangle) {
    Point points[3] = { {0,0}, {0,3}, {6,0} };
    Figure Triangle1(Triangle, points);
    double S1 = Triangle1.S();
    EXPECT_NEAR(S1, 9, PI);
}

TEST(FigurePerimeterTest, TestForRectangle) {
    Point points[2] = { {0,0}, {3,9} };
    Figure Rectangle1(Rectangle, points);
    double P1 = Rectangle1.P();
    EXPECT_NEAR(P1, 24, PI);
}

TEST(FigureAreaTest, TestForRectangle) {
    Point points[2] = { {0,0}, {3,9} };
    Figure Rectangle1(Rectangle, points);
    double S1 = Rectangle1.S();
    EXPECT_NEAR(S1, 27, PI);
}
/*TEST(Figure1Tests, SumStubTest1) {
    // Arrange
    int lhs = 2;
    int rhs = 3;
    
    // Act
    int r = sum_stub(lhs, rhs);
    
    // Assert
    EXPECT_EQ(r, 5);
}

TEST(Figure1Tests, SumStubTest2) {
    // Arrange
    int lhs = -1;
    int rhs = 3;
    
    // Act
    int r = sum_stub(lhs, rhs);
    
    // Assert
    EXPECT_EQ(r, 2);
}
*/