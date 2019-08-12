#include<iostream>
#include<string>


using namespace std;






class Worker
{

	string name;
	unsigned int age;

public:
	const string& get_name()const
	{
		return this->name;
	}
	unsigned int get_age()const
	{
		return this->age;
	}

	void set_name(string& name)
	{
		this->name = name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//Конструкторы
	Worker(string name, unsigned int age) :name(name), age(age)
	{
		cout << "WConstructor:\t" << this << endl;
	}
	~Worker()
	{
		cout << "WDestructor:\t" << this << endl;
	}
	//Методы
	//Зарплата:
	void cash_back();

};
class HWorker :public Worker
{
	double money;
public:
	//int cash[3]{};//coefficient
	double cash_back()
	{ 
		double money = 20.8 * 8 *150;
		return money;
	}
	HWorker(const string& name, unsigned int age, double cash) :Worker(name, age)
	{

	}
	~HWorker()
	{

	}

};
class FWorker :public Worker
{
	double money;
public:
	double cash_back()
	{
		double money = 20.8 * 8 * 100;
		return money;
	}
	FWorker(const string& name, unsigned int age, double money) :Worker(name, age)
	{

	}
	~FWorker()
	{

	}
};
ostream& operator<<(ostream& os, Worker& obj)
{

	return os << "Name: " << obj.get_name() << " \nYears:" << obj.get_age();
}
ostream& operator<<(ostream& os, HWorker& obj)
{
	os << (Worker&)obj;
	return os << "\nMoney:" << obj.cash_back() << endl;
}
ostream& operator<<(ostream& os, FWorker& obj)
{
	os << (Worker&)obj;
	return os << "\nMoney:" << obj.cash_back() << endl;
}
void main()
{
	setlocale(LC_ALL, "");
	//int cash[3] = { 150,100,75 };
	HWorker Max("Макс", 25, cash[0]);
	FWorker Ira("Ира", 27, 0);
	FWorker Cristy("Кристина", 19, 0);
	HWorker Alex("Саша", 35, cash[1]);
	HWorker W("Виктория Викторовна", 45, cash[2]);
	cout << Max << Ira << Cristy << Alex << W;


}