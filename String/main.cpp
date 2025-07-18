#include<Windows.h>
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class String
{
	int size;//размер строки в байтых
	char* str;//указатель на строку в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	 char* get_str()
	{
		return str;
	}
	//		Constructors
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		size = 0;
		while (str[size++]);
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++) this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		//Конструктор копирования DeepCopy(побитовое копирование)
		//т.е. выделять динамическую память под обьект побитово(поэлементно)
		//копировать содержимое динамической памяти из существующего обьекта в создаваемый

		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;

	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;//защищаем память ще удаления деструктором
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[]str;
		this->str = nullptr;
		this->size = 0;
		cout << "Destructor:\t\t" << this << endl;
	}
	//		Operators

	String& operator=(const String& other) // возвращаем по ссылке, чтобы сэкономит память
	{
		if (this == &other) return *this;
		delete[]this->str; //оператор присваивания должен удалять старое значения
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	String& operator =(String&& other)
	{
		if (this == &other)return *this;
		delete[]this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	 }

	char operator[](int i)const
	{
		return str[i];
	}
	char& operator [](int i)
	{
		return str[i];
}

	//		Methods
	void info()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}

};

String operator +(const String &left, const String right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; left.get_str()[i]; i++)
	{
		result.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; right.get_str()[i]; i++)
	{
		result.get_str()[left.get_size() - 1 + i] = right.get_str()[i];
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator >>(std::istream& cin, String& obj)
{
	const int SIZE = 1024 * 1024; //размер буфера -1Kb
	char buffer[SIZE] = {};
	cin >> buffer;
	obj = buffer;
	return cin;
}
std::istream& getline(std::istream& cin, String& obj)
{
	cin.getline(obj.get_str(), obj.get_size());
	return cin;
}
#define  delimiter "\n----------------------------------"
//#define CONSTRUCTORS_CHECK
#define OPERATOR_PLUS
//#define ISTRIM_OPERATOR

void main() {
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str1(5);//explicid-конструктор нельзя вызват оператором =, но можно вызвать ()
	cout << str1 << endl;
	str1.info();

	String str2 = "Hello";
	str2 = str2;
	cout << str2 << endl;

	String str3 = str2;
	cout << str3 << endl;

	String str4;
	str4 = str3;
	cout << str4 << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef OPERATOR_PLUS

	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1  + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
#endif // OPERATOR_PLUS

#ifdef ISTRIM_OPERATOR
	String str;
	cout << "Введите строку: "; //cin >> str;

	getline(cin, str);
	SetConsoleCP(866);
	cout << str << endl;
#endif // ISTRIM_OPERATOR

}