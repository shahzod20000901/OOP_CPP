#include<iostream>
using namespace std;
#define tab "\t"

class Point   // тип данных Point
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
	// Constructors
	/*Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		//конструктор с одним параметром создает точку на прямой
		this->x = x;
		this->y = 0;
		cout << "Singleargumentconstructor: " << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copyconstructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//   Operators
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
	}

	// Methods
	void print() const
	{
		cout << "X= " << x << tab << "Y= " << y << endl;
	}
};

//#define STRUCT

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT
	// type name;
	int a;//Обявляем переменную 'a' типа 'int'
	Point A; // обявляем переменную 'A' типа 'Point'
			 // обявляем обьект структуры 'Point'
			 // Создаём экземпляр структуры 'point'
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A; //Создаем указатель на 'Point'
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT

	Point A;
	/*A.set_x(2);
	A.set_y(3);*/
	cout << A.get_x() << tab << A.get_y() << endl;
	A.print();
	Point B(2, 3);
	B.print();
	Point C = 5; //
	C.print();

	Point D = B; // Copy Constructor
	D.print();

	Point E;    //Default constructor
	E = D;     // Copy assigment
	E.print();
}