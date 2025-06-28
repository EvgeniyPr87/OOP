#include <iostream>
using namespace std;

#define ASSIGNMENT_CHECK

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}

	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//Constructor
	Point() {
		x = y = 0;
		cout << "DefoltConstructor:/t" << this << endl;
	}
	Point(int x)
	{
		this->x=x;
		this->y=0;
		cout << "Constructor" << this << endl;
	}
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this->x << "\t" << this->y << endl;
	}

	~Point()
	{
			cout << "Destructor:/t/t" << this << endl;
	}

	// Operators:
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
	}

	void print()const
	{
		cout << "X= " << get_x() <<"/t"<< "Y= " << get_y() << endl;
	}

	
	

};
//#define STRUCT_POINT

void main() {
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	Point A
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;

	//вызов конструктора копирования
	Point A(12, 8);
	Point C = A;
	C.print();
#endif // STRUCT_POINT
	int a, b, c;
	a = b = c = 0;
	cout << a<<"\t" << b << "\t" << c << endl;

	Point A, B, C;
	A.print();
	B.print();
	C.print();


	
	
}