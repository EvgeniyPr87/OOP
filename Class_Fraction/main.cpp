#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n-----------------------------"

//прототипы функций:
//class Fraction;
//Fraction& operator*(Fraction left, Fraction right);


class Fraction
{
private:
	int integer;
	int numerator;
	int denomenator;

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denomenator()const
	{
		return denomenator;
	}

	void set_integer(int integer)
	{
		this->integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator;
	}
	void set_denomenator(int denomenator)
	{
		if (denomenator == 0) denomenator = 1;
		this->denomenator = denomenator;
	}

	//			Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denomenator = 1;
		cout << "Default constructor:\t" << this << endl;
	};
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denomenator = 1;
		cout << "constructor:\t\t" << this << endl;
	};
	Fraction(int numerator, int denomenator)
	{
		this->integer = 0;
		this->numerator =numerator;
		this->set_denomenator(denomenator);
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(int integer , int numerator , int denomenator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denomenator(denomenator);
		cout << "Constructor:\t\t" << this << endl;

	};
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denomenator = other.denomenator;
		cout << "CopyConstructor:\t" << this << endl;

	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	};

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denomenator = other.denomenator;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}

	//			Metods:
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denomenator;
			if (integer)cout << ")";

		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	//переводит дробь  в неправильную
	Fraction& to_improper()
	{
		numerator += integer * denomenator;
		integer = 0;
		return *this;
	}

	//переводит дробь в правильную
		Fraction& to_proper()
		{
			integer += numerator / denomenator;
			numerator %= denomenator;
			return *this;
		}
//переворачивает дробь
		Fraction inverted()const
		{
			Fraction inverted = *this;
			inverted.to_improper();
			swap(inverted.numerator, inverted.denomenator);
			return inverted;
		}

		//перегрузка операторов
		Fraction& operator*=(const Fraction& other)
		{
			return *this = *this * other;
		}
		Fraction& operator/(const Fraction& other)
		{
			return *this = *this * other;
		}

		Fraction& operator ++()	//Prefix incriment
		{
			integer++;
			return *this;
		}
		Fraction operator ++(int) //Postfix incriment
		{
			Fraction old = *this;
			integer++;
			return old;
		}
};


//Fraction& operator*(Fraction left, Fraction right){
//	left.to_improper();
//	right.to_improper();
//	return Fraction
//	(
//	left.get_numerator() * right.get_numerator(),
//	left.get_denomenator()* right.get_denomenator()
//	).to_proper();
//}
Fraction operator /(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denomenator();
	right.get_numerator()* right.get_denomenator();

}
bool operator !=(const Fraction& left, const Fraction& right)
	{
		return!(left == right);
	}
std::ostream& operator <<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" <<obj.get_denomenator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARIFMETICAL_OPERATORS
//#define INCREMENT_DECREMENT
//#define COMPARISON_OPERATOR


void main() {
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A; //Default constructor
	A.print();
	Fraction B = 5; //Single argument constructor
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
	Fraction E = C; //CopyConstructor
	E.print();
	Fraction F;
	F = E;			//Copy assigment
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << "\t" << endl;
	Fraction A, B, C;
	cout << delimiter << endl;
	A = B = C = Fraction(2, 3, 4);
	//A = B = C = Fraction(2, 3, 4) явный вызов конструктора, который создает временные безимянные объекты
	//Временные безымянные обьекты существуют в пределах одного выражения
	cout << delimiter << endl;
#endif // ASSIGNMENT_CHECK

#ifdef ARIFMETICAL_OPERATORS
	Fraction A(1, 2);
	Fraction B(2, 3, 4);
	Fraction C = A * B;
	Fraction M = A / B;
	M.print();
	A.print();
	B.print();
	C.print();
	cout << delimiter << endl;
	A *= B;
	A.print();
	B.print();
#endif // ARIFMETICAL_OPERATORS

#ifdef INCREMENT_DECREMENT
	Fraction A(1, 2);
	Fraction B = A++;
	A.print();
	B.print();

#endif // INCREMENT_DECREMENT
#ifdef COMPARISON_OPERATOR

	cout << (Fraction(1, 2) == Fraction(5, 10)) << endl;
	cout << (Fraction(1, 2) != Fraction(5, 10)) << endl;
#endif // COMPARISON_OPERATOR

	Fraction A(1, 2, 3);
	Fraction B(2, 3, 4);
	cout << A ;

}