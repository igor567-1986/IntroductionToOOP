#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimetr "\n----------------------------------------\n"
class String;
String operator+ (const String& left, const String& right);
class String
{
	size_t size;  //Размер строки в байтах
	char* str;    //указатель на строку в динамической памяти
public:
	const char* get_str()const;
	char* get_str();
   
	size_t get_size() const;

	// Constraction
	explicit String(size_t size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);

	~String();
	// Operators
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	char& operator[](int i)const;
	char& operator[](int i);
		   
		// Methods:
	void print()const;
	
};
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

 std::size_t String :: get_size() const
{
	return size;
}

// Constraction
  String :: String(size_t size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str) { cout << "CopyConstructor:" << this << endl; }
String::String(String&& other) :size(other.size), str(other.str)
{
	//Shallow copy:
	/*this->size = other.size;
	this->str = other.str;*/
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}

String::~String()
{
	delete[] this->str;
	cout << "destructor" << this << endl;
}
// Operators
String& String::operator=(const String& other)
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
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[]this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other) { return  *this = *this + other; }
char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

// Methods:
void String::print()const
{
	cout << "size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}

ostream&  operator <<(ostream& os, const String& obj)
{
		return os << obj.get_str();
}
String operator+ (const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

	
    

//#define CONSTRUCTORS_CHECK
#define OPERATORS_PLUS_CHECK
//#define WAYS_TO_CALL_CONSTRACTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;  // Пустая строка размером 80 байт
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
	String str3;
	str3 = str1 + " " + str2;
	cout << str3 << endl;
	str3 = str2;
	cout << str3 << endl;
	str1 += str2;
	cout << str1 << endl;
#endif // OPERATORS_PLUS_CHECK
#ifdef WAYS_TO_CALL_CONSTRACTORS
	String str1;   //DefaultConstructor
	String str2(5); //Single-argument
	String str3 = "Hello"; //Single-argument type 'const char'
	string str4(); //это выражение не создает обьект,а просто обьявляет функцию str4
	// которая не чего не принимает, и возвращает значение типа 'String'
	String str5{};  //явный вызов консруктора по умолчанию
	String str6{ 7 };
	String str7{ " Hello " };
#endif // WAYS_TO_CALL_CONSTRACTORS

}