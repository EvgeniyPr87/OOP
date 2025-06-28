#include<iostream>
#include<cmath>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Point
{
	double x;
	double y;
public:
	//константы. Принимаю за константу начало координат
	const double x0 = 0;//начало координат по оси X
	const double y0 = 0;//начало координат по оси Y
	//создаем геттеры. т.к нужно вернуть значение
	double get_x()const {
		return x;
	}
	double get_y()const {
		return y;
	}
	//создаем конструктор
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	//деструктор
	~Point()
	{};
	//метод для вычисления растояния до точки
public: double distanse(double x, double y) {
	double dist = sqrt(pow(this->x - x0, 2) + pow(this->y - y0, 2));
	return dist;
}
};

//функция вычисления растояния между двумя точками
double distanse(double x_1, double y_1, double x_2, double y_2);


	  void main() {

		  setlocale(LC_ALL, "");
		  // создаем новую точку класса Point
		  Point point_1 (3, 5);
		  //применяем к точке метод distanse
		  double dist = point_1.distanse(point_1.get_x(), point_1.get_y());
		  cout << "Растояние до указанной точки:  "<<dist<<endl;

		  //создадим вторую точку
		  Point point_2(18, 3);
		  //применяем к точке метод distanse
		  double dist_2 = point_2.distanse(point_2.get_x(), point_2.get_y());
		  cout << "Растояние до указанной точки:  " << dist_2 << endl;

		  //вызываем функцию distanse
		  double rast = distanse(point_1.get_x(), point_1.get_y(), point_2.get_x(), point_2.get_y());
		  //double rast = distanse(point_1.distanse(point_1.get_x(), point_1.get_y()), point_2.distanse(point_2.get_x(), point_2.get_y()));
		  cout <<"Растояние между двумя точками: "<< rast;
	  }
 
	   double distanse(double x_1, double y_1, double x_2, double y_2) {
		  double dist = sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2));
		  return dist;
	  }