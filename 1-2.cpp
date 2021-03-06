/*Даны точки плоскости своими координатами в виде двух одномерных массивов.
Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.*/
#include <iostream>
using namespace std;

void initArray(float * arr, int size) {
	float * end = arr + size;
	for (arr; arr < end; arr++) {
		*arr = rand() % 21 / 10.;
	}
}

void printArray(float * arr, int size) {
	float * p = arr;
	for (p; p < arr + size; p++) {
		cout << *p << ' ';
	}
	cout << endl;
}

float countDistance(float x, float y, float a, float b, float c) {
	return abs(a*x + b*y + c) / sqrt(a*a + b*b);
}

void swap(float * x, float * y) {
	float z = *y;
	*y = *x;
	*x = z;
}

void sortDistance(float * X, float * Y, int size, float a, float b, float c) {
	int i = 0, j = 0;
	for (i = 0; i < size; i++) {
		for (j = i; j < size; j++) {
			if (countDistance((*(X + i)), (*(Y + i)), a, b, c) > countDistance((*(X + j)), (*(Y + j)), a, b, c)) {
				swap(X + i, X + j);
				swap(Y + i, Y + j);
			}
		}
	}
}

float * giveMemory(int size) {
	float *arr;
	try {
		arr = new float[size];
	}
	catch (...) {
		cout << "Ошибка выделения памяти";
		exit(0);
	}
	return arr;
}

float * freeMemory(float * arr, int size) {
	delete[size] arr;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int N = 0;
	float a = 0, b = 0, c = 0;
	float * x = nullptr;
	float * y = nullptr;
	cout << "Введите количество точек плоскости: ";
	cin >> N;
	cout << endl;
	x = giveMemory(N);
	y = giveMemory(N);
	initArray(x, N);
	initArray(y, N);
	while (1)
	{
		cout << "Введите коэффициеты прямой a*x+b*y+c=0: " << endl;
		cout << "a=" << endl;
		cin >> a;
		cout << "b=" << endl;
		cin >> b;
		cout << "c=" << endl;
		cin >> c;
		if (a*a + b*b) break;
		else {
			cout << "Данное уравнение не имеет смысла, попробуйте снова: " << endl;
		}
	}
	cout << "Точки: " << endl;
	printArray(x, N);
	cout << endl;
	printArray(y, N);
	cout << endl;
	sortDistance(x, y, N, a, b, c);
	cout << "После сортировки: " << endl;
	printArray(x, N);
	cout << endl;
	printArray(y, N);
	cout << endl;
	freeMemory(x, N);
	freeMemory(y, N);
	system("pause");
	return 0;
}