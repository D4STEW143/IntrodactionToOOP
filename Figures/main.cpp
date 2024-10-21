#include<iostream>
#include<conio.h>
#include"stdlib.h"

using namespace std;

class Figure
{
public:
	virtual int one_side_length() = 0;
	virtual int perimeter() = 0;
	virtual int square() = 0;
	virtual void print() = 0;
};

class Square :public Figure
{
	int side_length, x, y;
public:
	int get_x()const
	{
		return x;
	}
	int get_y()const
	{
		return y;
	}
	int get_side_length()const
	{
		return side_length;
	}
	void set_x(int x)
	{
		this->x = x;
	}
	void set_y(int y)
	{
		this->y = y;
	}
	void set_side_length(int side_length)
	{
		this->side_length = side_length;
	}

	Square()
	{
		cout << "Square are constructed by\t" << this << endl;
	}
	Square(int side_length): Square()
	{
		set_side_length(side_length);
		set_x(side_length);
		set_y(side_length);
	}
	//Square(int x, int y):Square(side_length)
	//{
	//	set_side_length(x);
	//	/*set_side_length(x);
	//	set_x(x);
	//	set_y(y);*/
	//	
	//}
	~Square()
	{
		cout << "Square are destructed by\t" << this << endl;
	}

	int one_side_length()
	{
		return get_side_length();
	}
	int perimeter()
	{
		return (get_x() * 2) + (get_y() * 2);
	}
	int square()
	{
		return get_x() * get_y();
	}
	void print()
	{
		for (int i = 0; i < x; i++)
		{
			cout << "+";
		}
		cout << endl;
		for (int i = 0; i < y - 2; i++)
		{
			cout << "+";
			for (int j = 0; j < x - 2; j++) { cout << " ";}
			cout << "+";
			cout << endl;
		}
		for (int i = 0; i < x; i++)
		{
			cout << "+";
		}
		cout << endl;
	}
};

class Rectangle :public Square
{
	int side_length, x, y;
public:
	int get_x()const
	{
		return x;
	}
	int get_y()const
	{
		return y;
	}
	int get_side_length()const
	{
		return side_length;
	}
	void set_x(int x)
	{
		this->x = x;
	}
	void set_y(int y)
	{
		this->y = y;
	}
	void set_side_length(int side_length)
	{
		this->side_length = side_length;
	}

	Rectangle()
	{
		cout << "Rectangle are constructed by\t" << this << endl;
	}
	Rectangle(int x, int y):Rectangle()
	{
		set_side_length(x);
		set_side_length(x);
		set_x(x);
		set_y(y);
		
	}
	~Rectangle()
	{
		cout << "Rectangle are destructed by\t" << this << endl;
	}

	int one_side_length()
	{
		return get_x(), get_y();
	}
	int perimeter()
	{
		return (get_x() * 2) + (get_y() * 2);
	}
	int square()
	{
		return get_x() * get_y();
	}
	void print()
	{
		Square::print();
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Square sqr1(4);
	cout << sqr1.get_x() << endl;
	sqr1.print();
	Rectangle rec1(9, 4);
	cout << rec1.one_side_length() << endl;
	rec1.print();
}