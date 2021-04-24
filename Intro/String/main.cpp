#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n-----------------------------------------------------\n"

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;  //Размер строки в байтах
	char* str; //Указатель на строку в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	/*возвращает константный указатель(Нельза изменить значения по адресу)*/
	const char* get_str()const// Показывает что это константный метод
	{
		return str;
	}
	char* get_str()// Показывает что это константный метод
	{
		return str;
	}
	//			Constructors:
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << (size == 80 ? "Default" : "Size") << "Constructor:\t" << this << endl;
	}
	String(const char str[]) :String(strlen(str)+1)
	{
		/*this->size = strlen(str) + 1;
		this->str = new char[size] {};*/ //Это выполнит первый компютер
		for (int i = 0; str[i]; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t\t" << this << endl;
	}

	String(const String& other): String (other.str)
	{
		/*this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}*/
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr; //Указатель на ноль (Null pointer) - указатель в никуда
		cout << "MoveConstructor:\t" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	//			Operators
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	//			Methdos
	void print() const
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return result;
}

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