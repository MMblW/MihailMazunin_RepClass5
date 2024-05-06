#pragma once
#include <iostream>
#include <string>

using namespace std;

class Object
{
public:
	Object() {}
	virtual ~Object() {}
	virtual void Show() = 0;
};
