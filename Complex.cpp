﻿#include <iostream>
using namespace std;

struct Complex
{
public: float r;
public:	float img;
		Complex() :r(0), img(0) { }; 

		Complex(float a, float b) :r(a), img(b) { }; 

		~Complex() { };

		Complex(const Complex &other) { r = other.r; img = other.img; };//почему не в списке инициализации?????

		void operator = (const Complex &other) { this->r = other.r; this->img = other.img; };

		friend ostream &operator << (ostream &mystream, Complex &tmp) {
			if (tmp.img >= 0) mystream << tmp.r << "+" << tmp.img << "i" << endl;
			else mystream << tmp.r << tmp.img << "i" << endl;
			return mystream;
		};

		friend istream &operator >> (istream &input, Complex &tmp) {
			input >> tmp.r;
			input.ignore(); // зачем ???
			
			input >> tmp.img;
			input.ignore();
			return input;
		};

		Complex operator + (const Complex &other) { return Complex(r + other.r, img + other.img); };

		Complex operator * (const Complex &other) { return Complex(r*other.r - img*other.img, r*other.img + img*other.r); };

		Complex operator - (const Complex &other) { return Complex(r - other.r, img - other.img); };

		Complex operator / (const Complex &other) { 
			Complex tmp;
			if (!(other.r && other.img)) {
				cout << "Ошибка! Деление на 0";
				exit(0);
			}
			tmp.r = other.r / (other.r * other.r + other.img * other.img);
			tmp.img = (-1)*other.img / (other.r * other.r + other.img * other.img);
			return Complex(r*tmp.r - img*tmp.img, r*tmp.img + img*tmp.r);	
		};

		float abs() { return sqrt(this->r*this->r + this->img*this->img); };

		bool operator == (const Complex other) {
			if ((r == other.r) && (img == other.img)) return true;
			else return false;
		};

		bool operator != (const Complex &other) {
			if ((r != other.r) && (img != other.img)) return true;
			else return false;
		};

		Complex operator += (const Complex &other) { 
			this->r += other.r;
			this->img += other.img;
			return Complex(r, img); };

		Complex operator *= (const Complex &other) {
			this->r = r*other.r - img*other.img;
			this->img = img*other.img + img*other.r;
			return Complex(r, img);
		};

		Complex operator -= (const Complex &other) {
			this->r -= other.r;
			this->img -= other.img;
			return Complex(r, img);
		};

		Complex operator /= (const Complex &other) {
			Complex tmp;
			if (!(other.r && other.img)) {
				cout << "Ошибка! Деление на 0";
				exit(0);
			}
			tmp.r = other.r / (other.r * other.r + other.img * other.img);
			tmp.img = (-1)*other.img / (other.r * other.r + other.img * other.img);
			this->r = r*tmp.r - img*tmp.img;
			this->img = r*tmp.img + img*tmp.r;
			return Complex(r, img);
		}
};


int main()
{
	setlocale(LC_ALL, "ru");
	Complex A;
	Complex D(1, 1); // работает конструктор с параметрами
	Complex E(2, 2);
	A = D + E;
	cout << A;
	system("payse");
	return 0;
}
