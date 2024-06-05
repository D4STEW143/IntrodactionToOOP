#include<iostream>

using namespace std;

class Fraction
{
	int integer;	//целое
	int numerator;  //числитель
	int denominator;//знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//Constructors
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "Default Construct:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "S.A.Construct:\t\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "_Construct:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Construct:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstruct:\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destruct:\t\t" << this << endl;
	}
	//Operators
	//Оператор копирования
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	//Methods
	void print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	Fraction& to_improper() 
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}//в неправильную
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}//в правильную
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator); 

		return inverted;
	}//перевернуть 
	Fraction& reduce()
	{

		int more, less, rest;
		if (numerator > denominator) more = numerator, less = denominator;
		else more = denominator, less = numerator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; 
		numerator /= GCD;
		denominator /= GCD;

		return *this;
	}//сократить через наибольший общий делитель
	Fraction& operator++()
	{
		++integer;
		return *this;
	}
	Fraction& operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	explicit operator int()
	{
		return integer;
	}
	explicit operator double()
	{
		return (integer + ((double)numerator / denominator));
	}


};

Fraction operator+(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction(
		left.get_numerator() + right.get_numerator(),

		).to_proper().reduce();*/
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() * right.get_numerator() + right.get_numerator() * left.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();

}

void main()
{
	setlocale(LC_ALL, "");
	Fraction T1(1, 5, 8);
	Fraction T2(2, 7, 8);
	Fraction Tm = T1 * T2;
	Fraction Tp = T1 + T2;
	Tm.print();
	Tp.print();
}