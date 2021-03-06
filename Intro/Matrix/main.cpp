#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n--------------------------------------------\n"
template<typename T>

class Matrix
{
private:
	int rows;
	int cols;
	T** M;
public:
	int get_rows()const
	{
		return rows;
	}
	int get_cols()const
	{
		return cols;
	}
	const T** get_M()const
	{
		return M;
	}
	Matrix()
	{
		this->rows = 4;
		this->cols = 4;
		this->M = new T* [rows];
		for (int i = 0; i < cols; i++)
		{
			this->M[i] = new T[cols]{};
		}
		cout << "Default Constructor:\t\t" << this << endl;
	}
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
		this->M = new T* [rows];
		for (int i = 0; i < cols; i++)
		{
			this->M[i] = new T[cols]{};
		}
		cout << "Size Constructor:\t\t" << this << endl;
	}
	Matrix(const Matrix& other)
	{
		this->rows = other.rows;
		this->cols = other.cols;
		this->M = new T* [rows];
		for (int i = 0; i < cols; i++)
		{
			this->M[i] = new T[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->M[i][j] = other.M[i][j];
			}
		}
		cout << "Copy Constructor:\t\t" << this << endl;
	}
	//				operators:
	Matrix& operator=(const Matrix& other)
	{
		if (this == &other)return *this;
		for (int i = 0; i < this->rows; i++)delete[] this->M[i];
		delete[] this->M;
		this->rows = other.rows;
		this->cols = other.cols;
		this->M = new T* [rows];
		for (int i = 0; i < cols; i++)
		{
			this->M[i] = new T[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->M[i][j] = other.M[i][j];
			}
		}
		return *this;
	}
	Matrix operator+(const Matrix& other)
	{
		if (this->rows != other.rows || this->cols != other.cols)
		{
			cout << "Размер матрицы разные!!!!"; 
			exit(1);
		}
		Matrix local(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				local.M[i][j] = this->M[i][j] + other.M[i][j];
			}
		}
		return local;
	}

	Matrix& operator+=(Matrix& other)
	{
		return *this = *this + other;
	}

	~Matrix()
	{
		for (int i = 0; i < this->rows; i++)
			delete[] this->M[i];
		delete[]this->M;
		cout << "Destructor:\t\t\t" << this << endl;
	}
	void print()
	{
		cout << "rows:\t" << rows << endl;
		cout << "cols:\t" << cols << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << M[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Rand()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				M[i][j] = rand() % 50;
			}
		}
	}
};


void main()
{
	setlocale(LC_ALL, "Russian");
	Matrix<int> M;
	M.Rand();
	M.print();
	cout << delimiter;
	Matrix<int> M1(5, 6);
	M1.Rand();
	M1.print();
	cout << delimiter;
	Matrix<int> M2 = M1;
	M2.print();
	cout << delimiter;
	Matrix<int> M3;
	M3 = M;
	M3.print();
	cout << delimiter;
	Matrix<int> M4 = M1 + M2;
	M4.print();
	cout << delimiter;
	M4 += M1;
	M4.print();
	cout << delimiter;
}


/*TODO:
1. Разделить класс Fraction на файлы. Сделать это в ветке fraction_separated;
2. Создать проект Academy, в которм реализовать классы Student, Teacher и Graduate (Дипломник)
   Подумать, как сюда применить наследование.

DONE:
1. В новом проекте реализовать класс String, и все необходимые методы в этом классе;
2. В класс String добавить оператор [], и с его помощию упростить оператор +
3. В класс String добавить MoveAssignment;
4. Для класса String перегрузить операторы сравнения;
----------------------------------------------
Реадизовать класс Matrix, описывающий матрицу, 
и обеспечивающий все операции над матрицами:
-determinant()
-operator+
-operator-
-operator*
*/