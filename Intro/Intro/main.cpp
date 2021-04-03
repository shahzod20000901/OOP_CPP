#include<iostream>
using namespace std;
using std::cout;
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
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}

	Point& operator+=(const Point& other)
	{
		/*this->x+=other.x;
		this->y+=other.y;*/
		this->set_x(this->x + other.x);
		this->set_y(this->y + other.y);
		return *this;
	}
	Point& operator++()   // Prefix Increment
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int)   // Postfix increment
	{
		Point old = *this;
		this->x++;
		this->y++;
		return old;
	}

	Point& operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}

	// Methods
	void print() const
	{
		cout << "X= " << x << tab << "Y= " << y << endl;
	}
};

bool operator==(const Point& left, const Point& right)
{
	/*if ()
		return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == left.get_y();
}

bool operator!=(const Point& left, const Point& right)
{
	return !(left == right);
}

ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X= " << obj.get_x() << tab << "Y= " << obj.get_y();
	return os;
}

istream& operator>>(istream& is, Point& obj)
{
	double x, y;
	is >> x >> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}

Point operator+(Point left, Point right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

//#define STRUCT
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define STREAMS

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

#ifdef CONSTRUCTORS_CHECK
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
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
#endif // ASSIGMENT_CHECK

#ifdef STREAMS
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(3, 4);
	//A.print();
	//B.print();
	///*Point C = A + B;
	//C.print();*/
	///*A += B;
	//A.print();*/
	//A++;
	//A.print();

	cout << A << endl;
	cout << B << endl;

	cout << "Введите координаты точки: "; cin >> A;
	cout << "Вы ввели: " << A << endl;
#endif // STREAMS

	Point A(2, 3);
	Point B(3, 4);
	/*if (A == B)
	{
		cout << "Точки равны" << endl;
	}
	else
	{
		cout << "Точки разные" << endl;
	}*/
	cout << (A == A) << endl;
	cout << !(A == B) << endl;

	A(33, 44);
	cout << A << endl;
}