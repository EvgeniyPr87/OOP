#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class String
{
	int size;
	char* str;

	// реализуем инкапсул€цию
	//Get-методы
public:
	int get_size() const
	{
		return size;
	}
	const char* get_str() const
	{
		return str;
	}

	//создаем конструкторы

	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}

	 String(const char str[])
	{
		size = 0;
		while (str[size++])
		{
			this->str = new char[size] {};
		}
		for (int i = 0; str[i]; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t\t" << this << endl;
}

	//деструктор

	~String()
	{
		delete[]str;
		this->str = nullptr;
		this->size = 0;
		cout << "Destructor:\t\t" << this << endl;
	}

	//методы

	void info()const
	{
		cout << "Size:\t" << size << endl;
		cout<<"Str:\t"<<str<<endl;
	}

};


std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os<<obj.get_str();
}



void main() {

	setlocale(LC_ALL, "");

	String str1(5);
	str1.info();
	cout << str1 << endl;

	String str2 = "Hello";
	str2.info();
}