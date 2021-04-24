#include"String.h"

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHAECK
#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "russian");
#ifdef CONSTRUCTORS_CHECK
	String str;
	str.print();

	String str1 = "Hello";
	str1.print();
	cout << str1 << endl;
	String str2 = str1;
	cout << str2 << endl;

	str = str2;			//Copyassignmet
	cout << str << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHAECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;
#endif // ASSIGNMENT_CHAECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	//cout << delimiter << endl;
	//String str3 = str1 + str2;//operator + будет выполнять конкатенацию 
	//cout << delimiter << endl;
	//str3.print();				// (слияние, обьеденение) строк
	str1 += str2;
	cout << str1 << endl;

	int a = 2;
	int* pa = &a;
	int** ppa = &pa;
	int*** pppa = &ppa;
	cout << **ppa << endl;
#endif // OPERATOR_PLUS_CHECK

	
}