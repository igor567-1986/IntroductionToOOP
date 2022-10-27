#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimetr "\n----------------------------------\n"

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
	fraction(int integer)
	{
		set_integer(integer);
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
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
	return (left * right.inverted()).reduce();
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
fraction operator-(fraction& left, fraction& right)
{
	left.to_improper();
	right.to_improper();
	return fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
	
}

fraction operator+=(fraction left, fraction right) {	return left + right;}
fraction operator-=(fraction left, fraction right) {	return left - right;}
fraction operator*=(fraction left, fraction right) {	return left * right;}
fraction operator/=(fraction left, fraction right) {	return left / right;}

bool operator==(const fraction& left, const fraction& right)
{
	return left.get_integer() == right.get_integer()
		&& left.get_numerator() == right.get_numerator()
		&& left.get_denominator() == right.get_denominator();
}
bool operator!=(const fraction& left, const fraction& right)
{
	return!(left == right);
}
bool operator<(const fraction left, const fraction right)
{
	if (left.get_integer() == right.get_integer())
		return (left.get_numerator() * right.get_denominator()) < (right.get_numerator() * left.get_denominator());
	else return left.get_integer() < right.get_integer();
}
bool operator<=(fraction left,  fraction right)
{
	if (left.get_integer() == right.get_integer())
		return (left.get_numerator() * right.get_denominator()) <= (right.get_numerator() * left.get_denominator());
	else return left.get_integer() <= right.get_integer();
}
bool operator>(const fraction& left, const fraction& right)
{
	if (left.get_integer() == right.get_integer())
		return (left.get_numerator() * right.get_denominator()) > (right.get_numerator() * left.get_denominator());
	else return left.get_integer() > right.get_integer();
}
bool operator>=(const fraction& left, const fraction& right)
{
	if (left.get_integer() == right.get_integer())
		return (left.get_numerator() * right.get_denominator()) <= (right.get_numerator() * left.get_denominator());
	else return left.get_integer() >= right.get_integer();
}


//#define CONSTRACTORS_CHEK
//#define HOME_WOR

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
#endif // HOME_WOR
	fraction A(3,4);
	fraction B(2, 4); 
	cout <<  (A < B )<< endl;
for (fraction i(3, 4); i < 10;++ i)
		cout << i << "\t";
	cout << endl;
}