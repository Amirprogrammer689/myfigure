#include <gtest/gtest.h>
#include <figure1/figure1.h>

using namespace Figures;

Figurelist FillTestContainer(){
    Point _left_bottom_point; Point _right_top_point; Point _right_bottom_point;

    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(0, 3);
    _right_bottom_point = Point(4, 0);
    Figure figure0 = Figure(Triangle, _left_bottom_point, _right_top_point, _right_bottom_point);

    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(3, 9);
    Figure figure1 = Figure(Rectangle, _left_bottom_point, _right_top_point);

    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(0, 4);
    Figure figure2 = Figure(Circle, _left_bottom_point, _right_top_point);

    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(0, 8);
    _right_bottom_point = Point(6, 0);
    Figure figure3 = Figure(Triangle, _left_bottom_point, _right_top_point, _right_bottom_point);

    Figurelist figures;
    figures.insert(figure0, 0);
    figures.insert(figure1, 1);
    figures.insert(figure2, 2);
    figures.insert(figure3, 3);

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

TEST(FigurelistTests, FigurelistAddItemTest) {   
    //заполненный контейнер из 4 фигур
    Figurelist figures = FillTestContainer();
    Point _left_bottom_point; Point _right_top_point; Point _right_bottom_point;
    _left_bottom_point = Point(0, 0);
    _right_top_point = Point(0, 8);
    _right_bottom_point = Point(6, 0);
    Figure fig1 = Figure(Triangle, _left_bottom_point, _right_top_point, _right_bottom_point);

    figures.insert(fig1, 2);
    EXPECT_EQ(figures.get_size(), 5);
    EXPECT_EQ(figures[2].get_figure_type(), Triangle);
    EXPECT_EQ(figures[4].get_figure_type(), Triangle);
    EXPECT_ANY_THROW(figures.insert(figures[3], -2));
}

TEST(FigurelistTests, FigurelistDelItemTest) {
    const int SIZE = 4;
    Figurelist figures = FillTestContainer();
    //пустой контейнер
    //заполнение контейнера фигурами по умолчанию
    for (int i = 0; i < SIZE; ++i) {
        Figure fig = Figure();
        figures.insert(fig, i);
    }
    EXPECT_EQ(figures.get_size(), 8);
    figures.remove(2);
    EXPECT_EQ(figures.get_size(), 7);
    EXPECT_EQ(figures[2].get_figure_type(), Rectangle);
}

TEST(FigurelistTests, FigurelistClearTest) {
    Figurelist figures = FillTestContainer();
    const int SIZE = 4;
    //заполнение контейнера фигурами по умолчанию
    for (int i = 0; i < SIZE; ++i) {
        Figure f1 = Figure();
        figures.insert(f1, i);
    }
    EXPECT_EQ(figures.get_size(), 8); //промежуточная проверка, что массив заполнен
    figures.clear();
    EXPECT_EQ(figures.get_size(), 0);
}

TEST(FigurelistTests, FigurelistGetItemTest) {
    Figurelist figures = FillTestContainer();
    const int SIZE = 4;
    for (int i = 0; i < SIZE; ++i) {
        Figure f1 = Figure();
        figures.insert(f1, i);
    }
    EXPECT_EQ(figures.get_size(), 8);
    EXPECT_EQ(figures[3].get_figure_type(), Rectangle);
}

TEST(FigurelistTests, FigurelistMinAreaTest) {
    Figurelist figures = FillTestContainer();
    EXPECT_EQ(figures.find_figure_min_area(), 0);
}

