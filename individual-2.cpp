/*Симметричную матрицу А(N,N), заданную верхним треугольником в виде одномерного массива относительно главной диагонали,
умножить на вектор В(N). В памяти матрицу не получать.*/
#include <iostream>
#include <iomanip>
using namespace std;
typedef void fff(int * * &arr, int * &a, int * &rez, int M);
typedef fff * pfff;


int * * giveMemoryMatrix(int M) {
	int * * arr = new int *[M];
	for (int i = 0; i < M; i++) {
		try {
			arr[i] = new int[M - i];
		}
		catch (...) {
			exit(0);
		}
	}
	return arr;
}

void freeMemoryMatrix(int * * arr, int M) {
	for (int i = 0; i < M; i++) {
		delete[] arr[i];
	}
}


void initMatrix(int * * arr, int M) {
	int i = 0, j = 0;
	for (i = 0; i < M; i++) {
		if (i <= M / 2) {
			for (j = M - i - 1; j >= i; j--) {
				cout << "Введите элемент матрицы: " << endl;
				cin >> arr[i][j];
			}
		}
	}
}

void Symmetry(int * * arr, int M) {
	int i = 0, j = 0;
	for (i = 0; i < M; i++) {
		for (j = i; j < M - i; j++) {
			arr[j][i] = arr[i][j];
		}
	}
}

void reverseArray(int * a, int M) {
	for (int i = 0; i < M / 2; i++) {
		swap(a[i], a[M - i - 1]);
	}
}

void Reverse(int * * arr, int M) {
	for (int i = 0; i < M; i++) {
		reverseArray(arr[i], M - i);
	}
}

void printMatrix(int * * arr, int M) {
	for (int i = 0; i < M; i++) {
		for (int k = 0; k < i; k++) cout << setw(5) << ' ';
		for (int j = 0; j < M - i; j++) {
			cout << setw(5) << arr[i][j];
		}
		cout << endl;
	}
}

void initArray(int * a, int M) {
	int i = 0;
	for (i = 0; i < M; i++) {
		cout << "Введите координату вектора: " << endl;
		cin >> *(a + i);
	}
}

void printArray(int * a, int M) {
	int * p = a;
	for (p; p < a + M; p++) {
		cout << *p << ' ';
	}
	cout << endl;
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

int * freeMemory(int * arr, int size) {
	delete[size] arr;
	return 0;
}

int * multiplyMatrix(int * * arr, int * a, int * rez, int M) {
	int i = 0, j = 0, k = 0, s = 0;
	for (i = 0; i < M; i++) {
		for (j = 0, k = i; j < M - i, k < M; j++, k++) {
			s += arr[i][j] * a[k];
		}
		rez[i] = s;
		s = 0;
	}
	return rez;
}

void exit(int * * &arr, int * &a, int * &rez, int M) {
	exit(0);
}
void help(int * * &arr, int * &a, int * &rez, int M) {
	cout << "Симметричную матрицу А(N,N), заданную верхним треугольником в виде одномерного массива относительно главной диагонали, умножить на вектор В(N).В памяти матрицу не получать." << endl;
}

void Init(int * * &arr, int * &a, int * &rez, int M) {
	initMatrix(arr, M);
	initArray(a, M);
	Symmetry(arr, M);
	Reverse(arr, M);
}

void outputMatrix(int * * &arr, int * &a, int * &rez, int M) {
	cout << "Матрица: " << endl;
	printMatrix(arr, M);
	cout << endl;
}

void outputArray(int * * &arr, int * &a, int * &rez, int M) {
	cout << "Вектор: " << endl;
	printArray(a, M);
	cout << endl;
}

void Work(int * * &arr, int * &a, int * &rez, int M) {
	rez = multiplyMatrix(arr, a, rez, M);
	cout << "Результат: " << endl;
	printArray(rez, M);
	cout << endl;
}

void forEach(int * * &arr, int * &a, int * &rez, int M, pfff pf) {
	pf(arr, a, rez, M);
}

int main()
{
	setlocale(LC_ALL, "ru");
	int M = 0, n = 0;
	int * * arr = nullptr;
	int * a = nullptr;
	int * rez = nullptr;
	cout << "Введите количество строк матрицы: ";
	cin >> M;
	cout << endl;
	arr = giveMemoryMatrix(M);
	a = giveMemory(M);
	rez = giveMemory(M);
	fff * Fmenu[6] = { exit, help, Init, outputMatrix, outputArray, Work };
	while (1) {
		cout << "Введите номер операции (0 - выход, 1 - вывести условие, 2 - инициализировать матрицу и вектор, 3 - вывести матрицу, 4 - вывести вектор, 5 - получить результат) : " << endl;
		cin >> n;
		forEach(arr, a, rez, M, Fmenu[n]);

	}
	freeMemoryMatrix(arr, M);
	freeMemory(a, M);
	freeMemory(rez, M);
	system("pause");
	return 0;
}