#pragma once
#include <string>

#define PI 3.14
enum typeFigure {Circle, Triangle, Rectangle};

class Point {
	double x;
	double y;
public: 
	Point() : x(), y() {}
	Point(double x, double y) : x(x), y(y) {}
	double get_x() const;
	double get_y() const;
};

class Figure {
	static const int n = 3;
	typeFigure _type;
	Point _points[n];
public:
	Figure(typeFigure type, Point* points);
	double P() const;
	double S() const;
	std::string get_type() const;
};

class FigureList {
	static const int CAPACITY = 10;
	Figure List[CAPACITY];
	int size = 0;
public:
};
/*int sum_stub(int lhs, int rhs); */
