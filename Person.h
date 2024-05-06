#pragma once
#include <iostream>
#include "Object.h"

using namespace std;
class Person : public Object
{
	friend istream& operator >> (istream& in, Person& p)
	{
		cout << "������� ���" << endl;
		getline(in, p.name);
		cout << "������� �������" << endl;
		(in >> p.age).ignore();
		cout << endl << endl;
		return in;
	}
	friend ostream& operator << (ostream& out, const Person& p)
	{
		cout << "���: " << p.name << endl;
		cout << "�������: " << p.age << endl;
		cout << endl << endl;
		return out;
	}
protected:
	string name;
	int age;
public:
	~Person() {}
	Person()
	{
		name = "";
		age = 0;
	}
	Person(int a, string b)
	{
		name = b;
		age = a;
	}
	Person(const Person& p)
	{
		name = p.name;
		age = p.age;
	}
	string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}
	void setName(string a)
	{
		name = a;
	}
	void setAge(int a)
	{
		age = a;
	}
	Person& operator = (Person& p)
	{
		name = p.name;
		age = p.age;
	}
	void Show() override
	{
		cout << "���: " << endl;
		cout << "�������: " << endl;
	}
};

class Student : public Person
{
	friend istream& operator >> (istream& in, Student& s)
	{
		cout << "������� ���" << endl;
		getline(in, s.name);
		cout << "������� �������" << endl;
		(in >> s.age).ignore();
		cout << "�������: " << endl;
		in >> s.subject;
		cout << "������: " << endl;
		in >> s.mark;
		return in;
	}
	friend ostream& operator << (ostream & out, const Student& s)
	{
		cout << "���: " << s.name << endl;
		cout << "�������: " << s.age << endl;
		cout << "�������: " << s.subject << endl;
		if (s.mark <= 5 || s.mark >= 2)
		{
			out << "������: " << s.mark;
			if (s.mark > 5 || s.mark < 2)
			{
				cout << "������������ ������" << endl;
			}
			if (s.mark == 5)
			{
				cout << "�������� ������" << endl;
			}
			if (s.mark == 4)
			{
				cout << "������� ������" << endl;
			}
			if (s.mark == 3)
			{
				cout << "������������������ ������" << endl;
			}
			if (s.mark == 2)
			{
				cout << "�������������������� ������" << endl;
			}
		}
		return out;
	}
protected:
	string subject;
	int mark;
public:
	~Student() {}
	Student()
	{
		subject = "";
		mark = 2;
	}
	Student(string a, int b)
	{
		subject = a;
		mark = b;
	}
	Student(Student& s)
	{
		subject = s.subject;
		mark = s.mark;
	}
	Student(const string& name, const int& age, const string& subject, const int& mark) : Person(age, name)
	{
		this->setMark(mark);
		this->setSubject(subject);
	}
	Student(const int& age, const string& name, const string& subject, const int& mark) : Student(name, age, subject, mark) {}
	void setMark(const int& a)
	{
		mark = a;
	}
	void setSubject(const string& a)
	{
		subject = a;
	}
	int getMark() const
	{
		return mark;
	}
	string getSubject() const
	{
		return subject;
	}
};
