//� ������� ������� N, ������������ ����.������� �� 0 �� 10, ���������� ������������ ����� ������������������ ������ ���������.
#include <iostream>
#include <ctime>
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

int countMaxLenEqual(int * arr, int size) {
	int i = 0;
	int lenght = 0, max_lenght = 0;
	lenght = 1;
	for (i = 1; i < size; i++) {
		if (*(arr + i) == *(arr + i - 1)) {
			lenght++;
		}
		if ((*(arr + i) != *(arr + i - 1)) || (i == size - 1 )) {
			if (max_lenght < lenght) {
				max_lenght = lenght;
			}
			lenght = 1;
		}
	}
	return max_lenght;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int N = 0;
	int * arr = nullptr;
	cout << "������� ���������� ��������� �������: ";
	cin >> N;
	cout << endl;
	arr = new(nothrow) int[N];
	if (arr != 0) {
		initArray(arr, N);
		cout << "������: " << endl;
		printArray(arr, N);
		cout << endl;
		cout << "������������ ����� ������������������ ������ ���������: " << countMaxLenEqual(arr, N) << endl;
	}
	else cout << "������ ��������� ������" << endl;
	delete[] arr;
	system("pause");
	return 0;
}