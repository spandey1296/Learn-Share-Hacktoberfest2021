#include<iostream>
using namespace std;

class base
{
public:
	base()
	{
		cout << "Default constructor of base class " << endl;
	}
	base(int b)
	{
		cout << "Para Constructor of base class " << b << endl;
	}
};

class derived : public base
{
public:
	derived()
	{
		cout << "Default Constructor of Derived Class " << endl;
	}

	derived(int d) : base(d)
	{
		cout << "Para Constructor of Derived Class " << d << endl;
	}
};

int main()
{
	derived d(9);

	return 0;
}