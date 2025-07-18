#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimetr "\n---------------------------"
///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////// ќбъ€вление класса

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

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////  онец объ€влени€ класса
