#include "String.h"
// ÎÏÐÅÄÅËÅÍÈÅ ÊËÀÑÑÀ -CLASS DEFINITION 
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

std::size_t String::get_size() const
{
	return size;
}

// Constraction
String::String(size_t size) :size(size), str(new char[size] {})
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

ostream& operator <<(ostream& os, const String& obj)
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
// Êîíåö îïðåäåëåíèå êëààñà 