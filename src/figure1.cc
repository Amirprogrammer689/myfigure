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
/*#include <string>
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
	double get_x();
	double get_y();
};

class Figure {
	static const int n = 3;
	typeFigure type;
	Point points[3];
public:
	Figure(typeFigure type, Point* points) {
		this->type = type;
		for (int i = 0; i < n; ++i) {
			this->points[i] = points[i];
		}
	}
	double P() {
		switch (type) {
		case Circle:
			return 2 * PI * sqrt(pow(points[1].get_x() - points[0].get_x(), 2) + pow(points[1].get_y() - points[0].get_y(), 2));
			break;
		case Triangle:
			return (sqrt)
			break;
		case Rectangle:
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
			break;
		case Rectangle:
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
};

class Container {
	static const int CAPACITY = 10;
	Figure* list[CAPACITY];
	int size = 0;
public:
};*/
int sum_stub(int lhs, int rhs) {
    return lhs + rhs;
}
