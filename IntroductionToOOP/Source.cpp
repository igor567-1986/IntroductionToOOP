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

	int a;      //���������� ���������� � ���� int
    Point A;    //��������� ���������� "A" ���� Point
	            //���������� ������ 'A'��������� Point
	            //���������� ���������� 'A' ��������� Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
}