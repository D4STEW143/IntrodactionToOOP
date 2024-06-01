#include<iostream>
using namespace std;

class String
{
	int size;
	char* str;
public:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Defconstr:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str)+1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++) this->str[i] = str[i];
		cout << "Costructor:\t" << this;

	}

	~String()
	{
		delete[] str;
		cout << "Destr:\t" << this << endl;
	}

	
};

std::ostream

void main()
{
	setlocale(LC_ALL, "");

}