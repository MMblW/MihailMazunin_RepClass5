#include <iostream>
using namespace std;
class Object
{
public:
    virtual void Show() {};
};
class Person : public Object
{
protected:
    string Name;
    int age;
public:
    Person(string a, int b)
    {
        Name = a;
        age = b;
    }
    Person()
    {
        string a = "a";
        int b = 3;
        Name = a;
        age = b;
    }
    ~Person()
    {
        // No dynamic
    }
    void Show()
    {
        cout << endl << Name << " " << age;
    }
    void Set(string a, int b)
    {
        Name = a;
        age = b;
    }
    void operator = (Person a)
    {
        Name = a.Name;
        age = a.age;
    }
    void operator >> (Person a)
    {
        Name = a.Name;
        age = a.age;
    }
    void operator << (Person a)
    {
        cout << endl << Name << " " << age;
    }
};
class Student :public Person
{
    string Subject;
    int Mark;
public:
    Student(string a, int b, string c, int d)
    {
        Name = a;
        age = b;
        Subject = c;
        Mark = d;
    }
    Student()
    {
        string a = "a";
        int b = 0;
        string c = "b";
        int d = 1;
        Name = a;
        age = b;
        Subject = c;
        Mark = d;
    }
    void SetSub(string a, int b)
    {
        Subject = a;
        Mark = b;
    }
    void Show()
    {
        cout << endl << Name << " " << age << endl << Subject << " " << Mark;
        if (Mark < 3)
        {
            Neud();
        }
    }
    void Neud()
    {
        cout << endl << "Otchislen";
    }
};
int main()
{
    Student example("Ivanov", 14, "Mathematics", 3);
    example.Show();

    example.Set("Petrov", 15);
    example.SetSub("OBJ", 2);
    example.Show();

    Student example2("Zubenko", 35, "Inform", 4);
    Person* example3;
    example3 = &example2;
    (*example3).Show();
}