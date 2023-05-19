#include <figure1/figure1.h>

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
	for (int i = 0; i < _size; ++i)
		figure[i] = _figure[i];
	figure[_size] = new Figure(f);
	delete[] _figure;
	_figure = figure;
	++_size;
}


void Figurelist::insert(int index, Figure fig) {
	if (index < 0 || _size <= index)
		throw runtime_error("[FigureList::insert] Invalid index");
	auto figure = new Figure * [_size + 1];
	for (int i = 0; i < _size; ++i)
		figure[i] = _figure[i];
	for (int i = _size; i > index; --i)
		figure[i] = figure[i - 1];
	figure[index] = new Figure(fig);
	delete[] _figure;
	_figure = figure;
	++_size;
}

void Figurelist::clear() {
	if (_figure == nullptr)
		return;
	for (int i = 0; i < _size; ++i)
		delete _figure[i];
	_size = 0;
	delete[] _figure;
	_figure = nullptr;
}

void Figurelist::remove(int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("[FigureList::remove] FigureList is empty");
	delete _figure[index];
	for (int i = index; i < _size - 1; ++i)
		_figure[i] = _figure[i + 1];
	--_size;
}

void Figurelist::swap(Figurelist& other) {
	std::swap(_size, other._size);
	std::swap(_figure, other._figure);
}

Figurelist::~Figurelist() {
	clear();
}

//минимальная площадь
int Figurelist::find_figure_min_area() const {
	if (_size <= 0)
		return -1;
	int index = 0;
	double min_area = _figure[0]->get_area();
	for (int i = 1; i < _size; ++i) {
		float current_area = _figure[i]->get_area();
		if (current_area < min_area) {
			index = i;
			min_area = current_area;
		}
	}
	return index;
}