//Fraction
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
	Fraction& to_improper() //в неправильную дробь
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator); // меняет местами две переменные

		return inverted;
	}
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
		int GCD = more; // Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;

		return *this;
	}
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
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
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

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	/*Fraction product;
	product.set_numerator(left.get_numerator() * right.get_numerator());
	product.set_denominator(left.get_denominator() * right.get_denominator());
	return product;*/

	/*Fraction prod
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	return prod;*/

	return Fraction
	(	left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();// Создаётся временный безымянный объект и сразу же возвращается на место вызова функции
	// Временные безымянные объекты существуют лишь в пределах одного выражения

}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() * right.get_numerator() + right.get_numerator() * left.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	// return left > right || left == right;
	return !(left < right);
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}


//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, " ");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	A.print();

	Fraction B = 5; //Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D; //Copy constructor
	E.print();

	Fraction F;
	F = E;		//Copy assignment
	F.print();
#endif // CONSTRUCTORS_CHECK

	Fraction A(1, 2, 3);
	Fraction B(2, 3, 4);
	Fraction C = A * B;
	A.print();
	B.print();
	C.print();


	Fraction A(-2, 3, 5);
	Fraction B(-5, 6, 7);
	Fraction C = A + B;
	C.print();

	Fraction H(5, 3, 4);
	Fraction I(7, 1, 7);
	Fraction J = H * I;
	J.print();

	Fraction K(7, 2, 3);
	Fraction L(2, 1, 8);
	Fraction M = K / L;
	M.print();

	++K;
	K.print();
	L++;
	L.print();

	Fraction O(5, 3, 4);
	cout << (O == H) << endl;




}