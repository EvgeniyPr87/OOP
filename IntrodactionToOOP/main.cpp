#include <iostream>
using namespace std;

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
	/*Point() {
		x = y = 0;
		cout << "DefoltConstructor:/t" << this << endl;
	}
	Point(int x)
	{
		this->x=x;
		this->y=0;
		cout << "Constructor" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor" << this << endl;
	}

	~Point()
	{
			cout << "Destructor:/t/t" << this << endl;
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
#endif // STRUCT_POINT
	Point A;
	cout << A.get_x() << "\t" << A.get_y() << endl;
	//A.set_x(10);
	//A.set_y(5);
	Point B=5;
	//cout << B.get_x() << "/t" << B.get_y() << endl;
	A.print();
	B.print();
	Point C(7, 8);
	C.print();
	Point E(18, 0);
	E.print();


}