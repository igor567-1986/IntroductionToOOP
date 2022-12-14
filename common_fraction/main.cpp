#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimetr "\n----------------------------------\n"
class fraction;//Обьявление класса
fraction operator*(fraction left, fraction right);
fraction operator/(const fraction left, const  fraction right);
fraction operator+(fraction left, fraction right);
fraction operator-(fraction left, fraction right);
fraction& reduce();

class fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const {return integer;}
	int get_numerator()const {return numerator;}
	int get_denominator()const {return denominator;	}
	void set_integer(int integer) { this->integer = integer; }
	void set_numerator(int numerals) {this-> numerator = numerals;}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	             // Constructors
	fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	 explicit fraction(int integer)
	{
		set_integer(integer);
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	 fraction(double decimal)
	 {
		 integer = decimal;// сохраняем целую часть
		 decimal += 1e-10;
		 denominator = 1e+9;
		 numerator = (decimal - integer) * denominator;
		 reduce();
		 cout << "DoubleConstractor" << this << endl;
	 }
	fraction(int numerator, int denominator)
	{
		this->integer = 0;
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	fraction(int integer , int numerator , int denominator )
	{
		set_integer ( integer);
		set_numerator ( numerator);
		set_denominator ( denominator);
		reduce();
		cout << "Constructor:\t" << this << endl;
	}
	fraction(const fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator; 
		this->denominator = other.denominator;
		cout << "CopyConstructor: " << this << endl;
	}
	~fraction()	{cout << "Destructor: \t" << this << endl;}
	                //Operators
	fraction& operator=(const fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	fraction& operator++()
	{
		integer++;
		return *this;
	}
	fraction operator++(int)
	{
		fraction old;
		integer++;
		return old;
	} 
	fraction& operator()(int integer,int numerator,int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	fraction& operator*=(const fraction& other) {return *this=*this*other;}
	fraction& operator/=(const fraction& other) {return *this=*this/other;}
	fraction& operator+=(const fraction& other) {return *this=*this+other;}
	fraction& operator-=(const fraction& other) {return *this=*this-other;}
	friend istream& operator>>(istream& in, fraction& obj);
		               // Metodg:
	fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	fraction to_proper()
	{
		integer = numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	fraction inverted()const
	{
		fraction inverted=*this;
		inverted.to_improper();
		/*int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;*/
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	fraction& reduce()
	{
		for (int i = 10; i > 1; i--)
			if (this->numerator % i == 0 && this->denominator % i == 0)
			{
				this->numerator = this->numerator / i;
				this->denominator = this->denominator / i;
				i++;
			}
		return *this;
	}
	                   // TYPE CAST OPERATION
	explicit operator int()const
	{
		return integer + numerator / denominator;
	}
	explicit operator double() const
	{
		return integer + double(numerator) / denominator;
	}
};
ostream& operator<<(ostream& os, const fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
//istream& operator>>(istream& in ,fraction & obj)
//{
//	cout << "Введите целую часть:" << endl;
//	in >> obj.integer;
//	cout << "Введите числитель часть:" << endl;
//	in >> obj.numerator;
//	cout << "Введите знаменатель часть:" << endl;
//	in >> obj.denominator;
//	if (obj.denominator == 0)
//	{
//		obj.integer += obj.numerator;
//		obj.numerator = 0;
//	}
//	return in;
//	
//}
istream& operator>> (istream& is, fraction& obj)
{
	const int SIZE = 256;
	char buffer[SIZE]{};
	is.getline(buffer, SIZE);
	char delimetrs[] = "()/ ";
	int number[3] = {}; //Здесь будут хранится числа извлеченные из строки.

	int n = 0;
	for (char* pch = strtok(buffer, delimetrs); pch; pch = strtok(NULL, delimetrs))
	{
		number[n++] = atoi(pch);
		//atoi(char* str) ASCII string to integer
	}
	//for (int i = 0; i < n; i++)cout << number[i] << "\t";	cout << endl;
	obj = fraction();
	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2:
		obj.set_numerator(number[0]);
		obj.set_denominator(number[1]);
		break;
	case 3:
		obj.set_integer(number[0]);
		obj.set_numerator(number[1]);
		obj.set_denominator(number[2]);
	}
	return is;
}

fraction operator*( fraction left, fraction right)
{
	left.to_improper();
	right.to_improper();
	/*fraction resault;
	resault.set_numerator(left.get_numerator() * right.get_numerator());
	resault.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*fraction resault
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	return resault;*/
	return fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
fraction operator/(const fraction left,const  fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return fraction
	(
		left.get_numerator() * right.get_denominator(),
		right.get_numerator() * left.get_denominator()
	).to_proper();*/
	return (left * right.inverted()).to_proper().reduce();
}
fraction operator+(fraction left, fraction right)
{
	left.to_improper();
	right.to_improper();
	return fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
fraction operator-(fraction left, fraction right)
{
	left.to_improper();
	right.to_improper();
	return fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
	
}



bool operator==( fraction left,  fraction right)
{
	left.to_improper();
	right.to_improper();
	return 	 left.get_numerator() * right.get_denominator()==
		right.get_numerator() * left.get_denominator();
}
bool operator!=(const fraction& left, const fraction& right){	return!(left == right);}
bool operator<( fraction left,  fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < 
		right.get_numerator() * left.get_denominator();
}
bool operator<=(const fraction& left,const  fraction& right){	return left < right || left == right;}
bool operator>(const fraction& left, const fraction& right){	return!(left < right);}
bool operator>=(const fraction& left, const fraction& right){	return!(left <= right);}


//#define CONSTRACTORS_CHEK
//#define HOME_WOR
 //#define COMPARISSON_OPERATORS_CHECK
//#define CONVERSIONS_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER_TYPES
#define HOME_WORK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRACTORS_CHEK
	fraction A;
	cout << A << endl;
	double b = 5;
	fraction B = 5;
	cout << B << endl;

	fraction C(2, 3);
	cout << C << endl;

	fraction D(2, 3, 4);
	cout << D << endl;
#endif // CONSTRACTORS_CHEK
 
#ifdef HOME_WOR
	fraction A(1, 2, 3);
	fraction B(3, 4, 5);
	fraction C = A * B;
	cout << C << endl;
	cout << A / B << endl;
	cout << A + B << endl;
	cout << A - B << endl;
	for (double i = 0.25; i < 10; i++)cout << i << tab;
	cout << endl;
	
	cout << (A += B) << endl;
	cout << endl;
	cout << (A -= B) << endl;
	cout << endl;
	cout << (A *= B) << endl;
	cout << endl;
	cout << (A /= B) << endl;
	cout << endl;
fraction A(3,4);
	fraction B(1,2, 4); 
	cout <<  (A > B )<< endl;
for (fraction i(3, 4); i < 10;++ i)
		cout << i << "\t";
	cout << endl;
#endif // HOME_WOR
#ifdef COMPARISSON_OPERATORS_CHECK
	/*fraction A(1, 2);
fraction B(5, 10);
if (A == B)cout << "Дроби равны.";
else cout << "Дроби разные.";*/
	cout << (fraction(1, 2) < fraction(5, 9)) << endl;
#endif // COMPARISSON_OPERATORS_CHECK

#ifdef CONVERSIONS_BASICS
	// (type)value C-like notation (C_подобная форма записи)
// tape(valye) Function notation(Функциональная форма записи)
//cout << ( double)8 / 5 << endl;
	int a = 2;    // No conversion
	double b = 3; // Conversion from less to more.
	int c = b;    // Conversion from more to less with data loss.
	int d = 2.5;  // Conversion from more to less with data loss.
	cout << d << endl;
#endif // CONVERSIONS_BASICS

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	fraction A = fraction(5); // Conversion from int to fraction
	cout << A << endl;
	cout << delimetr << endl;
	fraction B;
	cout << delimetr << endl;
	B = fraction(8);
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS
#ifdef CONVERSION_FROM_CLASS_TO_OTHER_TYPES
	fraction A(2, 3, 0);
	int a =(int) A;
	cout << a << endl;
	cout << A << endl;

	double b = (double)A;
	cout << b << endl;

	fraction B = 2.8;
	cout << B << endl;

	//cout << 0.1 + 0.3 << endl;

#endif // CONVERSION_FROM_CLASS_TO_OTHER_TYPES
#ifdef HOME_WORK
	fraction A;
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
#endif // HOME_WORK

 
}