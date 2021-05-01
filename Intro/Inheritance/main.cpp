#include<iostream>
using namespace std;

class Box
{
private:
	double height;
	double width;
	double depth;
	bool is_open = false;
public:
	const double get_height()const
	{
		return height;
	}
	const double get_width()const
	{
		return width;
	}
	const double get_depth()const
	{
		return depth;
	}
	Box& operator()(double height, double width, double depth)
	{
		this->height = height;
		this->width = width;
		this->depth = depth;
		return *this;
	}
	void open()
	{
		is_open= true;
	}
	void closed()
	{
		is_open = false;
	}
	void info()
	{
		cout << height << "x" << width << "x" << depth << endl;
		cout << (is_open ? "Open" : "closed") << endl;
	}
};

class GiftBox :public Box
{
	string cover;
	string bantik;
	const string& get_cover()const
	{
		return cover;
	}
	const string& get_bantik()const
	{
		return bantik;
	}
	GiftBox(const string& cover, const string& bantik)
	{
		this->cover = cover;
		this->bantik = bantik;
	}
};

void main()
{
	setlocale(LC_ALL, "russian");
	Box box;
	box(2, 3, 4);
	box.open();
	box.closed();
	box.info();
	//GiftBox box1("С котами и мишами", "Зеленый бантик");
}
























//#include <iostream>
//using namespace std;
//
//class Box
//{
//	double height;
//	double width;
//	double depth;
//	bool is_open = false;
//public:
//	double get_height()const
//	{
//		return height;
//	}
//	double get_width()const
//	{
//		return width;
//	}
//	double get_depth()const
//	{
//		return depth;
//	}
//	Box& operator()(double height, double width, double depth)
//	{
//		this->height = height;
//		this->width = width;
//		this->depth = depth;
//		return *this;
//	}
//
//	void open()
//	{
//		is_open = true;
//	}
//	void close()
//	{
//		is_open = false;
//	}
//	void info()const
//	{
//		cout << height << "x" << width << "x" << depth << endl;
//		cout << (is_open ? "Open" : "Closed") << endl;
//	}
//};
//
//class GiftBox: public Box
//{
//	string cover;
//	string bantik;
//public:
//	const string& get_cover()const
//	{
//		return cover;
//	}
//	const string& get_bentik()const
//	{
//		return bantik;
//	}
//};
//
//void main()
//{
//	setlocale(LC_ALL, "Russian");
//	Box box;
//	box(2, 3, 4);
//	box.open();
//	//box.close();
//	box.info();
//	GiftBox box1;
//}