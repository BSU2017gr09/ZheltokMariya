//Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.
#include <iostream>
using namespace std;

void initArray(int * arr, int size) {
	int * end = arr + size;
	for (arr; arr < end; arr++) {
		*arr = rand() % 11;
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

void sortAscend(int * arr, int size, int k) {
	int i = 0, j = 0;
	for (i = k; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (*(arr + i) > *(arr + j)) swap(arr + i, arr + j);
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
	cout << "Введите номер элемента массива, с которого необходимо начать сортировку: " << endl;
	cin >> k;
	if (k >= N) cout << "" << endl;
	else {
		sortAscend(arr, N, k);
		printArray(arr, N);
	}
	freeMemory(arr, N);
	system("pause");
	return 0;
}