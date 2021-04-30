#include "Fraction.h"

int Fraction::get_x()const
{
	return x;
}
int Fraction::get_y()const
{
	return y;
}
void Fraction::set_x(int x)
{
	this->x = x;
}
void Fraction::set_y(int y)
{
	this->y = y;
	if (y == 0)throw exception("Zero in denominator");  //Бросаем исключение, с сообщение об ошибке
}
Fraction::Fraction() :x(0), y(1)
{
	//this->x = 0;
	//this->set_y(1);
	cout << "Constructor0:\t" << this << endl;
}
Fraction::Fraction(int x) :x(x), y(1)
{
	//this->x = x;
	//this->y = 1;
	cout << "Constructor1:\t" << this << endl;
}

Fraction::Fraction(int x, int y) :x(x), y(y)
{
	//this->x = x;
	//this->set_y(y);
	cout << "Constructor2:\t" << this << endl;
}
Fraction Fraction::operator=(Fraction& other)
{
	this->x = other.x;
	this->y = other.y;
	return *this;
}

//1. Арифметические операторы: +, -, *, /;
Fraction Fraction::operator+(Fraction& other)
{
	Fraction result;
	result.set_x(this->x * other.y + other.x * this->y);
	result.set_y(this->y * other.y);
	return result;
}
Fraction Fraction::operator-(Fraction& other)   //Разница дробов 3/4-2/5=7/20
{
	Fraction result;
	result.set_x(this->x * other.y - other.x * this->y);
	result.set_y(this->y * other.y);
	return result;
}
Fraction Fraction::operator*(Fraction& other) // Умножение дробей
{
	Fraction result;
	result.set_x(this->x * other.x);
	result.set_y(this->y * other.y);
	return result;
}
Fraction Fraction::operator/(Fraction& other)  //Деление дробей
{
	Fraction result;
	result.set_x(this->x * other.y);
	result.set_y(this->y * other.x);
	return result;
}

//2. Составные присваивания: +=, -=, *=, /=;
Fraction& Fraction:: operator+=(Fraction& other)
{
	this->set_x(this->x * other.y + other.x * this->y);
	this->set_y(this->y * other.y);
	return *this;
}

Fraction& Fraction::operator-=(Fraction& other)
{
	this->set_x(this->x * other.y - other.x * this->y);
	this->set_y(this->y * other.y);
	return *this;
}

Fraction& Fraction::operator*=(Fraction& other)
{
	this->set_x(this->x * other.x);
	this->set_y(this->y * other.y);
	return *this;
}

Fraction& Fraction:: operator/=(Fraction& other)
{
	this->set_x(this->x * other.y);
	this->set_y(this->y * other.x);
	return *this;
}

//	- to_proper();		//Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
void Fraction::to_proper(Fraction&)  //11/4 => 2(3/4)
{
	double value = this->x / this->y;
	double value_1 = this->x - (int)value * this->y;
	cout << this->x << "/" << this->y << "=>" << (int)value << "(" << (int)value_1 << "/" << this->y << ")" << endl;
}

//	- to_improper();	//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
void Fraction::to_improper(Fraction&)  // 2(3/4)=>11/4 
{
	double value = this->x / this->y;
	double value_1 = this->x - (int)value * this->y;
	cout << (int)value << "(" << (int)value_1 << "/" << this->y << ")" << "=>" << this->x << "/" << this->y << endl;
}

//	- reduce();			//Сокращает дробь: 5/10 => 1/2;
void Fraction::reduce(Fraction&)  //  6/8=>3/4
{
	double value;
	double result_x = this->x;
	double result_y = this->y;
	if (this->x < this->y)
	{
		value = this->x;
		while ((int)result_x % (int)value != 0 || (int)result_y % (int)value != 0)
		{
			--value;
		}
		cout << this->x << "/" << this->y << "=>" << this->x / value << "/" << this->y / value << endl;
	}
	else if (this->y < this->x)
	{
		value = this->y;
		while ((int)result_x % (int)value != 0 || (int)result_y % (int)value != 0)
		{
			--value;
		}
		cout << this->x << "/" << this->y << "=>" << this->x / value << "/" << this->y / value << endl;
	}
}

//3. Increment/Decrement (++/--);  
Fraction& Fraction::operator++()
{
	//++this->x;
	//++this->y;
	return *this;
}

Fraction Fraction::operator++(int) //Postfix
{
	Fraction old = *this;
	this->x++;
	this->y++;
	return old;
}

Fraction& Fraction::operator--() //prefix
{
	--this->x;
	--this->y;
	return *this;
}

Fraction Fraction::operator--(int) //Postfix
{
	Fraction old = *this;
	this->x--;
	this->y--;
	return old;
}

// type cast operators:
Fraction::operator int()const
{
	return x / y;
}

Fraction::operator double()const
{
	double value = (double)this->x / this->y;
	return value;
}

Fraction::operator char()const
{
	double value = (double)this->x / this->y;
	return value;
}

void Fraction::print()
{
	cout << this->x << "/" << this->y << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor: " << this << endl;
}


//4. Операторы сравнения: ==, !=, >, <, >=, <=;
bool operator==(const Fraction& left, const Fraction& right)
{
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator>(const Fraction& left, const Fraction& right)
{
	double result = left.get_x() / left.get_y();
	double result_1 = right.get_x() / right.get_y();
	if (result > result_1)
		return true;
	else
		return false;
}

bool operator<(const Fraction& left, const Fraction& right)
{
	double result = left.get_x() / left.get_y();
	double result_1 = right.get_x() / right.get_y();
	if (result < result_1)
		return true;
	else
		return false;
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	double result = left.get_x() / left.get_y();
	double result_1 = right.get_x() / right.get_y();
	if (result >= result_1)
		return true;
	else
		return false;
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	double result = left.get_x() / left.get_y();
	double result_1 = right.get_x() / right.get_y();
	if (result <= result_1)
		return true;
	else
		return false;
}

//5. Операторы для работы с потоками : << , >>
istream& operator>>(istream& is, Fraction& obj)
{
	double x, y;
	is >> x >> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}

ostream& operator<< (ostream& os, Fraction& obj)
{
	os << obj.get_x() << "/" << obj.get_y() << endl;
	return os;
}