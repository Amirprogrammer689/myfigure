#include "figure1/menu_figure1.h"
#include "figure1/figure1.h"
#include <iostream>
#include <windows.h>

using namespace Figures;
using namespace menu;
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	FigureList figures;

	system("color FC");

	menu::text_menu();
	
	while (true) {
		int choice = menu::get_key();
		int index = 0;

		system("cls");
		menu::text_menu();

		if (choice == 57) {
			figures.clear();
			break;
		}
		try {
			switch (choice) {

			case 49:
				figures.add(create_figure());
				figures.print();
				break;

			case 50:
				cout << "¬ведите индекс, по которому нужно вставить новую фигуру: ";
				cin >> index;
				figures.insert(create_figure(), index);
				figures.print();
				break;


			case 51:
				cout << "¬ведите индекс, по которому нужно удалить фигуру: ";
				cin >> index;
				figures.remove(index);
				figures.print();
				break;

			case 52:
				cout << "¬ведите индекс фигуры, у которой нужно вычислить периметр(P): ";
				cin >> index;
				cout << "ѕериметр = " << figures[index]->get_perimetr() << endl;
				break;

			case 53:
				cout << "¬ведите индекс фигуры, у которой нужно вычислить площадь(S): ";
				cin >> index;
				cout << "ѕлощадь = " << figures[index]->get_area() << endl;
				break;

			case 54:
				cout << "¬ведите индекс фигуры, у которой нужно найти минимальный обрамл€ющий пр€моугольник: ";
				cin >> index;
				cout << figures[index]->get_min_rectangle() << endl;
				break;

			case 55:
				cout << "»ндекс фигуры с минимальной площадью: " << figures.find_figure_min_area();
				break;

			case 56:
				figures.print();
				break;
			}
		}
		catch (const exception& ex) {
			cout << ex.what() << endl;
		}

		catch (...) {
			cout << "Unknown error" << endl;
		}

	}
	return 0;
}