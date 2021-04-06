#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"

class Fraction
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}

	double get_y()const
	{
		return y;
	}

	void set_x(double x)
	{
		this->x = x;
	}

	void set_y(double y)
	{
		this->y = y;
	}

	Fraction(double x=0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: " << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}

	Fraction operator/(const Fraction& other)  //11/4 => 2(3/4) и 2(3/4) => 11/4    - to_proper();	- to_improper();
	{
		double value = this->x / other.x;
		double value_1 = this->x - (int)value * other.x;
		cout << this->x << "/" << other.x << "=>" << (int)value << "(" << (int)value_1 << "/" << other.x <<")"<< endl;
		cout << (int)value << "(" << (int)value_1 << "/" << other.x << ")"<<"=>"<< (int)value * other.x + (int)value_1 << "/" << other.x << endl;
		return value;
	}

	Fraction operator+(const Fraction& other)
	{
		Fraction result;
		if (this->y == other.y)
		{
			result.set_x(this->x + other.x);
			result.set_y(this->y);
		}
		else if (this->y != other.y)
		{
			result.set_x(this->x * other.y + other.x * this->y);
			result.set_y(this->y * other.y);
		}
		return result;
	}

	Fraction operator-(const Fraction& other)
	{
		Fraction result;
		if (this->y == other.y)
		{
			result.set_x(this->x - other.x);
			result.set_y(this->y);
		}
		else if (this->y != other.y)
		{
			result.set_x(this->x * other.y - other.x * this->y);
			result.set_y(this->y * other.y);
		}
		return result;
	}

	Fraction& reduce(Fraction&)  //5/10=>1/2
	{
		int value = this->x;
		int result =this->y;
		if (value < result)
		{
			while (value % value != 0 || result % value != 0)
			{
				--value;
			}
			this->set_x(this->x /= value);
			this->set_y(this->y /= value);
		}
		else if(result<value)
		{
			while (result % result != 0 || value % result != 0)
			{
				--result;
			}
			this->set_x(this->x /= result);
			this->set_y(this->y /= result);
		}
		return *this;
	}


	void print() const
	{
		cout << x << "/" << y << endl;
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
	os << obj.get_x() <<"/"<<obj.get_y()<< endl;
	return os;
}

void main()
{
	setlocale(LC_ALL, "");
	Fraction A;
	Fraction B;
	A.set_x(19);
	B.set_x(18);
	A.print();
	B.print();
	Fraction C = A / B;
	C.print();
	cout << C << endl;

	Fraction D;
	D.set_x(16);
	D.set_y(26);
	D.print();
	Fraction E;
	E.set_x(4);
	E.set_y(25);
	E.print();
	Fraction F = D + E;
	cout <<F << endl;
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