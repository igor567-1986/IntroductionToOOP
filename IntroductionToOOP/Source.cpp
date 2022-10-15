#include<iostream>
using namespace std;

#define tab "/t"

class Point
{
	double x;
	double y;
public:
	void setVeriablePoint(double x1, double y1)
	{
		x = x1;
		y = y1;
	}
	void getVeriablePoint()
	{
		cout << x << "\t" << y << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl;
	double x1, y1;
	cout << "Введите координаты точки: "; cin >> x1; cin >> y1;
	int a;      //Обьявление переменной а типа int
    Point A;    //Обявление переменной "A" типо Point
	            //Обьявление обьект 'A'структуры Point
	            //Обьявление экземпляра 'A' структуры Point
	/*A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;*/
    A.setVeriablePoint(x1, y1);
	A.getVeriablePoint();
}