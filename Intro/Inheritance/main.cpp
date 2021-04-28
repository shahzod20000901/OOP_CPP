#include <iostream>
using namespace std;

class Box
{
	double height;
	double width;
	double depth;
	bool is_open = false;
public:
	double get_height()const
	{
		return height;
	}
	double get_width()const
	{
		return width;
	}
	double get_depth()const
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
		is_open = true;
	}
	void close()
	{
		is_open = false;
	}
	void info()const
	{
		cout << height << "x" << width << "x" << depth << endl;
		cout << (is_open ? "Open" : "Closed") << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	Box box;
	box(2, 3, 4);
	box.open();
	box.close();
	box.info();
}