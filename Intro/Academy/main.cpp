#include <iostream>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//					Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//			Methods:
	void info()
	{
		cout << last_name << " " << first_name << " " << age << " лет" << endl;
	}
};

class student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}

	//		Constructors:
	student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating
	) :Human(last_name, first_name, age)
	{
		this->speciality = speciality;
		this->group = group;
		this->rating = rating;
		cout << "SConstructor:\t" << this << endl;
	}
	~student()
	{
		cout << "Sdestructor:\t" << this << endl;
	}

	//			Methods
	void info()
	{
		Human::info();
		cout << "Специальность:\t" << speciality << "\tгруппа:\t" << group << "\tуспеваемость:\t" << rating << endl;
	}
};

class Graduate :public student
{
	string diploma_theme;
public:
	const string& get_diploma_theme() const
	{
		return diploma_theme;
	}
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& diploma_theme
	) :student(last_name, first_name, age, speciality, group, rating)
	{
		this->diploma_theme = diploma_theme;
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void info()
	{
		student::info();
		cout << "Diploma_theme:\t" << diploma_theme << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human human("тупенко", "Василий", 18);
	human.info();

	student ivan("Остроумный", "Иван", 19, "Китайская философия", "OS_011", 4.9);
	ivan.info();

	Graduate jesse("Pinkman", "Jesse", 20, "Methaphitamine manufacturing", "Withwalter", 4.5, "Methaphitamine distributine");
	jesse.info();
}