/*Массив чисел размера N проинициализировать случайными числами из промежутка от -N до N.
Написать функцию циклического сдвига элементов массива вправо на k элементов*/
#include <iostream>
#include <ctime>
using namespace std;

void initArray(int * arr, int size) {
	int * end = arr + size;
	for (arr; arr < end; arr++) {
		*arr = rand() % (2*size + 1) - size;
	}
}

void printArray(int * arr, int size) {
	int * p = arr;
	for (p; p < arr + size; p++) {
		cout << *p << ' ';
	}
	cout << endl;
}


void CyclicTransposition(int * arr, int size) {
	int i = 0, k = 0;
	cout << "Введите количество элементов, на которое сдвигаем: " << endl;
	cin >> k;
	int * b = nullptr, *c = nullptr;
	b = new(nothrow) int[size];
	c = new(nothrow) int[size];
	if ((b != 0) && (c != 0)) {
		if (k <= size) {
			for (i = 0; i < size; i++) {
				*(b + i) = *(arr + size - i - 1);
			}
			for (i = 0; i <= k - 1; i++) {
				*(c + i) = *(b + k - i - 1);
			}
			for (i = k; i < size; i++) {
				*(c + i) = *(arr + i - k);
			}
			for (i = 0; i < size; i++) {
				*(arr + i) = *(c + i);
			}
		}
		else cout << "Даннае число больше чем колличество элементов в массиве" << endl;
	}
	else cout << "Ошибка выделения памяти" << endl;
	cout << "Массив после циклического сдвига: " << endl;
	printArray(arr, size);
	delete[] b;
	delete[] c;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int N = 0;
	int * arr = nullptr;
	cout << "Введите количество элементов массива: ";
	cin >> N;
	cout << endl;
	arr = new(nothrow) int[N];
	if (arr != 0) {
		initArray(arr, N);
		cout << "Массив: " << endl;
		printArray(arr, N);
		cout << endl;
		CyclicTransposition(arr, N);
	}
	else cout << "Ошибка выделения памяти" << endl;
	delete[] arr;
	system("pause");
	return 0;
}