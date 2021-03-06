/*Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования.
Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.*/
#include <iostream>
using namespace std;

void initArray(int * arr, int size) {
	int * end = arr + size;
	for (arr; arr < end; arr++) {
		*arr = rand() % 21 - 10;
	}
}

void printArray(int * arr, int size) {
	int * p = arr;
	for (p; p < arr + size; p++) {
		cout << *p << ' ';
	}
	cout << endl;
}

void swap(int * x, int * y) {
	int z = *y;
	*y = *x;
	*x = z;
}

void sort(int * arr, int size) {
	int i = 0, j = 0;
	int k = 0;
	for (i = size - 1; i >= 0; i--) {
		for (j = i; j >= 0; j--) {
			if ((*(arr + i)) < 0) swap(arr + i, arr + j);
		}
	}
	for (i = 0; i < size; i++) {
		if (*(arr + i) > 0) {
			k = i;
			break;
		}
	}
	for (i = 0; i < k; i++) {
		for (j = i + 1; j < k; j++) {
			if (*(arr + i) < *(arr + j)) swap(arr + i, arr + j);
		}
	}
}

int * giveMemory(int size) {
	int *arr;
	try {
		arr = new int[size];
	}
	catch (...) {
		cout << "Ошибка выделения памяти";
		exit(0);
	}
	return arr;
}

int * freeMemory(int *arr, int size) {
	delete[size] arr;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int N = 0, k = 0;
	int * arr = nullptr;
	cout << "Введите количество элементов массива: ";
	cin >> N;
	cout << endl;
	arr = giveMemory(N);
	initArray(arr, N);
	cout << "Массив: " << endl;
	printArray(arr, N);
	cout << endl;
	sort(arr, N);
	printArray(arr, N);
	freeMemory(arr, N);
	system("pause");
	return 0;
}