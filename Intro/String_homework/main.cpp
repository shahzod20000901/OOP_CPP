#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	String(int size = 60)
	{
		this->size = size;
		this->str = new char[size];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout << (size == 60 ? "Default " : "Size") << "Constructor\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t\t" << this<< endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	//			operators
	String& operator=(const String& other)
	{
		this->size = other.size;
		this->str = new char[size];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		return *this;
	}

	
	void print()
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String local(left.get_size()+right.get_size()-1);
	for (int i = 0; i < left.get_size(); i++)
	{
		local.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		local.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return local;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	String str = "Hello ";
	str.print();
	String str1 = "World";
	str1.print();
	String str2 = str + str1;
	str2.print();
}

/*TODO:
1. ¬ новом проекте реализовать класс String, и все необходимые методы в этом классе;
2. ¬ класс String добавить оператор [], и с его помощию упростить оператор +
3. ¬ класс String добавить MoveAssignment;
4. ƒл€ класса String перегрузить операторы сравнени€;
----------------------------------------------
–еадизовать класс Matrix, описывающий матрицу, 
и обеспечивающий все операции над матрицами:
-determinant()
-operator+
-operator-
-operator*	*/