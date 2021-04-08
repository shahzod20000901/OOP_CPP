#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

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
	Fraction(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: " << this << endl;
	}
	Fraction operator=(Fraction& other)
	{
		this->x = other.x;
		this->y = other.y;
		return *this;
	}

	//1. Арифметические операторы: +, -, *, /;
	Fraction operator+(Fraction& other) //Сумма дробов 3/4+2/5=23/20
	{
		Fraction result;
		result.set_x(this->x * other.y + other.x * this->y);
		result.set_y(this->y * other.y);
		return result;
	}
	Fraction operator-(Fraction& other)   //Разница дробов 3/4-2/5=7/20
	{
		Fraction result;
		result.set_x(this->x * other.y - other.x * this->y);
		result.set_y(this->y * other.y);
		return result;
	}
	Fraction operator*(Fraction& other) // Умножение дробей
	{
		Fraction result;
		result.set_x(this->x * other.x);
		result.set_y(this->y * other.y);
		return result;
	}
	Fraction operator/(Fraction& other)  //Деление дробей
	{
		Fraction result;
		result.set_x(this->x * other.y);
		result.set_y(this->y * other.x);
		return result;
	}

	//2. Составные присваивания: +=, -=, *=, /=;
	Fraction& operator+=(Fraction& other)
	{
		this->set_x(this->x * other.y + other.x * this->y);
		this->set_y(this->y * other.y);
		return *this;
	}

	Fraction& operator-=(Fraction& other)
	{
		this->set_x(this->x * other.y - other.x * this->y);
		this->set_y(this->y * other.y);
		return *this;
	}

	Fraction& operator*=(Fraction& other) 
	{
		this->set_x(this->x *other.x);
		this->set_y(this->y * other.y);
		return *this;
	}

	Fraction& operator/=(Fraction& other) 
	{
		this->set_x(this->x * other.y);
		this->set_y(this->y * other.x);
		return *this;
	}

	//	- to_proper();		//Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
	void to_proper(Fraction&)  //11/4 => 2(3/4)
	{
		double value = this->x / this->y;
		double value_1 = this->x - (int)value * this->y;
		cout << this->x << "/" << this->y << "=>" << (int)value << "(" << (int)value_1 << "/" << this->y << ")" << endl;
	}

	//	- to_improper();	//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
	void to_improper(Fraction&)  // 2(3/4)=>11/4 
	{
		double value = this->x / this->y;
		double value_1 = this->x - (int)value * this->y;
		cout << (int)value << "(" << (int)value_1 << "/" << this->y << ")" << "=>" << this->x << "/" << this->y <<  endl;
	}

	//	- reduce();			//Сокращает дробь: 5/10 => 1/2;
	void reduce(Fraction&)  //  6/8=>3/4
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
	Fraction& operator++()  //Prefix
	{
		++this->x;
		++this->y;
		return *this;
	}

	Fraction operator++(int) //Postfix
	{
		Fraction old = *this;
		this->x++;
		this->y++;
		return old;
	}

	Fraction& operator--() //prefix
	{
		--this->x;
		--this->y;
		return *this;
	}

	Fraction operator--(int) //Postfix
	{
		Fraction old = *this;
		this->x--;
		this->y--;
		return old;
	}

	void print()
	{
		cout << this->x << "/" << this->y << endl;
	}
	~Fraction()
	{
		cout << "Destructor: " << this << endl;
	}
};

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

void main()
{
	setlocale(LC_ALL, "Russian");
	Fraction A;
	A.set_x(12);
	A.set_y(18);
	cout << "Правильный дроб: " << A.get_x() << "/" << A.get_y() << endl;
	A.reduce(A);
	Fraction B;
	B.set_x(11);
	B.set_y(4);
	cout << "Неправильный дроб: " << B.get_x() << "/" << B.get_y() << endl;
	B.to_proper(B);
	B.to_improper(B);
	Fraction C= A + B;
	cout << "Дроб А " << A.get_x() << "/" << A.get_y() << endl;
	cout << "Дроб B " << B.get_x() << "/" << B.get_y() << endl;
	cout << "Сумма этих дробов равен: ";
	C.reduce(C);
	Fraction D = B-A;
	cout << "Разница этих дробов равен: ";
	D.reduce(D);
	Fraction E = A * B;
	cout << "Умножение этих дробов равен: ";
	E.reduce(E);
	Fraction F = A / B;
	cout << "Деление этих дробов равен:";
	F.reduce(F);
	cout << "Дроб В присваиваем на дроб А " << endl;
	cout << "+= ";
	A += B; A.reduce(A);
	cout << "-= ";
	A -= B; A.reduce(A);
	cout << "*= ";
	A *= B; A.reduce(A);
	cout << "/= ";
	A /= B; A.reduce(A);
	//++B; B.print(); 
	//B++; B.print();
	//--B; B.print();
	//B--; B.print();
	//cout << (A == B) << endl;
	//cout << (A == A) << endl;
	//cout << (A != B) << endl;
	//cout << (A > B) << endl;
	//cout << (A < B) << endl;
	//cout << (A <= B) << endl;
	//cout << (A <= B) << endl;
	//cin >> A;
	//cout << A << endl;
}