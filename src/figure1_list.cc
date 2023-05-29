#include <figure1/figure1.h>

using namespace std;
using namespace Figures;

FigureList::FigureList(const FigureList& other) {
	const int n = other.get_size();
	for (int i = 0; i < n; ++i)
		_Figureslist.push_back(other[i]->clone());
}

FigureList& FigureList::operator=(FigureList other) {
	swap(other);
	return *this;
}

int FigureList::get_size() const {
	return _Figureslist.size();
}

const FigurePtr FigureList::operator[](int index) const {
	if (index < 0 || _Figureslist.size() <= index)
		throw runtime_error("[FigureList::operator[]] Index is out of range");
	return _Figureslist[index];
}

FigurePtr FigureList::operator[](int index) {
	if (index < 0 || _Figureslist.size() <= index)
		throw runtime_error("Invalid index");
	return _Figureslist[index];
}

void FigureList::swap(FigureList& other) {
	_Figureslist.swap(other._Figureslist);
}

void FigureList::add(FigurePtr fig) {
	_Figureslist.push_back(fig);
}

void FigureList::insert(FigurePtr fig, int index) {
	if (index < 0 || _Figureslist.size() < index)
		throw runtime_error("[FigureList::insert] Invalid index");
	_Figureslist.insert(_Figureslist.begin() + index, fig);
}

void FigureList::clear() {
	_Figureslist.clear();
}

void FigureList::remove(int index) {
	if (index < 0 || _Figureslist.size() <= index)
		throw runtime_error("[FigureList::remove] FigureList is empty");
	_Figureslist.erase(_Figureslist.begin() + index);
}

void FigureList::print() {
	for (int i = 0; i < _Figureslist.size(); i++) {
		cout << i + 1 << ") ";
		_Figureslist[i]->print();
	}
}

int FigureList::find_figure_min_area() const {
	if (_Figureslist.size() <= 0)
		return -1;
	int index = 0;
	float min_area = _Figureslist[0]->get_area();
	for (int i = 1; i < _Figureslist.size(); i++) {
		float current_area = _Figureslist[i]->get_area();
		if (current_area < min_area) {
			index = i;
			min_area = current_area;
		}
	}
	return index;
}

//минимальная площадь
/*int Figurelist::find_figure_min_area() const {
	if (_size <= 0)
		return -1;
	int index = 0;
	double min_area = _figure[0]->get_area();
	for (int i = 1; i < _size; ++i) {
		double current_area = _figure[i]->get_area();
		if (current_area < min_area) {
			index = i;
			min_area = current_area;
		}
	}
	return index;
}*/