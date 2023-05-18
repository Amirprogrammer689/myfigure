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

Figure::Figure() {
	_type = Rectangle;
	_right_bottom_point = Point(1, 1);
	_left_bottom_point = Point(-1, -1);
}

//создание заполненного объекта
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

std::string Figure::get_type() const {
	switch (_type)
	{
	case typeFigure::Circle:
		return "Circle";
	case typeFigure::Triangle:
		return "Triangle";
	case typeFigure::Rectangle:
		return "Rectangle";
	default:
		throw runtime_error("Unknown type");
	}
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
double Figure::get_perimetr() const {
	switch (_type) {
	case Circle: {
		double a = (_left_bottom_point.get_x() - _right_top_point.get_x());
		double b = (_left_bottom_point.get_y() - _right_top_point.get_y());
		return 2 * PI * sqrt((a*a) + (b*b));
	}
		case Triangle: {
		double a = sqrt(((_right_top_point.get_x())*(_right_top_point.get_x())) - 2 * _right_top_point.get_x() * _left_bottom_point.get_x() + ((_left_bottom_point.get_x()) * (_left_bottom_point.get_x())) + ((_right_top_point.get_y()) * (_right_top_point.get_y())) - 2 * _left_bottom_point.get_y() * _right_top_point.get_y() + (_left_bottom_point.get_y() * _left_bottom_point.get_y()));
		double b = sqrt(((_right_bottom_point.get_x()) * (_right_bottom_point.get_x())) - 2 * _right_bottom_point.get_x() * _right_top_point.get_x() + ((_right_top_point.get_x()) * (_right_top_point.get_x())) + ((_right_bottom_point.get_y()) * (_right_bottom_point.get_y())) - 2 * _right_top_point.get_y() * _right_bottom_point.get_y() + (_right_top_point.get_y() * _right_top_point.get_y()));
		double c = sqrt(((_left_bottom_point.get_x()) * (_left_bottom_point.get_x())) - 2 * _left_bottom_point.get_x() * _right_bottom_point.get_x() + ((_right_bottom_point.get_x()) * (_right_bottom_point.get_x())) + ((_left_bottom_point.get_y()) * (_left_bottom_point.get_y())) - 2 * _right_bottom_point.get_y() * _left_bottom_point.get_y() + (_right_bottom_point.get_y() * _right_bottom_point.get_y()));
		return ((a + b + c) / 2);
	}
	case Rectangle: {
		double a = _right_top_point.get_x() - _left_bottom_point.get_x();
		double b = _right_top_point.get_y() - _left_bottom_point.get_y();
		return 2 * (a + b);
	}
	default:
		throw std::runtime_error("Type error");
	}
}

//площадь
double Figure::get_area() const {
	switch (_type) {
	case Circle: {
		double a = (_left_bottom_point.get_x() - _right_top_point.get_x());
		double b = (_left_bottom_point.get_y() - _right_top_point.get_y());
		return PI * sqrt((a * a) + (b * b)) * sqrt((a * a) + (b * b));
	}
	case Triangle: {
		double a = sqrt(((_right_top_point.get_x()) * (_right_top_point.get_x())) - 2 * _right_top_point.get_x() * _left_bottom_point.get_x() + ((_left_bottom_point.get_x()) * (_left_bottom_point.get_x())) + ((_right_top_point.get_y()) * (_right_top_point.get_y())) - 2 * _left_bottom_point.get_y() * _right_top_point.get_y() + (_left_bottom_point.get_y() * _left_bottom_point.get_y()));
		double b = sqrt(((_right_bottom_point.get_x()) * (_right_bottom_point.get_x())) - 2 * _right_bottom_point.get_x() * _right_top_point.get_x() + ((_right_top_point.get_x()) * (_right_top_point.get_x())) + ((_right_bottom_point.get_y()) * (_right_bottom_point.get_y())) - 2 * _right_top_point.get_y() * _right_bottom_point.get_y() + (_right_top_point.get_y() * _right_top_point.get_y()));
		double c = sqrt(((_left_bottom_point.get_x()) * (_left_bottom_point.get_x())) - 2 * _left_bottom_point.get_x() * _right_bottom_point.get_x() + ((_right_bottom_point.get_x()) * (_right_bottom_point.get_x())) + ((_left_bottom_point.get_y()) * (_left_bottom_point.get_y())) - 2 * _right_bottom_point.get_y() * _left_bottom_point.get_y() + (_right_bottom_point.get_y() * _right_bottom_point.get_y()));
		double p = (a + b + c) / 2;
		return (sqrt(p * (p - a) * (p - b) * (p - c)));
	}
	case Rectangle:
		return  abs(_right_top_point.get_x() - _left_bottom_point.get_x()) * (_right_top_point.get_y() - _left_bottom_point.get_y());
	default:
		throw std::runtime_error("Type error");
	}
}

//минимальный обрамл€ющий треугольник
Figure Figure::get_min_rectangle() const {
	if (_type == Triangle) {
		return Figure(Rectangle, _left_bottom_point, Point(_right_bottom_point.get_x(), _right_top_point.get_y()));
	}
	if (_type == Circle) {
		return Figure(Rectangle, _left_bottom_point, _right_top_point);
	}
	return Figure(Rectangle, _left_bottom_point, _right_top_point);
}

std::ostream& Figures::operator<<(std::ostream& stream, const Figure& fig) {
	if (fig.get_type() == "Triangle")
		stream << "“ип фигуры: " << fig.get_type() << " \n "
		<< " Ћева€ нижн€€: x = " << fig.get_left_bottom_point().get_x() << " y = " << fig.get_left_bottom_point().get_y() << "\n"
		<< " ѕрава нижн€€: x = " << fig.get_right_bottom_point().get_x() << " y = " << fig.get_right_bottom_point().get_y() << "\n"
		<< " ѕрава€ верхн€€: x = " << fig.get_right_top_point().get_x() << " y = " << fig.get_right_top_point().get_y() << "\n" << endl;

	else
		stream << "“ип фигуры: " << fig.get_type() << " \n "
		<< " Ћева€ нижн€€: x = " << fig.get_left_bottom_point().get_x() << " y = " << fig.get_left_bottom_point().get_y() << "\n"
		<< " ѕрава€ верхн€€: x = " << fig.get_right_top_point().get_x() << " y = " << fig.get_right_top_point().get_y() << "\n" << endl;
	return stream;
}