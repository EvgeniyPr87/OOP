?#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;		//����� �����
	int numerator;		//���������
	int denominator;	//�����������
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

	//				Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		//decimal - ����������
		decimal += 1e-10;
		integer = decimal;	//������� �������������� ����� �� 'double' � 'int'
		decimal -= integer;
		denominator = 1e+9;	//����������� ��������� �������� ��������� (9 ���������� ��������)
		//e - Exponent (�������� ������� ���������)
		numerator = decimal * denominator;
		reduce();
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
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

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//				Increment/Decrement:
	Fraction& operator++()	//Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)//Postfix increment
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	//				Type-cast operators:
	operator int()const
	{
		return integer + numerator / denominator;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//					Methods:
	Fraction& reduce()
	{
		//https://www.webmath.ru/poleznoe/formules_12_7.php
		int more, less, rest;
		if (numerator < denominator)
		{
			less = numerator;
			more = denominator;
		}
		else
		{
			more = numerator;
			less = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;	//GCD - Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	Fraction& to_improper()
	{
		//��������� ����� � ������������ (����� ����� ����������� � ���������)
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
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

//					Comparison operators:
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
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
	return !(left < right);
	//return left > right || left == right;
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
	//return left < right || left == right;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	//os - Output Stream
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& cin, Fraction& obj)
{
	/*
	------------------
	5
	1/2
	2(3/4)
	3 4/5
	3.4/5
	3,4/5
	------------------
	*/

	const int SIZE = 32;
	char sz_input[SIZE] = {};	//sz_ - String Zero (������, ��������������� �����)
	//is >> sz_input;
	cin.getline(sz_input, SIZE);	//���� ������ � ���������
	//cout << sz_input << endl;
	const char delimiters[] = { '(', '/', ')', ' ', '.', ',', 0 };
	int numbers[3] = {};
	int n = 0;

	/*
	---------------------------
	������� strtok() ��������� ������ �� ������;
	����������� (delimiters) - ��� �������, �� ������� ����� ������ ������;
	������ (tokens) - ��� ��������, ������� ����� ������� �� ������ (��� ��� ��� �� �����������);
	������� strtok() ���������� ��������� �� ��������� �����, ���� ����� �� ������,
	�� ������� ���������� 'nullptr';
	pch - Pointer to Character, �������� ��������� �� ������ ������ ������.
	---------------------------
	*/
	//https://legacy.cplusplus.com/reference/cstring/strtok/
	for (char* pch = strtok(sz_input, delimiters); pch && n < 3; pch = strtok(NULL, delimiters))
		numbers[n++] = atoi(pch);	//https://legacy.cplusplus.com/reference/cstdlib/atoi/
	/*
	---------------------------
	������� atoi() ASCII to Integer, ��������� ������ ASCII-�������, � ���������� ����� �����,
	��������������� ���� ������.
	---------------------------
	*/

	//for (int i = 0; i < n; i++)cout << numbers[i] << "\t"; cout << endl;

	switch (n)
	{
	case 1:obj = Fraction(numbers[0]); break;
	case 2:obj = Fraction(numbers[0], numbers[1]); break;
	case 3:obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}

	return cin;
}

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS
//#define INCREMENT_DECREMENT
//#define COMPARISON_OPERATORS
//#define ISTREAM_OPERATOR
//#define CONVERSIONS_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;			//Default constructor
	A.print();

	Fraction B = 5;		//Single-argument constructor (����������� � ����� ����������)
	B.print();

	Fraction C(1, 2);	//Constructor
	C.print();

	Fraction D(2, 3, 4);//Constructor
	D.print();

	Fraction E = D;		//Copy constructor
	E.print();

	Fraction F;
	F = E;				//Copy assignment
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;

	a = b = c = 0;

	cout << a << "\t" << b << "\t" << c << endl;

	Fraction A, B, C;
	cout << delimiter << endl;
	A = B = C = Fraction(2, 3, 4);
	//Fraction(2, 3, 4); // ����� ����� ������������, ������� ������� ��������� ���������� ������.
	//��������� ���������� ������� ���������� � �������� ������ ���������
	cout << delimiter << endl;
#endif // ASSIGNMENT_CHECK

#ifdef ARITHMETICAL_OPERATORS
	Fraction A(1, 2);
	Fraction B(2, 3, 4);
	Fraction C = A / B;
	A.print();
	B.print();
	C.print();
	cout << delimiter << endl;
	A /= B;
	A.print();
	B.print();
#endif // ARITHMETICAL_OPERATORS

#ifdef INCREMENT_DECREMENT
	Fraction A(1, 2);
	Fraction B = A++;
	A.print();
	B.print();
#endif // INCREMENT_DECREMENT

#ifdef COMPARISON_OPERATORS
	cout << (Fraction(1, 3) <= Fraction(5, 11)) << endl;
#endif // COMPARISON_OPERATORS

	//Fraction A(1, 2, 3);
	//Fraction B(2, 3, 4);

#ifdef ISTREAM_OPERATOR
	Fraction A;
	cout << "������� ������� �����: "; cin >> A;
	cout << delimiter << endl;
	cout << A << endl;
	cout << delimiter << endl;
#endif // ISTREAM_OPERATOR

#ifdef CONVERSIONS_BASICS
	//(type)value;	//C-like notation
//type(value);	//Functional notation
//C4244: ... possible loss of data

	int a = 2;		//No conversions
	double b = 3;	//Implicit conversion from less to more ('int' to 'double')
	int c = b;		//Implicit conversion from more to less without data loss
	int d = 4.5;	//Implicit conversion from more to less with data loss  
#endif // CONVERSIONS_BASICS

	/*
	------------------------------
	1. From other to Class:
		1.1. SingleArgumentConstrictor;
		1.2. Assignment operator (Copy assignment);
	2. From Class to other;
	------------------------------
	*/

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;		//Conversion from less to more
	cout << A << endl;

	Fraction B;
	cout << delimiter << endl;
	B = Fraction(8);
	cout << delimiter << endl;
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
	/*operator type()
{
	....;
	....;
	....;
}*/

	Fraction A(2, 3, 4);
	cout << A << endl;

	int a = A;
	cout << a << endl;
	double b = A;
	cout << b << endl;
#endif // CONVERSIONS_FROM_CLASS_TO_OTHER

	/*int i = 0;
	i += 1;*/

	Fraction A = 2.76;
	cout << A << endl;

}