#include <figure1/figure1.h>
#include <cmath>
#include <stdexcept>
#include <cassert>

using namespace std;
using namespace Figures;

double Point::get_x() const {
	return _x;
}
double Point::get_y() const {
	return _y;
}

void Point::print()const {
	cout << "x = " << _x << "y = " << _y << endl;
}

//геттеры точек
Point Figure::get_left_bottom_point() const {
	return _left_bottom_point;
};

Point Figure::get_right_bottom_point() const {
	return _right_bottom_point;
};

Point Figure::get_right_top_point() const {
	return _right_top_point;
};

//периметр
double Circle::get_perimetr() const {
	double a = (_left_bottom_point.get_x() - _right_top_point.get_x());
	double b = (_left_bottom_point.get_y() - _right_top_point.get_y());
	return 2 * PI * sqrt((a * a) + (b * b));
}

double Triangle::get_perimetr() const {
	double a = sqrt(((_right_top_point.get_x()) * (_right_top_point.get_x())) - 2 * _right_top_point.get_x() * _left_bottom_point.get_x() + ((_left_bottom_point.get_x()) * (_left_bottom_point.get_x())) + ((_right_top_point.get_y()) * (_right_top_point.get_y())) - 2 * _left_bottom_point.get_y() * _right_top_point.get_y() + (_left_bottom_point.get_y() * _left_bottom_point.get_y()));
	double b = sqrt(((_right_bottom_point.get_x()) * (_right_bottom_point.get_x())) - 2 * _right_bottom_point.get_x() * _right_top_point.get_x() + ((_right_top_point.get_x()) * (_right_top_point.get_x())) + ((_right_bottom_point.get_y()) * (_right_bottom_point.get_y())) - 2 * _right_top_point.get_y() * _right_bottom_point.get_y() + (_right_top_point.get_y() * _right_top_point.get_y()));
	double c = sqrt(((_left_bottom_point.get_x()) * (_left_bottom_point.get_x())) - 2 * _left_bottom_point.get_x() * _right_bottom_point.get_x() + ((_right_bottom_point.get_x()) * (_right_bottom_point.get_x())) + ((_left_bottom_point.get_y()) * (_left_bottom_point.get_y())) - 2 * _right_bottom_point.get_y() * _left_bottom_point.get_y() + (_right_bottom_point.get_y() * _right_bottom_point.get_y()));
	return ((a + b + c) / 2);
}

double Rectangle::get_perimetr() const {
	double a = _right_top_point.get_x() - _left_bottom_point.get_x();
	double b = _right_top_point.get_y() - _left_bottom_point.get_y();
	return 2 * (a + b);
}

//площадь
double Circle::get_area() const {
	double a = (_left_bottom_point.get_x() - _right_top_point.get_x());
	double b = (_left_bottom_point.get_y() - _right_top_point.get_y());
	return PI * sqrt((a * a) + (b * b)) * sqrt((a * a) + (b * b));
}

double Triangle::get_area() const {
	double a = sqrt(((_right_top_point.get_x()) * (_right_top_point.get_x())) - 2 * _right_top_point.get_x() * _left_bottom_point.get_x() + ((_left_bottom_point.get_x()) * (_left_bottom_point.get_x())) + ((_right_top_point.get_y()) * (_right_top_point.get_y())) - 2 * _left_bottom_point.get_y() * _right_top_point.get_y() + (_left_bottom_point.get_y() * _left_bottom_point.get_y()));
	double b = sqrt(((_right_bottom_point.get_x()) * (_right_bottom_point.get_x())) - 2 * _right_bottom_point.get_x() * _right_top_point.get_x() + ((_right_top_point.get_x()) * (_right_top_point.get_x())) + ((_right_bottom_point.get_y()) * (_right_bottom_point.get_y())) - 2 * _right_top_point.get_y() * _right_bottom_point.get_y() + (_right_top_point.get_y() * _right_top_point.get_y()));
	double c = sqrt(((_left_bottom_point.get_x()) * (_left_bottom_point.get_x())) - 2 * _left_bottom_point.get_x() * _right_bottom_point.get_x() + ((_right_bottom_point.get_x()) * (_right_bottom_point.get_x())) + ((_left_bottom_point.get_y()) * (_left_bottom_point.get_y())) - 2 * _right_bottom_point.get_y() * _left_bottom_point.get_y() + (_right_bottom_point.get_y() * _right_bottom_point.get_y()));
	double p = (a + b + c) / 2;
	return (sqrt(p * (p - a) * (p - b) * (p - c)));
}

double Rectangle::get_area() const {
	return  abs(_right_top_point.get_x() - _left_bottom_point.get_x()) * (_right_top_point.get_y() - _left_bottom_point.get_y());
}

//минимальный обрамл€ющий треугольник
FigurePtr Circle::get_min_rectangle() const {
	return this->clone();
//	return std::make_shared<Rectangle>();
}

FigurePtr Triangle::get_min_rectangle() const {
	return this->clone();
	//return std::make_shared<Rectangle>(_left_bottom_point, Point(_right_bottom_point.get_x(), _right_top_point.get_y()));
}

FigurePtr Rectangle::get_min_rectangle()const {
	return this->clone();
}

void Circle::print()const {
	cout << "Circle" << endl;
	cout << "..." << endl;
	_left_bottom_point.print();
	cout << "..." << endl;
	_right_top_point.print();
}

void Triangle::print()const {
	cout << "Triangle" << endl;
	cout << "..." << endl;
	_left_bottom_point.print();
	cout << "..." << endl;
	_right_bottom_point.print();
	cout << "..." << endl;
	_right_top_point.print();
}

void Rectangle::print()const {
	cout << "Rectangle" << endl;
	cout << "..." << endl;
	_left_bottom_point.print();
	cout << "..." << endl;
	_right_top_point.print();
}

FigurePtr Circle::clone()const {
	return make_shared<Circle>(_left_bottom_point, _right_top_point);
}

FigurePtr Rectangle::clone()const {
	return make_shared<Rectangle>(_left_bottom_point, _right_top_point);
}

FigurePtr Triangle::clone()const {
	return make_shared<Triangle>(_left_bottom_point, _right_bottom_point, _right_top_point);
}