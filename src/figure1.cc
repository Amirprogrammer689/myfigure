#include <figure1/figure1.h>
double Point::get_x() const{
    return x;
}
double Point::get_y() const{
    return y;
}
Figure::Figure(typeFigure type, Point* points){
	this->type = type;
	for (int i = 0; i < n; ++i) {
		this->points[i] = points[i];
	}
}
double Figure::P() const {
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
double Figure::S() const {
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
std::string Figure::get_type() const {
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
int sum_stub(int lhs, int rhs) {
    return lhs + rhs;
}
