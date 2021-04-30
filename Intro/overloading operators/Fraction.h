#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define HOME_WORK
//#define TYPE_CONVERSIONS
class Fraction;

//4. Операторы сравнения: ==, !=, >, <, >=, <=;
bool operator==(const Fraction& left, const Fraction& right);

bool operator!=(const Fraction& left, const Fraction& right);

bool operator>(const Fraction& left, const Fraction& right);

bool operator<(const Fraction& left, const Fraction& right);

bool operator>=(const Fraction& left, const Fraction& right);

bool operator<=(const Fraction& left, const Fraction& right);

//5. Операторы для работы с потоками : << , >>
istream& operator>>(istream& is, Fraction& obj);

ostream& operator<< (ostream& os, Fraction& obj);

class Fraction
{
	int x;
	int y;
public:
	int get_x()const;
	int get_y()const;
	void set_x(int x);
	void set_y(int y);
	Fraction();
	explicit Fraction(int x);

	Fraction(int x, int y);
	Fraction operator=(Fraction& other);

	//1. Арифметические операторы: +, -, *, /;
	Fraction operator+(Fraction& other);
	Fraction operator-(Fraction& other);
	Fraction operator*(Fraction& other);
	Fraction operator/(Fraction& other);

	//2. Составные присваивания: +=, -=, *=, /=;
	Fraction& operator+=(Fraction& other);

	Fraction& operator-=(Fraction& other);

	Fraction& operator*=(Fraction& other);

	Fraction& operator/=(Fraction& other);

	//	- to_proper();		//Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
	void to_proper(Fraction&);

	//	- to_improper();	//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
	void to_improper(Fraction&);

	//	- reduce();			//Сокращает дробь: 5/10 => 1/2;
	void reduce(Fraction&);

	//3. Increment/Decrement (++/--);  
	Fraction& operator++();

	Fraction operator++(int);

	Fraction& operator--();

	Fraction operator--(int);

	// type cast operators:
	explicit operator int()const;

	explicit operator double()const;

	operator char()const;

	void print();
	~Fraction();
};
