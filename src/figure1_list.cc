#include <figure1/figure1.h>
#include <cmath>
#include <stdexcept>

using namespace std;
using namespace Figures;

Figurelist::Figurelist() {
	size = 0;
}

Figurelist::Figurelist(Figure figure[], int _size) {
	size = _size;
	for (int i = 0; i < _size; ++i) {
		this->data[i] = figure[i];
	}
}


Figure Figurelist::get_figure_by_index(int index) const {
	if (index < 0 || index >= size) {
		throw std::runtime_error("Index out of range.");
	}
	return data[index];
}

int Figurelist::get_size() const {
	return size;
}

Figure Figurelist::operator[](int index) const {
	if (index < 0 || index >= size) {
		throw std::runtime_error("Index out of range.");
	}
	return data[index];
}

Figure& Figurelist::operator[](int index) {
	if (index < 0 || index >= size) {
		throw std::runtime_error("Index out of range.");
	}
	return data[index];
}

void Figurelist::insert(int index, Figure figure) {
	if (size >= CAPACITY) {
		throw std::runtime_error("Full capacity reached.");
	}
	if (index < 0 || index > size) {
		throw std::runtime_error("Index out of range.");
	}
	//сдвиг элементов массива
	for (int i = size - 1; i >= index; --i) {
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
		throw std::runtime_error("Plane is empty.");
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
	double min_square = this->data[0].S();
	for (int i = 1; i < size; ++i) {
		double current_square = data[i].S();
		if (current_square < min_square) {
			index = i;
			min_square = current_square;
		}
	}
	return index;
}