#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimetr "\n---------------------------"

//#define CONSTRUCTORS_CHECK

//Fraction operator *(Fraction left, Fraction right);
//Fraction& operator /(const Fraction& left, const Fraction right);
//class Fraction;

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
	int get_integer()const {
		return integer;
	}
	int get_numerator()const {
		return numerator;
	}
	int get_denominator()const {
		return denominator;
	}


	//		Setters:
	void set_integer(int integer) {
		this->integer;
	}
	void set_numerator(int numerator) {
		this->numerator;
	}
	void set_denominator(int denominator) {
		if (denominator == 0) denominator = 1;
		this->denominator=denominator;
	}


	//		Constructors:

	Fraction() {
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Default constructor:\t\t" << this << endl;
	}

	Fraction(int integer) {
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(int numerator, int denominator) {
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator) {
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(const Fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}

	//		Destructor:

	~Fraction() {
		cout << "Destructor\t\t" << this << endl;
	};

	//		Operators:

	Fraction& operator =(const Fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
	}

	//		Methods:
	void print()const {
		if (integer) cout << integer;
		if (numerator) {
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}

	Fraction& to_improper() {
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper() {
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction inverted()const {
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& to_the_general() {
		numerator += left.numerator * right.denominator;
		denominator*=
	}

};
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




}