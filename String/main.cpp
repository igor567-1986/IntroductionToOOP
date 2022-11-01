#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimetr "\n----------------------------------------\n"

class String
{
	size_t size;  //������ ������ � ������
	char* str;    //��������� �� ������ � ������������ ������
public:
	const char* get_str()const
	{
		return str;
	}
   
	const size_t get_size() const
	{
		return size;
	}

	// Constraction
	explicit String(size_t size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "destructor" << endl;
	}
	// Operators
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[]this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator[](char* str)
	{
		 get_str();
		 return *this;
	}
		   
		// Methods:
	void print()const
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
	
};
ostream&  operator <<(ostream& os, const String& obj)
{
		return os << obj.get_str();
}
String operator+ (const String& left, const String& right)
{
	int size = strlen(left.get_str()) + strlen(right.get_str());
	char* buffer = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = left[i];
	}
	return buffer;
}
	
    

//#define CONSTRUCTORS_CHECK
#define OPERATORS_PLUS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;  // ������ ������ �������� 80 ����
	str1.print();
	cout << str1 << endl;

	String str2(22);
	str2.print();

	String str3 = "Hello";
	str3.print();

	String str4 = str3;     //CopyConstructor
	cout << str4 << endl;

	String str5;         //DefaultConstructor
	str5 = str4;         // CopyAssignment
	cout << str5 << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef OPERATORS_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;
#endif // OPERATORS_PLUS_CHECK

}