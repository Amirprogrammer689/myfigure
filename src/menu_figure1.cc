#include <figure1/menu_figure1.h>
#include <string.h>

using namespace Figures;
using namespace menu;
using namespace std;

void menu::text_menu() {
	cout << " |--------------------------------------------------------------------|" << endl;
	cout << " |                                Меню                                |" << endl;
	cout << " |--------------------------------------------------------------------|" << endl;
	cout << " | 1 - Добавить фигуру в конец                                        |" << endl;
	cout << " | 2 - Добавить фигуру по индексу                                     |" << endl;
	cout << " | 3 - Удалить фигуру по индексу                                      |" << endl;
	cout << " | 4 - Рассчитать периметр                                            |" << endl;
	cout << " | 5 - Рассчитать площадь                                             |" << endl;
	cout << " | 6 - Вычислить минимальный обрамляющий прямоугольник                |" << endl;
	cout << " | 7 - Поиск в наборе первой фигуры с минимальной площадью            |" << endl;
	cout << " | 8 - Вывести список фигур                                           |" << endl;
	cout << " | 9 - Выйти из системы                                               |" << endl;
	cout << " |--------------------------------------------------------------------|" << endl;
}

int menu::get_key() {
	int key = _getch();
	if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56) || (key == 57))
		return key;
}

Figure menu::create_figure() {
	Figure fig;
	int type;
	Point _left_bottom_point;
	Point _right_bottom_point;
	Point _right_top_point;
	double x1, x2, x3, y1, y2, y3;

	cout << "Введите тип фигуры (1 - Круг, 2 - Прямоугольник, 3 - Треугольник): ";
	cin >> type;
	if (type != 1 && type != 2 && type != 3)
		throw runtime_error("Invalid type");
	if (type == 1) {
		cout << " Введите левую нижнюю точку \n " << "x=";
		cin >> x1;
		cout << "y=";
		cin >> y1;

		cout << " Введите правую верхнюю точку \n " << "x=";
		cin >> x2;
		cout << "y=";
		cin >> y2;

		return Figure(Circle, Point(x1, y1), Point(x2, y2));
	}
	
	if (type == 2) {
		cout << "Введите левую нижнюю точку \n " << "x=";
		cin >> x1;
		cout << "y=";
		cin >> y1;

		cout << "Введите правую верхнюю точку \n " << "x=";
		cin >> x2;
		cout << "y=";
		cin >> y2;

		return Figure(Rectangle, Point(x1, y1), Point(x2, y2));
	}

	if (type == 3) {
		cout << "Трапеция ";
		cout << "Введите левую нижнюю точку \n " << "x=";
		cin >> x1;
		cout << "y=";
		cin >> y1;

		cout << " Введите правую верхнюю точку \n " << "x=";
		cin >> x2;
		cout << "y=";
		cin >> y2;

		cout << "Введите левую верхнюю точку \n " << "x=";
		cin >> x3;
		cout << "y=";
		cin >> y3;

		return Figure(Triangle, Point(x1, y1), Point(x2, y2), Point(x3, y3));
	}
}