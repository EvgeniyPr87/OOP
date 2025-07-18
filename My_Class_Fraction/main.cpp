#include"Fraction.h"

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