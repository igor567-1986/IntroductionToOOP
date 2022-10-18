#include<iostream>
using namespace std;

#define tab "\t"
//#define STRUCT_POINT

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//        Constructors:
	Point()
	{
		x = y = double();
		cout << "Constructor: \t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor: \t" << this << endl;
	}

	//          Methods :
	void print()const
	{
		cout << " X = "  << x << " \tY = " << y << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	cout << "Hello OOP" << endl;
	double x1, y1;
	cout << "Введите координаты точки: "; cin >> x1; cin >> y1;
	int a;      //Обьявление переменной а типа int
    Point A;    //Обявление переменной "A" типо Point
	//            //Обьявление обьект 'A'структуры Point
	            //Обьявление экземпляра 'A' структуры Point
	//*A.x = 2;
	//A.y = 3;
	//cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;*/
    A.setVeriablePoint(x1, y1);
	A.getVeriablePoint();

	Point A;
	A.set_x(2);
	A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B;
	B.set_x(5);
	B.set_y(7);
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	B.print();
#endif // DEBUG

	Point A; // Default constructor
	A.print();
	 
	Point B = 5; // Single-Argument constructor
	B.print();

	Point C(2, 3);
	C.print();
}