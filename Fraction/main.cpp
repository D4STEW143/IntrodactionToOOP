#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

class Fraction;
void reduce_numbers(int& numerator, int& denominator);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
private:
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const { return integer; }
	int get_numerator()const { return numerator; }
	int get_denominator()const { return denominator; }

	void set_integer(int integer) { this->integer = integer; }
	void set_numerator(int numerator) { this->numerator = numerator; }
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	// Costructors
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}

	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}

	explicit Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal; // Сохраняем целую часть
		denominator = 1e+9; // INT Полноценно можно использовать только 9 десятичных разрядов
		decimal -= integer; // Убираем целую часть из десятичной дроби
		numerator = decimal * denominator;
		reduce();

	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "2ArgConstructor:\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "3ArgConstructor:\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	// Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
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

	// Methods

	Fraction& to_improper() // Преобразует дробь в неправильную
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



	std::ostream& print(std::ostream& os = std::cout)const
	{
		if (integer) os << integer;
		if (numerator)
		{
			if (integer) os << "(";
			os << numerator << "/" << denominator;
			if (integer) os << ")";
		}
		else if (integer == 0) os << 0;
		//os << endl;
		return os;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce(); // Создаётся временный безымянный объект и сразу же возвращается на место вызова функции
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

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	return obj.print(os);
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 256;
	char sz_buffer[SIZE]{};
	cin >> sz_buffer;

	int n = 0;
	int numbers[3];
	char delimiters[] = "(/)";
	for (char* pch = strtok(sz_buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		numbers[n++] = std::atoi(pch);
	//for (int i = 0; i < n; i++) cout << numbers[i] << "\t"; cout << endl;

	obj = Fraction();

	switch (n)
	{
	case 1: obj.set_integer(numbers[0]);
		break;
	case 2:
		obj.set_numerator(numbers[0]);
		obj.set_denominator(numbers[1]);
		break;
	case 3:
		obj.set_integer(numbers[0]);
		obj.set_numerator(numbers[1]);
		obj.set_denominator(numbers[2]);
		break;
	default:
		obj.set_integer(0);
		obj.set_numerator(0);
		obj.set_denominator(1);
	}

	return is;
}

//#define CHECK_CONSTRUCTORS
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISION_OPERATORS_CHECK
//#define STREAM_CHECK
//#define TYPE_CONVERSION
#define HOME_WORK

void main()
{
	setlocale(LC_ALL, "");

#if defined CHECK_CONSTRUCTORS
	Fraction A; // Default constructor
	A.print();

	Fraction B = 5; // Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D; // Copy constructor
	E.print();

	Fraction F;
	F = E;          // Copy assignment
	F.print();


	// Сложение
	Fraction A(-2, 3, 5);
	Fraction B(-5, 6, 7);
	Fraction C = A + B;
	C.print();

	// Вычитание
	Fraction D(5, 7, 9);
	Fraction E(3, 1, 3);
	Fraction F = D - E;
	F.print();

	// Умножение
	Fraction H(5, 3, 4);
	Fraction I(7, 1, 7);
	Fraction J = H * I;
	J.print();

	// Деление
	Fraction K(7, 2, 3);
	Fraction L(2, 1, 8);
	Fraction M = K / L;
	M.print();

	// ++
	++K;
	K.print();
	L++;
	L.print();

	// --
	Fraction N(1, 3);
	--N;
	N.print();
	N--;
	N.print();

	// +=
	A += B;
	A.print();

	// ==
	Fraction O(5, 3, 4);
	cout << (O == H) << endl;

	// cin
	Fraction P;
	cout << "Введите целое, числитель и знаминатель дробного числа: "; cin >> P;
	cout << endl;
	cout << P;
#endif // CHECK_CONSTRUCTORS

#if defined ARITHMETICAL_OPERATORS_CHECK
	Fraction A(1, 2, 3);
	Fraction B(2, 3, 4);
	//A.to_improper();
	A.print();
	//B.to_proper();
	B.print();

	/*
	Fraction C = A + B;
	C.print();
	C++;
	C.print();
	*/

	A *= B;
	A /= B;
	A.print();
	//B.print();
#endif

#ifdef COMPARISION_OPERATORS_CHECK
	cout << (Fraction(1, 2) < Fraction(5, 2)) << endl;
#endif

#if defined STREAM_CHECK
	Fraction A(1, 2, 3);
	cout << "Введите простую дробь: "; cin >> A;
	A.print();
#endif

#if defined TYPE_CONVERSION

	int a = 2;
	double b = 3;
	int c = b;

	Fraction A = (Fraction)5; // Conversion from 'int' to 'fraction'
	cout << A << endl;

	int d = (int)A;
	cout << d << endl;

	Fraction B;
	B = Fraction(8);
	cout << B << endl;
#endif;

#if defined HOME_WORK

	Fraction A(2, 3, 4);
	double a = (double)A;
	cout << A << "=" << a << endl;
	//cout << a << endl;

	Fraction B = (Fraction)3.845;
	cout << B << endl;



#endif // HOME_WORK

}