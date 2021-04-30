#include "Fraction.h"


void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef HOME_WORK
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
	Fraction C = A + B;
	cout << "Дроб А " << A.get_x() << "/" << A.get_y() << endl;
	cout << "Дроб B " << B.get_x() << "/" << B.get_y() << endl;
	cout << "Сумма этих дробов равен: ";
	C.reduce(C);
	Fraction D = B - A;
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
#endif // HOME_WORK

#ifdef TYPE_CONVERSIONS
	//явное преобразование значения 43 в char:
	cout << (char)43 << endl;  //C-like style
	cout << (char)44 << endl;  //Functional style

	// Неявное преобразование:
	int a = 2;
	double b = 3.4;
	cout << a * b << endl;  // Оператор * неявно преобразует переменную "а" в тип double,
							// чтобы вернуть результат double

	//double c = 4;		// От меньшего к большему
	//int d = c;			// От большего к меньшему, без потери данных
	//int e = 2.5;		// От большего к меньшему с потерей данных

	//Fraction A(3, 4);
	//cout << A << endl;
	//int a = (int)A;
	//cout << a << endl;
	//double b = A;
	//cout << b << endl;

	Fraction B = (Fraction)3;     // Implicit conversion from 'int' to 'Fraction'
						// Преобразование значения "3" типа "int" во Fraction 
	cout << B << endl;  //Это преобразование возможно благодаря конструктору с одним параметром

	B.to_proper(B);
	cout << B << endl;
	Fraction D = Fraction(4);  
#endif // TYPE_CONVERSIONS
}