#include <figure1/figure1.h>
#include <cmath>
#include <stdexcept>

using namespace std;

double Point::get_x() const{
    return x;
}
double Point::get_y() const{
    return y;
}
Figure::Figure(typeFigure type, Point* points){
	_type = type;
	for (int i = 0; i < n; ++i) {
		_points[i] = points[i];
	}
}
double Figure::P() const {
	switch (_type) {
	case Circle:
		return 2 * PI * sqrt((_points[0].get_x() - _points[1].get_x()) * (_points[0].get_x() - _points[1].get_x()) + (_points[0].get_y() - _points[1].get_y()) * (_points[0].get_y() - _points[1].get_y()));
		//return 2 * PI * sqrt(pow(_points[0].get_x() - _points[1].get_x(), 2) + pow(_points[0].get_y() - _points[1].get_y(), 2));
	case Triangle: {
		double a = sqrt((_points[1].get_x() - _points[0].get_x()) * (_points[1].get_x() - _points[0].get_x()) + (_points[1].get_y() - _points[0].get_y()) * (_points[1].get_y() - _points[0].get_y()));
		//double a = sqrt(pow(_points[1].get_x() - _points[0].get_x(), 2) + pow(_points[1].get_y() - _points[0].get_y(), 2));
		double b = sqrt((_points[2].get_x() - _points[1].get_x()) * (_points[2].get_x() - _points[0].get_x()) + (_points[1].get_y() - _points[0].get_y()) * (_points[1].get_y() - _points[0].get_y()));
		//double b = sqrt(pow(_points[2].get_x() - _points[1].get_x(), 2) + pow(_points[2].get_y() - _points[1].get_y(), 2));
		double c = sqrt((_points[0].get_x() - _points[2].get_x()) * (_points[0].get_x() - _points[2].get_x()) + (_points[0].get_y() - _points[2].get_y()) * (_points[0].get_y() - _points[2].get_y()));
		//double c = sqrt(pow(_points[0].get_x() - _points[2].get_x(), 2) + pow(_points[0].get_y() - _points[2].get_y(), 2));
		return ((a + b + c) / 2);
	}
	case Rectangle:
		return (abs(_points[1].get_x() - _points[0].get_x()) + (_points[1].get_y() - _points[0].get_y())) * 2;
	default:
		throw std::runtime_error("Type error");
	}
}
double Figure::S() const {
	switch (_type) {
	case Circle:
		return PI * sqrt((_points[0].get_x() - _points[1].get_x()) * (_points[0].get_x() - _points[1].get_x()) + (_points[0].get_y() - _points[1].get_y()) * (_points[0].get_y() - _points[1].get_y())) * sqrt((_points[0].get_x() - _points[1].get_x()) * (_points[0].get_x() - _points[1].get_x()) + (_points[0].get_y() - _points[1].get_y()) * (_points[0].get_y() - _points[1].get_y()));
		//return PI * pow(sqrt(pow(_points[0].get_x() - _points[1].get_x(), 2) + pow(_points[0].get_y() - _points[1].get_y(), 2)), 2);
	case Triangle: {
		double a = sqrt(((_points[1].get_x() - _points[0].get_x()) * (_points[1].get_x() - _points[0].get_x())) + (_points[1].get_y() - _points[0].get_y())* (_points[1].get_y() - _points[0].get_y()));
		//double a = sqrt(pow(_points[1].get_x() - _points[0].get_x(), 2) + pow(_points[1].get_y() - _points[0].get_y(), 2));
		double b = sqrt((_points[2].get_x() - _points[1].get_x()) * (_points[2].get_x() - _points[0].get_x()) + (_points[1].get_y() - _points[0].get_y()) * (_points[1].get_y() - _points[0].get_y()));
		//double b = sqrt(pow(_points[2].get_x() - _points[1].get_x(), 2) + pow(_points[2].get_y() - _points[1].get_y(), 2));
		double c = sqrt((_points[0].get_x() - _points[2].get_x()) * (_points[0].get_x() - _points[2].get_x()) + (_points[0].get_y() - _points[2].get_y()) * (_points[0].get_y() - _points[2].get_y()));
		//double c = sqrt(pow(_points[0].get_x() - _points[2].get_x(), 2) + pow(_points[0].get_y() - _points[2].get_y(), 2));
		double p = (a + b + c) / 2;
		return (sqrt(p * (p - a) * (p - b) * (p - c)));
	}
	case Rectangle:
		return  abs(_points[1].get_x() - _points[0].get_x()) * (_points[1].get_y() - _points[0].get_y());
	default:
		throw std::runtime_error("Type error");
	}
}
std::string Figure::get_type() const {
	switch (_type)
	{
	case Circle:
		return "Circle";
	case Triangle:
		return "Triangle";
	case Rectangle:
		return "Rectangle";
	default:
		throw std::runtime_error("Type error");
	}
}
/*#pragma once
#include <string>
#include <cmath>
#include <stdexcept>
#define PI 3.14
enum typeFigure {Circle,  Triangle, Rectangle};

class Point {
	double x;
	double y;
public: 
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	double get_x() const;
	double get_y() const;
};

class Figure {
	static const int n = 3;
	typeFigure type;
	Point points[n];
public:
	Figure(typeFigure type, Point* points);
	double P() {
		switch (type) {
		case Circle:
			return 2 * PI * sqrt(pow(points[1].get_x() - points[0].get_x(), 2) + pow(points[1].get_y() - points[0].get_y(), 2));
			break;
		case Triangle:
			return (((sqrt(pow(points[1].get_x() - points[0].get_x(), 2) + pow(points[1].get_y() - points[0].get_y(), 2))) + (sqrt(pow(points[2].get_x() - points[1].get_x(), 2) + pow(points[2].get_y() - points[1].get_y(), 2))) + (sqrt(pow(points[0].get_x() - points[2].get_x(), 2) + pow(points[0].get_y() - points[2].get_y(), 2)))) / 2);
			break;
		case Rectangle:
			return (abs(points[1].get_x() - points[0].get_x()) + (points[1].get_y() - points[0].get_y())) * 2;
			break;
		default:
			break;
		}
	}
	double S() {
		switch (type) {
		case Circle:
			return PI * pow(sqrt(pow(points[1].get_x() - points[0].get_x(), 2) + (points[1].get_y() - points[0].get_y(), 2)), 2);
			break;
		case Triangle:
			return sqrt((((sqrt(pow(points[1].get_x() - points[0].get_x(), 2) + pow(points[1].get_y() - points[0].get_y(), 2))) + (sqrt(pow(points[2].get_x() - points[1].get_x(), 2) + pow(points[2].get_y() - points[1].get_y(), 2))) + (sqrt(pow(points[0].get_x() - points[2].get_x(), 2) + pow(points[0].get_y() - points[2].get_y(), 2)))) / 2) * ((((sqrt(pow(points[1].get_x() - points[0].get_x(), 2) + pow(points[1].get_y() - points[0].get_y(), 2))) + (sqrt(pow(points[2].get_x() - points[1].get_x(), 2) + pow(points[2].get_y() - points[1].get_y(), 2))) + (sqrt(pow(points[0].get_x() - points[2].get_x(), 2) + pow(points[0].get_y() - points[2].get_y(), 2)))) / 2) - (sqrt(pow(points[1].get_x() - points[0].get_x(), 2) + pow(points[1].get_y() - points[0].get_y(), 2)))) * ((((sqrt(pow(points[1].get_x() - points[0].get_x(), 2) + pow(points[1].get_y() - points[0].get_y(), 2))) + (sqrt(pow(points[2].get_x() - points[1].get_x(), 2) + pow(points[2].get_y() - points[1].get_y(), 2))) + (sqrt(pow(points[0].get_x() - points[2].get_x(), 2) + pow(points[0].get_y() - points[2].get_y(), 2)))) / 2) - (sqrt(pow(points[2].get_x() - points[1].get_x(), 2) + pow(points[2].get_y() - points[1].get_y(), 2)))) * (((((sqrt(pow(points[1].get_x() - points[0].get_x(), 2) + pow(points[1].get_y() - points[0].get_y(), 2))) + (sqrt(pow(points[2].get_x() - points[1].get_x(), 2) + pow(points[2].get_y() - points[1].get_y(), 2))) + (sqrt(pow(points[0].get_x() - points[2].get_x(), 2) + pow(points[0].get_y() - points[2].get_y(), 2)))) / 2) - (sqrt(pow(points[0].get_x() - points[2].get_x(), 2) + pow(points[0].get_y() - points[2].get_y(), 2))))));
			break;
		case Rectangle:
			return  abs(points[1].get_x() - points[0].get_x()) * (points[1].get_y() - points[0].get_y());
			break;
		default:
			break;
		}
	}
	std::string get_type() {
		switch (type)
		{
		case Circle:
			return "Circle";
		case Triangle:
			return "Triangle";
		case Rectangle:
			return "Rectangle";
		default:
			throw std::runtime_error("Type error");
		}
	}
};*/

/*int sum_stub(int lhs, int rhs) {
    return lhs + rhs;
}*/
