#pragma once
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>

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

	class Figure;
	using FigurePtr = Figure*;

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
		Figure(typeFigure type, Point left_bottom_point, Point right_bottom_point, Point right_top_point);
		typeFigure get_figure_type() const;
		std::string get_type() const;
		Point get_left_bottom_point() const;
		Point get_right_bottom_point() const;
		Point get_right_top_point() const;
		double get_perimetr() const;
		double get_area() const;
		Figure get_min_rectangle() const;
	};

	std::ostream& operator<<(std::ostream& stream, const Figure& fig);

	class Figurelist {
	private:
		FigurePtr* _figure;
		int _size;

	public:
		Figurelist();
		Figurelist(const Figurelist& copy);
		Figurelist& operator=(Figurelist copy);
		const Figure& get_figure_by_index(int i) const;
		int get_size() const;
		const Figure& operator[](int index) const;
		Figure& operator[](int index);
		void add(const Figure& fig);
		void insert(int index, Figure fig);
		void remove(int index);
		void clear();
		void swap(Figurelist& other);
		~Figurelist();
		int find_figure_min_area() const;
	};
	std::ostream& operator<<(std::ostream& stream, const Figurelist& fig);
}
