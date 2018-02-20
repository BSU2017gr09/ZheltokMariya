//� ������� ������� N, ������������ ����.������� �� 0 �� 10, ���������� ���������� ���������, ������������� ����� ������ ����.
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

int countRepeatNums(int * arr, int size) {
	int i = 0, j = 0;
	int count = 0, amount = 0;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (*(arr + i) == *(arr + j)) count++;
		}
		if (count == 1) {
			amount++;
		}
		count = 0;
	}
	return amount;
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
		cout << "���������� ���������, ������������� ����� ������ ����: " << countRepeatNums(arr, N) << endl;
	}
	else cout << "������ ��������� ������" << endl;
	delete[] arr;
	system("pause");
	return 0;
}