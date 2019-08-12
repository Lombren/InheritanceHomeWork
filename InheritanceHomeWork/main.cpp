#include<iostream>
#include<string>


using namespace std;






class Worker
{

	string name;
	string surname;
	unsigned int age;

public:
	const string& get_name()const
	{
		return this->name;
	}
	const string& get_surname()const
	{
		return this->surname;
	}
	unsigned int get_age()const
	{
		return this->age;
	}

	void set_name(const string& name)
	{
		this->name = name;
	}
	void set_surname(const string& surname)
	{
		this->surname = surname;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//Конструкторы
	Worker(const string& name, const string& surname, unsigned int age) :name(name), age(age)
	{
		set_name(name);
		set_surname(surname);
		set_age(age);
		cout << "WConstructor:\t" << this << endl;
	}
	virtual ~Worker()
	{
		cout << "WDestructor:\t" << this << endl;
	}
	//Методы
	//Зарплата:
	virtual double get_money() const= 0;
	

};
class HWorker :public Worker
{
	double Hsalary;
	int hours;
public:
	
	double get_Hsalary()const
	{
		return this->Hsalary;
	}
	int get_hours()const
	{
		return this->hours;
	}
	void set_Hsalary(double Hsalary)
	{
		this->Hsalary = Hsalary;
	}	
	void set_hours(int hours)
	{
		this->hours = hours;
	}
	HWorker(const string& name, const string& surname, unsigned int age, double Hsalary, int hours=168) :Worker(name, surname, age)
	{
		set_Hsalary(Hsalary);
		set_hours(hours);
		cout << "HConstructor:\t" << this << endl;
	}
	~HWorker()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	double get_money() const
	{
		return Hsalary*hours;
	}

};
class FWorker :public Worker
{
	double salary;
public:
	double get_salary()const
	{
		return this->salary;
	}
	void set_salary(double salary)
	{
		this->salary = salary;
	}
	FWorker(const string& name, const string& surname, unsigned int age, double salary) :Worker(name, surname, age)
	{
		set_salary(salary);
		cout << "FConstructor:\t" << this << endl;
	}
	~FWorker()
	{
		cout << "FDestructor:\t" << this << endl;
	}
	double get_money() const
	{
		return salary;
	}
};
ostream& operator<<(ostream& os, const Worker& obj)
{

	return os << "Name: " << obj.get_name() << "\tSurname: " << obj.get_surname() << " \tYears: " << obj.get_age();
}
ostream& operator<<(ostream& os, const HWorker& obj)
{
	os << (Worker&)obj;
	return os << "\tSalary: " << obj.get_money() << "$ per "<<obj.get_hours()<<" hours";
}
ostream& operator<<(ostream& os, FWorker& obj)
{
	os << (Worker&)obj;
	return os << "\tSalary: " << obj.get_money() << "$";
}
void main()
{
	setlocale(LC_ALL, "");
	
	/*Worker W("Василий", "Лентяй", 40);
	cout << W << endl;*/
	/*FWorker Anton("Antonio", "Montana", 25, 5000);
	cout << Anton << endl;
	HWorker Max("Max", "Volkov", 28, 50,160);
	cout << Max << endl;*/
	
	Worker* department[] =
	{
		new FWorker("Antonio", "Montana", 25, 5000),
		new HWorker("Max", "Volkov", 28, 100),
		new HWorker("James","Cameron",64,200)
	};
	for (int i = 0; i < sizeof(department) / sizeof(Worker*); i++)
	{
		if(typeid(*department[i])==typeid(HWorker))	cout << *(HWorker*)department[i] << endl;
		if(typeid(*department[i])==typeid(FWorker))	cout << *(FWorker*)department[i] << endl;
	}
	
	for (int i = 0; i < sizeof(department) / sizeof(Worker*); i++)
	{
		delete department[i];
	}


}