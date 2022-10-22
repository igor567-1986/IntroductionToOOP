﻿#include<iostream>
//#include<math.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimetr "\n-------------------------------------------\n"
//#define STRUCT_POINT
#define CONSTRUCTORS_CHEK
#define DISTANCE_CHECK


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
	/*Point()
	{
		x = y = double();
		cout << "Constructor: \t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
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
	double distance(const Point& A)const
	{
		/*double a = 0.00001;
		double root = 0;
		double n= ((x - A.x) * (x - A.x) + (y - A.y) * (y - A.y));
		while (root * root < n)root += a;
		return root;*/
		//return sqrt((x - A.x) * (x - A.x) + (y - A.y) * (y - A.y));
		return sqrt(pow(x - A.x, 2) + pow(y - A.y, 2));
	}
};

double distance(const Point &A,const Point& B);

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
    

	Point A;
	
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
    A.set_x(2);
	A.set_y(3);

	Point B;
	B.set_x(5);
	B.set_y(7);
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	B.print();
#endif // DEBUG
	
#ifdef CONSTRUCTORS_CHEK
	Point A; // Default constructor
	A.print();

	Point B = 5.3; // Single-Argument constructor
	B.print();

	Point C(4.4, 5.2); //  constructor
	C.print();
#endif // CONSTRUCTORS_CHEK


#ifdef DISTANCE_CHECK
	cout << delimetr << endl;
	cout << "Расстояние от точки А до точки С " << "=" << A.distance(C) << endl;
	cout << delimetr << endl;
	cout << "Расстояние от точки С до точки А " << "=" << C.distance(A) << endl;
	cout << delimetr << endl;
	cout << distance(B, C) << endl;
	cout << delimetr << endl;
#endif // DISTANCE_CHECK


	Point D = C;
	D.print();
}
double distance(const Point& A,const Point &B)
{
	return A.distance (B);
}