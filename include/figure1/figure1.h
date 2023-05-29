#pragma once
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace Figures {
	const double PI = 3.14;
	/*enum typeFigure {
		Circle,
		Triangle,
		Rectangle
	};*/
	class Point;

	using PointPtr = std::shared_ptr<Point>;

	class Point {
		double _x;
		double _y;
	public:
		Point() : _x(), _y() {}
		Point(double _x, double _y) : _x(_x), _y(_y) {}
		double get_x() const;
		double get_y() const;
		void print()const;
	};

	class Figure;

	using FigurePtr = std::shared_ptr<Figure>;
	
	class Figure {
	protected:
		//typeFigure _type;
		//circle and rectangle
		Point _left_bottom_point;
		Point _right_top_point;
		//triangle
		Point _right_bottom_point;
	public:
		Figure() : _left_bottom_point(Point(0, 0)), _right_top_point(Point(0, 0)) {}
		//circle nad rectangle
		Figure(Point left_bottom_point, Point right_top_point) : _left_bottom_point(left_bottom_point), _right_top_point(right_top_point) {}
		//triangle
		Figure(Point left_bottom_point, Point right_bottom_point, Point right_top_point) : _left_bottom_point(left_bottom_point), _right_bottom_point(right_bottom_point), _right_top_point(right_top_point) {}

		Point get_left_bottom_point() const;
		Point get_right_bottom_point() const;
		Point get_right_top_point() const;

		virtual void print() const = 0;
		virtual FigurePtr clone() const = 0;

		virtual double get_perimetr() const = 0;
		virtual double get_area() const = 0;
		virtual FigurePtr get_min_rectangle() const = 0;
	};

	class Circle : public Figure {
	public:
		Circle(): Figure() {}
		Circle(Point left_bottom_point, Point right_top_point):Figure(left_bottom_point, right_top_point){}
		void print() const override;
		FigurePtr clone() const override;
		virtual double get_perimetr()const override;
		virtual double get_area()const override;
		virtual FigurePtr get_min_rectangle() const override;
	};

	class Rectangle : public Figure {
	public:
		Rectangle(): Figure() {}
		Rectangle(Point left_bottom_point, Point right_top_point):Figure(left_bottom_point, right_top_point) {}
		void print() const override;
		FigurePtr clone() const override;
		virtual double get_perimetr()const override;
		virtual double get_area()const override;
		virtual FigurePtr get_min_rectangle() const override;
	};

	class Triangle : public Figure {
	public:
		Triangle(): Figure() {}
		Triangle(Point left_bottom_point, Point right_bottom_point, Point right_top_point):Figure(left_bottom_point, right_bottom_point, right_top_point) {}
		void print() const override;
		FigurePtr clone() const override;
		virtual double get_perimetr()const override;
		virtual double get_area()const override;
		virtual FigurePtr get_min_rectangle() const override;
	};

	class FigureList {
	private:
		std::vector<FigurePtr>_Figureslist;
	public:
		FigureList() = default;
		FigureList(const FigureList& other);
		FigureList& operator=(FigureList other);
		FigurePtr operator[](int index);
		const FigurePtr operator[](int index)const;
		int get_size() const;
		void add(FigurePtr fig);
		void insert(FigurePtr fig, int index);
		void remove(int index);
		void clear();
		void swap(FigureList& other);
		void print();
		int find_figure_min_area() const;
	};
}
