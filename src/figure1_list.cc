#include <figure1/figure1.h>
#include <cmath>
#include <stdexcept>

using namespace std;
using namespace Figures;

Figurelist::Figurelist() : _figure(nullptr), _size(0) {}

Figurelist::Figurelist(const Figurelist& copy) : _figure(new FigurePtr[copy._size]), _size(copy._size)
{
	for (int i = 0; i < _size; ++i)
		_figure[i] = new Figure(*copy._figure[i]);
}

Figurelist& Figurelist::operator=(Figurelist copy) {
	swap(copy);
	return *this;
}

const Figure& Figurelist::get_figure_by_index(int index) const {
	if (index < 0 || _size <= index)
		throw runtime_error("[FigureList::get_figure_by_index] Invalid index");
	return *_figure[index];
}

int Figurelist::get_size() const {
	return _size;
}

Figure& Figurelist::operator[](int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("Invalid index");
	return *_figure[index];
}

const Figure& Figurelist::operator[](int index) const {
	if (index < 0 || _size <= index)
		throw runtime_error("[FigureList::operator[]] Index is out of range");
	return *_figure[index];
}

void Figurelist::add(const Figure& f) {
	auto figure = new Figure * [_size + 1];
	for (int i = 0; i < _size; i++)
		figure[i] = _figure[i];
	figure[_size] = new Figure(f);
	delete[] _figure;
	_figure = figure;
	++_size;
}

void Figurelist::insert(int index, Figure figure) {
	if (size >= CAPACITY) {
		throw std::runtime_error("Full capacity reached.");
	}
	if (index < 0 || index > size) {
		throw std::runtime_error("Index out of range.");
	}
	//сдвиг элементов массива
	for (int i = size; i >= index; --i) {
		data[i] = data[i - 1];
	}
	data[index] = figure;
	++size;
}

void Figurelist::clear() {
	size = 0;
}


void Figurelist::remove(int index) {
	if (size == 0) {
		throw std::runtime_error("List is empty.");
	}
	if (index < 0 || index >= size) {
		throw std::runtime_error("Index out of range.");
	}
	for (int i = index; i < size - 1; ++i) {
		data[i] = data[i + 1];
	}
	--size;
}

//минимальная площадь
int Figurelist::find_figure_min_square() const {
	if (size <= 0) {
		throw std::runtime_error("Figurelist is empty");
	}
	int index = 0;
	double min_square = data[0].get_area();
	for (int i = 1; i < size; ++i) {
		double current_square = data[i].get_area();
		if (current_square < min_square) {
			index = i;
			min_square = current_square;
		}
	}
	return index;
}