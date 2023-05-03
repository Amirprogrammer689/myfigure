#include <figure1/figure1.h>
#include <cmath>
#include <stdexcept>

using namespace std;
using namespace Figures;

double Point::get_x() const {
	return x;
}
double Point::get_y() const {
	return y;
}

Figure::Figure() {
	_type = Rectangle;
	_right_bottom_point = Point(1, 1);
	_left_bottom_point = Point(-1, -1);
}

Figure::Figure(typeFigure type, Point left_bottom_point, Point right_bottom_point, Point right_top_point) {
	if (type != Triangle)
		throw std::runtime_error("Wrong figure type. It is required two points for a rectangle or an circle");

	_type = type;
	_left_bottom_point = left_bottom_point;
	_right_bottom_point = right_bottom_point;
	_right_top_point = right_top_point;
}

Figure::Figure(typeFigure type, Point left_bottom_point, Point right_top_point) {
	if (type == Triangle)
		throw std::runtime_error("Wrong figure type. It is required four points for a triangle or circle.");

	_type = type;
	_left_bottom_point = left_bottom_point;
	_right_top_point = right_top_point;
}

typeFigure Figure::get_figure_type() const {
	return _type;
}

Point Figure::get_left_bottom_point() const {
	return _left_bottom_point;
};

Point Figure::get_right_top_point() const {
	return _right_top_point;
};

double Figure::P() const {
	switch (_type) {
	case Circle: {
		double a = (_left_bottom_point.get_x() - _right_top_point.get_x());
		double b = (_left_bottom_point.get_y() - _right_top_point.get_y());
		return 2 * PI * sqrt((a*a) + (b*b));
		//return 2 * PI * sqrt(pow(_left_bottom_point.get_x() - _right_top_point.get_x(), 2) + pow(_left_bottom_point.get_y() - _right_top_point.get_y(), 2));
	}
		case Triangle: {
		double a = sqrt(((_right_top_point.get_x())*(_right_top_point.get_x())) - 2 * _right_top_point.get_x() * _left_bottom_point.get_x() + ((_left_bottom_point.get_x()) * (_left_bottom_point.get_x())) + ((_right_top_point.get_y()) * (_right_top_point.get_y())) - 2 * _left_bottom_point.get_y() * _right_top_point.get_y() + (_left_bottom_point.get_y() * _left_bottom_point.get_y()));
		//double a = sqrt(pow(_right_top_point.get_x() - _left_bottom_point.get_x(), 2) + pow(_right_top_point.get_y() - _left_bottom_point.get_y(), 2));
		double b = sqrt(((_right_bottom_point.get_x()) * (_right_bottom_point.get_x())) - 2 * _right_bottom_point.get_x() * _right_top_point.get_x() + ((_right_top_point.get_x()) * (_right_top_point.get_x())) + ((_right_bottom_point.get_y()) * (_right_bottom_point.get_y())) - 2 * _right_top_point.get_y() * _right_bottom_point.get_y() + (_right_top_point.get_y() * _right_top_point.get_y()));
		//double b = sqrt(pow(_right_bottom_point.get_x() - _right_top_point.get_x(), 2) + pow(_right_bottom_point.get_y() - _right_top_point.get_y(), 2));
		double c = sqrt(((_left_bottom_point.get_x()) * (_left_bottom_point.get_x())) - 2 * _left_bottom_point.get_x() * _right_bottom_point.get_x() + ((_right_bottom_point.get_x()) * (_right_bottom_point.get_x())) + ((_left_bottom_point.get_y()) * (_left_bottom_point.get_y())) - 2 * _right_bottom_point.get_y() * _left_bottom_point.get_y() + (_right_bottom_point.get_y() * _right_bottom_point.get_y()));
		//double c = sqrt(pow(_left_bottom_point.get_x() - _right_bottom_point.get_x(), 2) + pow(_left_bottom_point.get_y() - _right_bottom_point.get_y(), 2));
		return ((a + b + c) / 2);
	}
	case Rectangle: {
		double a = _right_top_point.get_x() - _left_bottom_point.get_x();
		double b = _right_top_point.get_y() - _left_bottom_point.get_y();
		return 2 * (a + b);
		//return (abs(_right_top_point.get_x() - _left_bottom_point.get_x()) + (_right_top_point.get_y() - _left_bottom_point.get_y())) * 2;
	}
	default:
		throw std::runtime_error("Type error");
	}
}

double Figure::S() const {
	switch (_type) {
	case Circle: {
		double a = (_left_bottom_point.get_x() - _right_top_point.get_x());
		double b = (_left_bottom_point.get_y() - _right_top_point.get_y());
		return PI * sqrt((a * a) + (b * b)) * sqrt((a * a) + (b * b));
			//return PI * pow(sqrt(pow(_left_bottom_point.get_x() - _right_top_point.get_x(), 2) + pow(_left_bottom_point.get_y() - _right_top_point.get_y(), 2)), 2);
	}
	case Triangle: {
		double a = sqrt(((_right_top_point.get_x()) * (_right_top_point.get_x())) - 2 * _right_top_point.get_x() * _left_bottom_point.get_x() + ((_left_bottom_point.get_x()) * (_left_bottom_point.get_x())) + ((_right_top_point.get_y()) * (_right_top_point.get_y())) - 2 * _left_bottom_point.get_y() * _right_top_point.get_y() + (_left_bottom_point.get_y() * _left_bottom_point.get_y()));
		//double a = sqrt(pow(_right_top_point.get_x() - _left_bottom_point.get_x(), 2) + pow(_right_top_point.get_y() - _left_bottom_point.get_y(), 2));
		double b = sqrt(((_right_bottom_point.get_x()) * (_right_bottom_point.get_x())) - 2 * _right_bottom_point.get_x() * _right_top_point.get_x() + ((_right_top_point.get_x()) * (_right_top_point.get_x())) + ((_right_bottom_point.get_y()) * (_right_bottom_point.get_y())) - 2 * _right_top_point.get_y() * _right_bottom_point.get_y() + (_right_top_point.get_y() * _right_top_point.get_y()));
		//double b = sqrt(pow(_right_bottom_point.get_x() - _right_top_point.get_x(), 2) + pow(_right_bottom_point.get_y() - _right_top_point.get_y(), 2));
		double c = sqrt(((_left_bottom_point.get_x()) * (_left_bottom_point.get_x())) - 2 * _left_bottom_point.get_x() * _right_bottom_point.get_x() + ((_right_bottom_point.get_x()) * (_right_bottom_point.get_x())) + ((_left_bottom_point.get_y()) * (_left_bottom_point.get_y())) - 2 * _right_bottom_point.get_y() * _left_bottom_point.get_y() + (_right_bottom_point.get_y() * _right_bottom_point.get_y()));
		//double c = sqrt(pow(_left_bottom_point.get_x() - _right_bottom_point.get_x(), 2) + pow(_left_bottom_point.get_y() - _right_bottom_point.get_y(), 2));
		double p = (a + b + c) / 2;
		return (sqrt(p * (p - a) * (p - b) * (p - c)));
	}
	case Rectangle:
		return  abs(_right_top_point.get_x() - _left_bottom_point.get_x()) * (_right_top_point.get_y() - _left_bottom_point.get_y());
	default:
		throw std::runtime_error("Type error");
	}
}

Figure Figure::get_min_rectangle() const {
	if (_type == Triangle) {
		return Figure(Rectangle, _left_bottom_point, Point(_right_bottom_point.get_x(), _right_top_point.get_y()));
	}
	if (_type == Circle) {
		return Figure(Rectangle, _left_bottom_point, _right_top_point);
	}
	return Figure(Rectangle, _left_bottom_point, _right_top_point);
}