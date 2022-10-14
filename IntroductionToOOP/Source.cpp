#include<iostream>
using namespace std;

#define tab "/t"

class Point
{
public:
	double x;
	double y;
};
void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl;

	int a;      //Обьявление переменной а типа int
    Point A;    //Обявление переменной "A" типо Point
	            //Обьявление обьект 'A'структуры Point
	            //Обьявление экземпляра 'A' структуры Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
}