#include "String.h"

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