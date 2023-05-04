#pragma once
#include <string>

namespace Figures {
	const double PI = 3.14;
	enum typeFigure { 
		Circle,
		Triangle,
		Rectangle
	};

	class Point {
		double _x;
		double _y;
	public:
		Point() : _x(), _y() {}
		Point(double _x, double _y) : _x(_x), _y(_y) {}
		double get_x() const;
		double get_y() const;
	};

	class Figure {
		typeFigure _type;
		//circle and rectangle
		Point _left_bottom_point;
		Point _right_top_point;
		//triangle
		Point _right_bottom_point;
	public:
		Figure();
		//circle nad rectangle
		Figure(typeFigure type, Point left_bottom_point, Point right_top_point);
		//triangle
		Figure(typeFigure type, Point left_bottom_point, Point right_bottom_point, Point top_point);
		typeFigure get_figure_type() const;
		Point get_left_bottom_point() const;
		Point get_right_top_point() const;
		double get_perimetr() const;
		double get_area() const;
		Figure get_min_rectangle() const;
	};

	class Figurelist {
		static const int CAPACITY = 10;
		Figure data[CAPACITY];
		int size;
	public:
		Figurelist();
		Figurelist(Figure figures[], int size);
		Figure get_figure_by_index(int i) const;
		int get_size() const;
		Figure operator[](int index) const;
		Figure& operator[](int index);
		void insert(int index, Figure fig);
		void remove(int index);
		void clear();
		int find_figure_min_square() const;
	};
}
