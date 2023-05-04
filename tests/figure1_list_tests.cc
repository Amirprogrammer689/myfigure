#include <gtest/gtest.h>
#include <figure1/figure1.h>
#define CAPACITY 10

using namespace Figures;

Figurelist FillTestContainer() {
    const int SIZE = 4;
    Figure f1[CAPACITY];
    Point _left_bottom_point; Point _right_top_point; Point _right_bottom_point;

    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(0, 3);
    _right_bottom_point = Point(4, 0);
    f1[0] = Figure(Triangle, _left_bottom_point, _right_top_point, _right_bottom_point);

    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(3, 9);
    f1[1] = Figure(Rectangle, _left_bottom_point, _right_top_point);

    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(0, 4);
    f1[2] = Figure(Circle, _left_bottom_point, _right_top_point);

    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(0, 8);
    _right_bottom_point = Point(6, 0);
    f1[3] = Figure(Triangle, _left_bottom_point, _right_top_point, _right_bottom_point);

    Figurelist figures = Figurelist(f1, SIZE);
    return figures;
};

//проверка пустого контейнера
TEST(FigurelistTests, FigurelistDefaultConstructorTest) {
    Figurelist figures = Figurelist();
    EXPECT_EQ(figures.get_size(), 0);
}

TEST(FigurelistTests, FigurelistConstructorTest) {
    Figurelist figures = FillTestContainer();
    EXPECT_EQ(figures.get_size(), 4);
    EXPECT_EQ(figures[3].get_figure_type(), Triangle);
    EXPECT_EQ(figures[0].get_left_bottom_point().get_x(), 0);
}

TEST(FigurelistTests, FigurelistAddFirstItemTest) {
    Figurelist figures = Figurelist();
    Point _left_bottom_point; Point _right_top_point; Point _right_bottom_point;
    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(0, 8);
    _right_bottom_point = Point(6, 0);
    Figure f1 = Figure(Triangle, _left_bottom_point, _right_top_point, _right_bottom_point);
    figures.insert(0, f1);
    EXPECT_EQ(figures.get_size(), 1);
}

TEST(FigurelistTests, FigurelistAddItemTest) {   
    //заполненный контейнер из 4 фигур
    Figurelist figures = FillTestContainer();
    Point _left_bottom_point; Point _right_top_point; Point _right_bottom_point;
    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(0, 8);
    _right_bottom_point = Point(6, 0);
    Figure f1 = Figure(Triangle, _left_bottom_point, _right_top_point, _right_bottom_point);
    figures.insert(2, f1);
    EXPECT_EQ(figures.get_size(), 5);
    EXPECT_EQ(figures[2].get_figure_type(), Triangle);
    EXPECT_EQ(figures[3].get_figure_type(), Circle);
    EXPECT_ANY_THROW(figures.insert(-2, f1));
}

TEST(FigurelistTests, FigurelistDelItemTest) {
    const int SIZE = 4;
    Figurelist figures = Figurelist(); //пустой контейнер
    //заполнение контейнера фигурами по умолчанию
    for (int i = 0; i < SIZE; ++i) {
        Figure fig = Figure();
        figures.insert(i, fig);
    }
    EXPECT_EQ(figures.get_size(), 4);
    figures.remove(2);
    EXPECT_EQ(figures.get_size(), 3);
    EXPECT_EQ(figures[2].get_figure_type(), Rectangle);
}

TEST(FigurelistTests, FigurelistClearTest) {
    Figurelist figures = Figurelist();
    const int SIZE = 4;
    //заполнение контейнера фигурами по умолчанию
    for (int i = 0; i < SIZE; ++i) {
        Figure f1 = Figure();
        figures.insert(i, f1);
    }
    EXPECT_EQ(figures.get_size(), 4); //промежуточная проверка, что массив заполнен
    figures.clear();
    EXPECT_EQ(figures.get_size(), 0);
}

TEST(FigurelistTests, FigurelistGetItemTest) {
    Figurelist figures = Figurelist();
    const int SIZE = 4;
    for (int i = 0; i < SIZE; ++i) {
        Figure f1 = Figure();
        figures.insert(i, f1);
    }
    EXPECT_EQ(figures.get_size(), 4);
    EXPECT_EQ(figures[3].get_figure_type(), Rectangle);
}

TEST(FigurelistTests, FigurelistMinAreaTest) {
    Figurelist figures = FillTestContainer();
    EXPECT_EQ(figures.find_figure_min_square(), 0);
}

//проверка исключений
TEST(ExceptionTests, ExeptionIndexOutTest) {
    Figurelist figures = Figurelist();
    for (int i = 0; i < CAPACITY; ++i) {
        Figure f1 = Figure();
        figures.insert(i, f1);
    }
    EXPECT_THROW(figures[-1].S(), std::runtime_error);
    EXPECT_THROW(figures[10].S(), std::runtime_error);
}

TEST(ExceptionTests, ExeptionCapacityTest) {
    Figurelist figures = Figurelist();
    for (int i = 0; i < CAPACITY; ++i) {
        Figure f1 = Figure();
        figures.insert(i, f1);
    }
    Figure f2 = Figure();
    EXPECT_THROW(figures.insert(1, f2), std::runtime_error);
}

TEST(ExceptionTests, ExeptionEmptyTest) {
    Figurelist figures = Figurelist();
    EXPECT_THROW(figures.remove(1), std::runtime_error);
}