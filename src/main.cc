#include <figure1/menu_figure1.h>
#include "figure1/figure1.h"
#include <Windows.h>

using namespace Figures;
using namespace menu;
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	Figurelist fig;
	Figure figure;

	menu::text_menu();

	while (true) {
		int choice = menu::get_key();
		int index = 0;

		system("cls");
		menu::text_menu();

		if (choice == 57) {
			fig.clear();
			break;
		}

		switch (choice) {

		case 49:
			fig.add(create_figure());
			break;

		case 50:
			cout << "������� ������, �� �������� ����� �������� ����� ������: ";
			cin >> index;
			fig.insert(index, create_figure());
			break;


		case 51:
			cout << "������� ������, �� �������� ����� ������� ������: ";
			cin >> index;
			fig.remove(index);
			break;

		case 52:
			cout << "������� ������ ������, � ������� ����� ��������� ��������(P): ";
			cin >> index;
			cout << "�������� = " << fig[index].get_perimetr() << endl;
			break;

		case 53:
			cout << "������� ������ ������, � ������� ����� ��������� �������(S): ";
			cin >> index;
			cout << "������� = " << fig[index].get_area() << endl;
			break;

		case 54:
			cout << "������� ������ ������, � ������� ����� ����� ����������� ����������� �������������: ";
			cin >> index;
			cout << fig[index].get_min_rectangle() << endl;
			break;

		case 55:
			cout << "������ ������ � ����������� ��������" << fig.find_figure_min_area();
			break;

		case 56:
			cout << fig;
			break;
		}

	}
	return 0;
}