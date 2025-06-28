#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
//#define V
int Nod(int x, int y);


class Fraction
{

private:
	int integer;
	int numerator;//числитель
	int denominator;//знаменатель

public:
	//геттеры
	int get_numerator()const {
		return numerator;
	}
	int get_denominator() {
		return denominator;
	}
	//сеттеры
	void set_numerator() {
		this -> numerator;
	}
	void set_denominator() {
		this->denominator;
	}
	Fraction() {

	}
	Fraction(double decimal)
	{
		//decimal-дес€тичный
		integer = decimal;//не€вное преобразование типов из double в int
		decimal += 1e-10;
		decimal -= integer;
		denominator = 1e+9;// максимально возможное значение числител€(9дес€тичных разр€дов)
		numerator = decimal * denominator;
		reduce();
	}
	Fraction(int numerator, int denominator) {
		this-> numerator = numerator;
		this -> denominator = denominator;
	};
	~Fraction();

	Fraction Fraction_simplification() {
		int nod=Nod(numerator, denominator);
		Fraction result;
		result.numerator/= nod;
		result.denominator/= nod;
		return result;
	}

	Fraction& reduce()
	{
		//сокращаем дробь по алгаритму ≈вклида
		int more, less, rest;
		if (numerator < denominator)
		{
			less = numerator;
			more = denominator;

		}
		else
		{
			less = denominator;
			more = numerator;
		}
		do
		{
			rest = more % less;
			less = rest;
		} while (rest);
		int GSD = more;//GSD- Greatest Common Divisor
		numerator /= GSD;
		denominator /= GSD;
		return *this;
	}
	

	//перегружаем оператор сложени€
	Fraction operator +(const Fraction& other) {
		Fraction result;
		result.denominator = this->denominator * other.denominator;
		result.numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
		return result.Fraction_simplification();
	}

	Fraction operator -(const Fraction& other) {
		Fraction result;
		result.denominator = this->denominator * other.denominator;
		result.numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
		return result.Fraction_simplification();
	}
	
	Fraction operator *(const Fraction& other) {
		Fraction result;
		result.numerator = this->numerator * other.numerator;
		result.denominator = this->denominator * other.denominator;
		return result.Fraction_simplification();
	}
	
	Fraction operator /(const Fraction& other) {
		Fraction result;
		result.numerator = this->numerator * other.denominator;
		result.denominator = this->denominator * other.numerator;
		return result.Fraction_simplification();
	}
	
	void operator =(const Fraction& other) {
		
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	}
	Fraction& operator ++() {
		this->numerator = this->numerator ++ ;
		this->denominator = this->denominator++;
		return *this;
	}
	Fraction& operator --() {
		this->numerator = this->numerator--;
		this->denominator = this->denominator--;
		return *this;
	}

	bool operator <(const Fraction& other) const {
		return (this->numerator * other.denominator) < (other.numerator * this->denominator);
	}
	bool operator >(const Fraction& other)const {
		return (this->numerator * other.denominator) > (other.numerator * this->denominator);
	}
	bool operator ==(const Fraction& other)const {
		return (this->numerator == other.numerator) < (other.denominator== this->denominator);
	}
};
void Print(Fraction& resault);

void main() {
	setlocale(LC_ALL, "");

#ifdef V
	Fraction number_1(2, 3);
	Fraction number_2(1, 3);
	Fraction multiplicat = number_1.operator*(number_2);
	Print(multiplicat);
#endif // V
	Fraction A = 2,75;
	cout << A << endl;
	

}
int Nod(int x, int y) {
	int buffer;
	if (x < y) buffer = x;
	else buffer = y;
	while (x % buffer != 0 || y % buffer != 0) buffer--;
	return buffer;
}
void Print(Fraction& resault) {
	cout << resault.get_numerator() << "/" << resault.get_denominator() << endl;
}
