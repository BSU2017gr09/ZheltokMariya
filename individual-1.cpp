//В строке в каждой паре слов поменять слова местами, если длины слов совпадают, иначе заменить их звёздочками.
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;
const int MAX = 255, N = 100, L = 100;
typedef void fff(char *, char [N][L], char [N][L], int);
typedef fff * pfff;


void inputString(char * str, char arrWords[N][L], char Rez[N][L], int k) {
	fflush(stdin);
	cout << "Введите строку (рамер < 255, слов < 100 ): " << endl;
	cin.ignore();
	cin.getline(str, MAX);
}

void printString(char * str, char arrWords[N][L], char Rez[N][L], int k) {
	cout << str << endl;
}

void exit(char * str, char arrWords[N][L], char Rez[N][L], int k) {
	exit(0);
}
void help(char * str, char arrWords[N][L], char Rez[N][L], int k) {
	cout << "В строке в каждой паре слов поменять слова местами, если длины слов совпадают, иначе заменить их звёздочками." << endl;
}

void Words(char * str, char arrWords[N][L], char Rez[N][L], int &k) {
	char separators[] = " ";
	char * p = str;
	int lenght = 0;
	while (*p) {
		p += strspn(p, separators);
		lenght = strcspn(p, separators);
		if (lenght == 0) break;
		strncpy(arrWords[k], p, lenght);
		arrWords[k][lenght] = '\0';
		k++;
		p += lenght;
	}
	if (k>N) k = N;
}

bool isEven(int A)
{
	if (A % 2) return true;
	else return false;
}

void changeWords(char * str, char arrWords[N][L], char Rez[N][L], int k) {
	char a[] = "***";
	int i = 0;
	if (isEven(N)) {
		for (i = 1; i <= k; i += 2) {
			if (strlen(arrWords[i]) == strlen(arrWords[i - 1])) {
				strcat(Rez[i - 1], arrWords[i]);
				strcat(Rez[i], arrWords[i - 1]);
			}
			else {
				strcat(Rez[i - 1], a);
				strcat(Rez[i], a);
			}
		}
	}
	else {
		for (i = 1; i <= k - 1; i += 2) {
			if (strlen(arrWords[i]) == strlen(arrWords[i - 1])) {
				strcat(Rez[i - 1], arrWords[i]);
				strcat(Rez[i], arrWords[i - 1]);
			}
			else {
				strcat(Rez[i - 1], a);
				strcat(Rez[i], a);
			}
		}
		strcat(Rez[i - 1], arrWords[i - 1]);
	}
}

void outputString(char * str, char arrWords[N][L], char Rez[N][L], int k) {
	int i = 0;
	char a[] = " ";
	for (i = 0; i <= k; i++) {
		strcat(Rez[i], a);
	}
	for (i = 1; i <= k; i++) {
		strcat(Rez[0], Rez[i]);
	}
}



void Work(char * str, char arrWords[N][L], char Rez[N][L], int k) {
	Words(str, arrWords, Rez, k);
	changeWords(str, arrWords, Rez, k);
	outputString(str, arrWords, Rez, k);
	printString(Rez[0], arrWords, Rez, k);
	str = { '\0' };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) {
			arrWords[i][j] = '\0';
			Rez[i][j] = '\0';
		}

	}
}

char * giveMemory(int size) {
	char * arr;
	try {
		arr = new char[size];
	}
	catch (...) {
		cout << "Ошибка выделения памяти";
		exit(0);
	}
	return arr;
}

char * freeMemory(char * arr) {
	delete[] arr;
	return 0;
}

void forEach(char * str, char arrWords[N][L], char Rez[N][L], int k, pfff pf) {
	pf(str, arrWords, Rez, k);
}

int main()
{
	setlocale(LC_ALL, ".1251");
	int k = 0, n = 0;
	char * str = nullptr;
	char arrWords[N][L] = { '\0' };
	char Rez[N][L] = { '\0' };
	str = giveMemory(MAX);
	fff * Fmenu[4] = { exit, help, inputString, Work };
	while (1) {
		cout << "Введите номер операции (0 - выход, 1 - вывести условие, 2 - ввести строку, 3 - вывести реультат) : " << endl;
		cin >> n;
		forEach(str, arrWords, Rez, k, Fmenu[n]);
	}
	freeMemory(str);
	system("pause");
	return 0;
}