#include<Fraction.h>

void main()
{
	setlocale(LC_ALL, "");

	Fraction A(3,5);
	Fraction B(2, 9);
	Fraction F( 1,2);
	Fraction C = A * B;
	Fraction E = A / B;
	A.inverted().print();
	C.print();
	E.print();
	F.print();




}