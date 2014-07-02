#include "testclass.h"

Person::Person()
{}

int Person::Add(int a, int b)
{
		c = a+b;
		return 0;
}

int Person::Result(void)
{
		return c;
}
