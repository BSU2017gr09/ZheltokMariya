//Создать класс вектор
#include <iostream>
#include <cmath>
using namespace std;

struct Vector
{
private: float x;
		 float y;
		 float z;
public:	Vector() :x(0), y(0), z(0) { };

		Vector(float a, float b, float c) :x(a), y(b), z(c) { };

		~Vector() { };

		Vector(const Vector &other) { x = other.x; y = other.y; z = other.z; };

		void operator = (const Vector &other) { x = other.x; y = other.y; z = other.z; };

		friend ostream &operator << (ostream &mystream, Vector &tmp) {
			mystream << "(" << tmp.x << ";" << tmp.y << ";" << tmp.z << ")" << endl;
			return mystream;
		};

		friend istream &operator >> (istream &input, Vector &v) {
			input >> v.x;
			//input.ignore();
			input >> v.y;
			//input.ignore();
			input >> v.z;
			//input.ignore();
			return input;
		};

		Vector operator + (const Vector &other) { return Vector(x + other.x, y + other.y, z + other.z); };

		Vector operator * (const float A) { return Vector(x * A, y * A, z * A); };

		Vector operator - (const Vector &other) { return Vector(x - other.x, y - other.y, z - other.z); };

		Vector operator / (const float A) {
			if (!(A)) {
				cout << "Ошибка! Не могу делить на 0" << endl;
				return *this;
			}
			return Vector(x / A, y / A, z / A);
		};

		Vector operator * (const Vector &other) {
			return Vector(y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x);
		};

		float length() { return sqrt(x*x + y*y + z*z); };

		bool operator == (const Vector &other) {
			if ((x == other.x) && (y == other.y) && (z == other.z)) return true;
			else return false;
		};

		bool operator != (const Vector &other) {
			return !(*this == other);
		};

		bool operator > (Vector &other) {
			if ( this->length() > other.length() )return true;
			else return false;
		};

		bool operator < (Vector &other) {
			return !(*this > other);
		};

		bool operator >= (Vector &other) {
			if ((*this > other) || (*this == other)) return true;
			else return false;
		};

		bool operator <= (Vector &other) {
			if ((*this < other) || (*this == other)) return true;
			else return false;
		};

		void operator += (const Vector &other) {
			*this = *this + other;
		};

		/*Vector &operator += (const Vector &other) {   //dummy вариант
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		return *this;
		};*/

		void operator *= (const float A) {
			*this = *this * A;
		};

		/*Vector operator *= (const float A) {   // dummy вариант
		this->x *= A;
		this->y *= A;
		this->z *= A;
		return *this;
		};*/

		void operator *= (const Vector &other) {
			*this = *this * other;
		};

		void operator -= (const Vector &other) {
			*this = *this - other;
		};

		/*Vector &operator -= (const Vector &other) {   //dummy вариант
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		return *this;
		};*/

		void operator /= (const float A) {
			/*			if (!(A)) {
			cout << "Ошибка! Деление на 0";
			exit(0);
			}*/
			//это поверка лишняя так как оператор / уже проверяет на 0
			*this = *this / A;//безопасное действие!!!!!
		};

		/*Vector operator /= (const float A) {   //dummy вариант
		if (!(A)) {
		cout << "Ошибка! Деление на 0";
		exit(0);
		}
		this->x /= A;
		this->y /= A;
		this->z /= A;
		return *this;
		};*/


		float getFirstCoord() { return x; };
		float getSecondCoord() { return y; };
		float getThirdCoord() { return z; };
		void setFirstCoord(float i) { x = i; };
		void setSecondCoord(float j) { y = j; };
		void setThirdCoord(float k) { z = k; };

};

float ScalarProduct(Vector a, Vector b) {
	return a.getFirstCoord()*b.getFirstCoord() + a.getSecondCoord()*b.getSecondCoord() + a.getThirdCoord()*b.getThirdCoord();
};

float angle(Vector a, Vector b) {
	return acos(ScalarProduct(a, b) / (a.length() * b.length()));
};

float VectorProductLength(Vector a, Vector b) {
	return (a.length() * b.length() * sin(angle(a, b)));
};

float Projection(Vector a, Vector b) { return a.length() * cos(angle(a, b)); };

float MixedProduct(Vector a, Vector b, Vector c) {
	return c.getFirstCoord()*(a.getSecondCoord()*b.getThirdCoord() - a.getThirdCoord()*b.getSecondCoord()) + c.getSecondCoord()*(a.getThirdCoord()*b.getFirstCoord() - a.getFirstCoord()*b.getThirdCoord()) + c.getThirdCoord()*(a.getFirstCoord()*b.getSecondCoord() - a.getSecondCoord()*b.getFirstCoord());
};


bool isOrthogonal(Vector a, Vector b) {
	if (!(ScalarProduct(a, b))) return true;
	else return false;
}

bool isCollinear(Vector a, Vector b) {
	if (!(VectorProductLength(a, b))) return true;
	else return false;
}

bool isCoplanar(Vector a, Vector b, Vector c) {
	if (!(MixedProduct(a, b, c))) return true;
	else return false;
}

bool isRight(Vector a, Vector b, Vector c) {
	if (MixedProduct(a, b, c) > 0) return true;
	else return false;
}

bool isLeft(Vector a, Vector b, Vector c) {
	return !(isRight(a, b, c));
}

void swap(Vector * a, Vector * b) {
	Vector c = *b;
	*b = *a;
	*a = c;
}

void printArray(Vector A[], const int size) {
	for (int i = 0; i < size; i++) {
		cout << A[i];
	}
}

void sortArray(Vector A[], const int size) {
	int i = 0, j = 0;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (*(A + i) > *(A + j)) swap(A + i, A + j);
		}
	}
}

void initArray(Vector A[], const int size, int k=0) {
	for (int i = k; i < size; i++) {
		A[i].setFirstCoord((rand() % 100) / 10.);
		A[i].setSecondCoord((rand() % 100) / 10.);
		A[i].setThirdCoord((rand() % 100) / 10.);
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	const int N = 20;
	Vector a, b, c;
	Vector d(1, 1, 1);
	Vector e(2, 2, 2);
	Vector f(3, 3, 3);
	Vector A[N];

	float k = 3.5;

	cout << "Введите первый вектор: " << endl;
	cin >> a;
	cout << "Второй вектор: " << endl;
	cin >> b;

	cout << "Первый вектор: " << a;
	cout << "Второй вектор: " << b;


	cout << "Их сумма: " << a + b;
	cout << "Их разность (от второго отнять первый): " << b - a;
	cout << "Произведение первого вектора на число, равнвое 3.5: " << a * k;
	cout << "Длина первого вектора: " << a.length() << endl;
	cout << "Длина второго вектора: " << b.length() << endl;
	cout << "Их скалярное произведение: " << ScalarProduct(a, b) << endl;
	cout << "Величина угла между векторами: " << angle(a, b) << endl;
	cout << "Их вектороное произведение: " << a * b;
	cout << "Длина их векторного произведения: " << VectorProductLength(a, b) << endl;

	if (isCollinear(a, b)) cout << "Векторы коллинеарны" << endl;
	else cout << "Векторы не коллинеарны" << endl;
	if (isOrthogonal(a, b)) cout << "Векторы перпендикульрны" << endl;
	else {
		cout << "Векторы не перпендикулярны" << endl;
		cout << "Алгебраическая проекция (первого на второй): " << Projection(a, b) << endl;
		cout << "Алгебраическая проекция (второго на первый): " << Projection(b, a) << endl;
	}
	cout << "Третий вектор: " << endl;
	cin >> c;
	cout << "Третий вектор: " << c;
	cout << "Смешанное произведение трёх векторов: " << MixedProduct(a, b, c) << endl;
	if (isCoplanar(a, b, c)) cout << "Векторы компланарны" << endl;
	else cout << "Векторы не компланарны" << endl;
	if (isRight(a, b, c))  cout << "Тройка векторов правая" << endl;
	if (isLeft(a, b, c))  cout << "Тройка векторов левая" << endl;
	A[0] = a;
	A[1] = b;
	A[2] = c;
	cout << "Массив векторов: " << endl;
	initArray(A, N, 3);
	printArray(A, N);
	cout << "Отсортируем вектора по возрастанию длины: " << endl;
	sortArray(A, N);
	printArray(A, N);
	system("pause");
	return 0;
}