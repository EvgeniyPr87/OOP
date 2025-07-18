#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimetr "\n---------------------------"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS
//#define INCREMENT_DECREMENT
//#define COMPARISON_OPERATORS
//#define ISTREAM_OPERATOR
//#define CONVERSIONS_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER


class Fraction
{
private:
	//		Variables:
	int integer;
	int numerator;
	int denominator;
public:
	//		Realize encapsulation:
	
	//		Getters:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;


	//		Setters:
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//		Constructors:

	Fraction();

	Fraction(int integer);

	Fraction(int numerator, int denominator);

	Fraction(int integer, int numerator, int denominator);

	Fraction(const Fraction& other);

	//		Destructor:

	~Fraction();

	//		Operators:

	Fraction& operator =(const Fraction& other);

	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	//				Increment/Decrement:
	Fraction& operator++();
	Fraction operator++(int);

	//				Type-cast operators:
	operator int()const;
	operator double()const;

	//		Methods
	Fraction& reduce();

	void print()const;

	Fraction& to_improper();

	Fraction& to_proper();

	Fraction inverted()const;
};


//		Getters:
int Fraction:: get_integer()const {
	return integer;
}
int Fraction:: get_numerator()const {
	return numerator;
}
int Fraction:: get_denominator()const {
	return denominator;
}


//		Setters:
void Fraction::set_integer(int integer) {
	this->integer;
}
void Fraction::set_numerator(int numerator) {
	this->numerator;
}
void Fraction::set_denominator(int denominator) {
	if (denominator == 0) denominator = 1;
	this->denominator = denominator;
}


//		Constructors:

Fraction::Fraction() {
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "Default constructor:\t\t" << this << endl;
}

Fraction::Fraction(int integer) {
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "Constructor:\t\t" << this << endl;
}

Fraction:: Fraction(int numerator, int denominator) {
	this->integer = 0;
	this->numerator = numerator;
	this->denominator = denominator;
	cout << "Constructor:\t\t" << this << endl;
}

Fraction::Fraction(int integer, int numerator, int denominator) {
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}

Fraction::Fraction(const Fraction& other) {
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}

//		Destructor:

Fraction::~Fraction() {
	cout << "Destructor\t\t" << this << endl;
};

//		Operators:

Fraction& Fraction:: operator =(const Fraction& other) {
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}

//				Increment/Decrement:
Fraction& Fraction::operator++()	//Prefix increment
{
	integer++;
	return *this;
}
Fraction Fraction::operator++(int)//Postfix increment
{
	Fraction old = *this;
	integer++;
	return old;
}

//				Type-cast operators:
Fraction::operator int()const
{
	return integer + numerator / denominator;
}
Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}

//		Methods
Fraction& Fraction::reduce()
{
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
	int GCD = more;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}

void Fraction::print()const {
	if (integer) cout << integer;
	if (numerator) {
		if (integer) cout << "(";
		cout << numerator << "/" << denominator;
		if (integer) cout << ")";
	}
	else if (integer == 0) cout << 0;
	cout << endl;
}

Fraction& Fraction::to_improper() {
	numerator += integer * denominator;
	integer = 0;
	return *this;
}

Fraction& Fraction::to_proper() {
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}

Fraction Fraction::inverted()const {
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}
Fraction operator *(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	return Fraction(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator /(const Fraction& left, const Fraction& right) {
	return left * right.inverted();
}

Fraction operator+(Fraction& left, Fraction& right) {
	left.to_improper();
	right.to_improper();
	return
		Fraction((left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator()),
		left.get_denominator() * right.get_denominator()).reduce().to_proper();
}

Fraction operator-(Fraction& left, Fraction& right) {
	left.to_improper();
	right.to_improper();
	return
		Fraction((left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()),
			left.get_denominator() * right.get_denominator()).reduce().to_proper();
}

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
	const int SIZE = 32;
	char sz_input[SIZE] = {};
	cin.getline(sz_input, SIZE);
	const char delimiters[] = { '(', '/', ')', ' ', '.', ',', 0 };
	int numbers[3] = {};
	int n = 0;

	
	for (char* pch = strtok(sz_input, delimiters); pch && n < 3; pch = strtok(NULL, delimiters))
		numbers[n++] = atoi(pch);
	
	switch (n)
	{
	case 1:obj = Fraction(numbers[0]); break;
	case 2:obj = Fraction(numbers[0], numbers[1]); break;
	case 3:obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}
	return cin;
}


void main() {

#ifdef CONSTRUCTORS_CHECK
	setlocale(LC_ALL, "");
	Fraction A(1, 2);
	A.print();
	Fraction B(2, 3, 5);
	B.print();
	Fraction C = A;
	C.print();
	Fraction M(2, 8);
	Fraction E = M;
	E.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	Fraction A, B, C;
	cout << delimiter << endl;
	A = B = C = Fraction(2, 3, 4);
	cout << delimiter << endl;
#endif // ASSIGNMENT_CHECK
	
#ifdef ARITHMETICAL_OPERATORS
	Fraction A(1, 2);
	Fraction B(5, 4);
	Fraction C = A * B;
	C.print();
	Fraction E = C.inverted();
	E.print();
	Fraction M = A * B * E;
	M.print();
	Fraction F = B / A;
	F.print();
	cout << delimetr << endl;
	Fraction K = A + B;
	K.print();
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

#ifdef ISTREAM_OPERATOR
	Fraction A;
	cout << "Введите простую дробь: "; cin >> A;
	cout << delimiter << endl;
	cout << A << endl;
	cout << delimiter << endl;
#endif // ISTREAM_OPERATOR

#ifdef CONVERSIONS_BASICS
	//(type)value;	//C-like notation
//type(value);	//Functional notation
//C4244: ... possible loss of data

	int a = 2;		
	double b = 3;	
	int c = b;		
	int d = 4.5;	
#endif // CONVERSIONS_BASICS

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

	Fraction A(2, 3, 4);
	cout << A << endl;

	int a = A;
	cout << a << endl;
	double b = A;
	cout << b << endl;
#endif // CONVERSIONS_FROM_CLASS_TO_OTHER





}