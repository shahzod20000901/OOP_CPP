#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"

class Point
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

	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: " << tab << this << endl;
	}

	double distance(const Point& other)
	{
		double distance_x = this->x - other.x;
		double distance_y = this->y - other.y;
		double distance = sqrt(distance_x * distance_x + distance_y + distance_y);
		return distance;
	}

	~Point()
	{
		this->x = x;
		this->y = y;
		cout << "Destructor: " << tab << this << endl;
	}
};

double distance(const Point& A, const Point& B);

void main()
{
	setlocale(LC_ALL, "");
	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(4);
	B.set_y(5);
	cout << "Рассстояние между двумя точками: " << distance(A, B) << endl;;

}

double distance(const Point& A, const Point& B)
{
	double distance_x = B.get_x() - A.get_x();
	double distance_y = B.get_y() - A.get_y();
	double distance = sqrt(distance_x * distance_x + distance_y * distance_y);
	return distance;
}

// TODO:
//0. Выучить теорию!!!
//1. В классе Point реализовать МЕТОД ? ? ? distance(? ? ? ), который возвращает расстояние до указанной точки;
//2. Реализовать ФУНКЦИЮ ? ? ? distance(? ? ? ), которая возвращает расстояние между двумя точками;