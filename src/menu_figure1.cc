#include <figure1/menu_figure1.h>
#include <string.h>

using namespace Figures;
using namespace menu;
using namespace std;

void menu::text_menu() {
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                ћеню                               |" << endl;
	cout << " Ч-------------------------------------------------------------------" << endl;
	cout << " | 1 - добавить фигуру в конец                                       |" << endl;
	cout << " | 2 - добавить фигуру по индексу                                    |" << endl;
	cout << " | 3 - удалить фигуру по индексу                                     |" << endl;
	cout << " | 4 - рассчитать периметр                                           |" << endl;
	cout << " | 5 - рассчитать площадь                                            |" << endl;
	cout << " | 6 - вычислить минимальный обрамл€ющий пр€моугольник               |" << endl;
	cout << " | 7 - поиск в наборе первой фигуры с максимальной площадью          |" << endl;
	cout << " | 8 - вывести список фигур                                          |" << endl;
	cout << " | 9 - выйти из системы                                              |" << endl;
	cout << "  -------------------------------------------------------------------" << endl;
}

int menu::get_key() {
	int key = _getch();
	if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56) || (key == 57))
		return key;
}

Figure menu::create_figure() {
	Figure fig;
	int type;
	Point left_bottom;
	Point right_top;
	Point right_bottom;
	float x1, x2, x3, y1, y2, y3;

	cout << "¬ведите тип фигуры (1- руг 2-“реугольник 3-ѕр€моугольник): ";
	cin >> type;
	if (type != 1 && type != 2 && type != 3)
		throw runtime_error("Invalid type");
	if (type == 1) {
		cout << " ¬ведите левую нижнюю точку \n " << "x=";
		cin >> x1;
		cout << "y=";
		cin >> y1;

		cout << " ¬ведите правую верхнюю точку \n " << "x=";
		cin >> x2;
		cout << "y=";
		cin >> y2;
		return Figure(Circle, Point(x1, y1), Point(x2, y2));
	}
	
	if (type == 2) {
		cout << "“рапеци€ ";
		cout << "¬ведите левую нижнюю точку \n " << "x=";
		cin >> x1;
		cout << "y=";
		cin >> y1;

		cout << " ¬ведите правую верхнюю точку \n " << "x=";
		cin >> x2;
		cout << "y=";
		cin >> y2;

		cout << "¬ведите левую верхнюю точку \n " << "x=";
		cin >> x3;
		cout << "y=";
		cin >> y3;

		return Figure(Triangle, Point(x1, y1), Point(x2, y2), Point(x3, y3));
	}

	if (type == 3) {
		cout << "¬ведите левую нижнюю точку \n " << "x=";
		cin >> x1;
		cout << "y=";
		cin >> y1;

		cout << "¬ведите правую верхнюю точку \n " << "x=";
		cin >> x2;
		cout << "y=";
		cin >> y2;
		return Figure(Rectangle, Point(x1, y1), Point(x2, y2));
	}
}