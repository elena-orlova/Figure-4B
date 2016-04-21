#include "My2DPoint.h"

#include "My2DObject4B.h"

#include <iomanip>


int main() {


	setlocale(LC_ALL, "rus");

	setlocale(LC_NUMERIC, "eng");


	std::cout << "Орлова Елена, БПМ142\nДомашняя работа 1, модуль 3. Вариант 20 (4B) \n" << std::endl;

	cout << setfill('*') << setw(80) << "";


	CMy2DPoint centre_point(1, 1), b(0, -1);

	CMy2DObject4B MyFigure(20, 10, 3, 2, 0, centre_point);


	cout << "A = " << MyFigure.GetA() << endl;

	cout << "A1 = " << MyFigure.GetA1() << endl;

	cout << "A2 = " << MyFigure.GetA2() << endl;

	cout << "A3 = " << MyFigure.GetA3() << endl;

	cout << "Angle = " << MyFigure.GetAngle() << endl;

	cout << "Center " << MyFigure.GetCenter() << endl;


	MyFigure.SetA(4);

	MyFigure.Rotate(720);

	cout << "точка 1" << endl;

	MyFigure.IsInside(b);

	cout << "точка 2" << endl;

	MyFigure.IsInside(-10, 11);


	system("pause");

	return 0;

}