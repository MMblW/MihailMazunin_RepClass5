#pragma once
#include <iostream>
#include "Object.h"

using namespace std;

class Vector
{
public:
	friend ostream& operator << (ostream& out, const Vector& v)
	{
		if (v.size == 0)
		{
			cout << "Вектор пустой" << endl;
		}
		else
		{
			Object** ptr = v.beg;
			for (int i = 0; i < v.cur; i++)
			{
				(*ptr)->Show();
				ptr++;
			}
		}
		return out;
	}
	Vector()
	{
		beg = 0;
		size = 0;
		cur = 0;
	}
	Vector(int lin)
	{
		beg = new Object * [lin];
		cur = 0;
		size = lin;
	}
	~Vector() {}
	void Add(Object* ptr)
	{
		if (cur < size)
		{
			beg[cur] = ptr;
			cur++;
		}
	}
private:
	Object** beg;
	int size;
	int cur;
};