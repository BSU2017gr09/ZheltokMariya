/*������ ����� ������� N ������������������� ���������� ������� �� ���������� �� -N �� N.
�������� ������� ������������ ������ ��������� ������� ������ �� k ���������*/
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
	cout << "������� ���������� ���������, �� ������� ��������: " << endl;
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
		else cout << "������ ����� ������ ��� ����������� ��������� � �������" << endl;
	}
	else cout << "������ ��������� ������" << endl;
	cout << "������ ����� ������������ ������: " << endl;
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
	cout << "������� ���������� ��������� �������: ";
	cin >> N;
	cout << endl;
	arr = new(nothrow) int[N];
	if (arr != 0) {
		initArray(arr, N);
		cout << "������: " << endl;
		printArray(arr, N);
		cout << endl;
		CyclicTransposition(arr, N);
	}
	else cout << "������ ��������� ������" << endl;
	delete[] arr;
	system("pause");
	return 0;
}