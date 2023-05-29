#include <gtest/gtest.h>
#include <figure1/figure1.h>

using namespace Figures;

FigureList FillTestContainer() {
    FigureList figures;

    auto figure0 = Triangle(Point(0, 0), Point(0, 3), Point(4, 0));
    auto figure1 = Rectangle(Point(0, 0), Point(3, 9));
    auto figure2 = Circle(Point(0, 0), Point(0, 4));
    auto figure3 = Triangle(Point(0, 0), Point(0, 8), Point(6, 0));
   
    figures.insert(figure0.clone(), 0);
    figures.insert(figure1.clone(), 1);
    figures.insert(figure2.clone(), 2);
    figures.insert(figure3.clone(), 3);

    return figures;
};

//проверка пустого контейнера
TEST(FigurelistTests, FigurelistDefaultConstructorTest) {
    auto figures = FigureList();
    EXPECT_EQ(figures.get_size(), 0);
}

TEST(FigurelistTests, FigurelistAddITest) {   
    //заполненный контейнер из 4 фигур
    FigureList figures = FillTestContainer();

    auto fig1 = Triangle(Point(0, 0), Point(0, 8), Point(6, 0));
 
    figures.add(fig1.clone());
    EXPECT_EQ(figures.get_size(), 5);
}

TEST(FigurelistTests, FigurelistDelItemTest) {
    const int SIZE = 4;
    FigureList figures = FillTestContainer();
    //пустой контейнер
    //заполнение контейнера фигурами по умолчанию
    for (int i = 0; i < SIZE; ++i) {
        FigurePtr fig = FigurePtr();
        figures.insert(fig, i);
    }
    EXPECT_EQ(figures.get_size(), 8);
    figures.remove(2);
    EXPECT_EQ(figures.get_size(), 7);
}

TEST(FigurelistTests, FigurelistClearTest) {
    auto figures = FillTestContainer();
    const int SIZE = 4;
    //заполнение контейнера фигурами по умолчанию
    for (int i = 0; i < SIZE; ++i) {
        FigurePtr f1 = FigurePtr();
        figures.insert(f1, i);
    }
    EXPECT_EQ(figures.get_size(), 8); //промежуточная проверка, что массив заполнен
    figures.clear();
    EXPECT_EQ(figures.get_size(), 0);
}

TEST(FigurelistTests, FigurelistGetItemTest) {
    auto figures = FillTestContainer();
    const int SIZE = 4;
    for (int i = 0; i < SIZE; ++i) {
        FigurePtr f1 = FigurePtr();
        figures.insert(f1, i);
    }
    EXPECT_EQ(figures.get_size(), 8);
}

TEST(FigurelistTests, FigurelistMinAreaTest) {
    auto figures = FillTestContainer();
    EXPECT_EQ(figures.find_figure_min_area(), 0);
}

