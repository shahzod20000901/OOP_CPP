#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"

class Fraction
{
	double x;
public:
	double get_x()const
	{
		return x;
	}

	void set_x(double x)
	{
		this->x = x;
	}

	Fraction(double x=0)
	{
		this->x = x;
		cout << "Constructor: " << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->x = other.x;
		cout << "CopyConstructor: " << this << endl;
	}

	Fraction operator/(const Fraction& other)  //11/4 => 2(3/4)
	{
		double value = this->x / other.x;
		double value_1 = this->x - (int)value * other.x;
		cout << this->x << "/" << other.x << "=>" << (int)value << "(" << (int)value_1 << "/" << other.x <<")"<< endl;
		cout << (int)value << "(" << (int)value_1 << "/" << other.x << ")"<<"=>"<< (int)value * other.x + (int)value_1 << "/" << other.x << endl;
		return value;
	}

	Fraction reduce( Fraction& other)  //5/10=>1/2
	{
		double value = this->x;
		double result = other.x;
		if (value < result)
		{
			while (value % value != 0 && result % value != 0)
			{
				--value;
			}
			this->x /= value;
			other.x /= value;
		}
		else
		{
			while (result % result != 0 && value % result != 0)
			{
				--result;
			}
			this->x /= result;
			other.x /= result;
		}
	}

	~Fraction()
	{
		cout << "Destructor: " << this << endl;
	}
};

istream& operator>>(istream& is, Fraction& obj)
{
	double x;
	is >> x;
	return is;
}

ostream& operator<< (ostream& os, Fraction& obj)
{
	os << obj.get_x() << endl;
	return os;
}

void main()
{
	setlocale(LC_ALL, "");
	Fraction A;
	Fraction B;
	A.set_x(19);
	B.set_x(18);
	Fraction C = A / B;
	cout << C << endl;
}

//TODO:
//Реализовать класс Fraction, описывающий простую дробь. 
//В классе должны быть все обязательные методы, а так же методы:
//	- to_proper();		//Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
//	- to_improper();	//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
//	- reduce();			//Сокращает дробь: 5/10 => 1/2;
//1. Арифметические операторы: +, -, *, /;
//2. Составные присваивания: +=, -=, *=, /=;
//3. Increment/Decrement (++/--);
//4. Операторы сравнения: ==, !=, >, <, >=, <=;
//5. Операторы для работы с потоками: <<, >>