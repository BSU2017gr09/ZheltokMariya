﻿/*Объект  содержит информацию об абонентах междугородной телефонной станции : фамилия и имя абонента, адрес, номер телефона.
a)	Вывести список абонентов по возрастанию номеров телефонов.
b)	Вывести список абонентов дома, адрес которого вводится.
c)	Все номера телефонов, начинающиеся с цифры х, заменить на номера, начинающиеся с цифры y.*/


#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;
const int MAX = 255;
const int SIZE = 100;

class Subscriber {
private: char * surname;
		 char * name;
		 char * street;
		 unsigned int house;
		 unsigned int tel;

public:
	Subscriber() : surname(nullptr), name(nullptr), street(nullptr), house(0), tel(0) { };

	Subscriber(char * sn, char * n, char * st, unsigned int h, unsigned int t) :
		surname(nullptr), name(nullptr), street(nullptr), house(h), tel(t) {
		if (sn != nullptr) {
			try { this->surname = new char[strlen(sn) + 1]; }
			catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
			strcpy(surname, sn);
		}

		if (n != nullptr) {
			try { this->name = new char[strlen(n) + 1]; }
			catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
			strcpy(name, n);
		}

		if (st != nullptr) {
			try { this->street = new char[strlen(st) + 1]; }
			catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
			strcpy(street, st);
		}
	};

	~Subscriber() {
		delete[] surname;
		delete[] name;
		delete[] street;
	};

	Subscriber(const Subscriber &other) :
		surname(nullptr), name(nullptr), street(nullptr), house(other.house), tel(other.tel) {
		if (other.surname != nullptr) {
			try { this->surname = new char[strlen(other.surname) + 1]; }
			catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
			strcpy(surname, other.surname);
		}

		if (other.name != nullptr) {
			try { this->name = new char[strlen(other.name) + 1]; }
			catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
			strcpy(name, other.name);
		}

		if (other.street != nullptr) {
			try { this->street = new char[strlen(other.street) + 1]; }
			catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
			strcpy(street, other.street);
		}
	};

	/* вариант 1. Правильный, но не лучший*/
	/*void operator = (const Subscriber &other) {
	if (this == &other) return;

	delete[] surname;
	try { this->surname = new char[strlen(other.surname) + 1]; }
	catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
	strcpy(surname, other.surname);

	delete[] name;
	try { this->name = new char[strlen(other.name) + 1]; }
	catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
	strcpy(name, other.name);

	delete[] street;
	try { this->street = new char[strlen(other.street) + 1]; }
	catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
	strcpy(street, other.street);

	this->house = other.house;
	this->tel = other.tel;
	};*/

	void my_swap(Subscriber &other) {
		std::swap(surname, other.surname);
		std::swap(name, other.name);
		std::swap(street, other.street);
		std::swap(house, other.house);
		std::swap(tel, other.tel);
	}

	Subscriber& operator = (const Subscriber &other) {
		Subscriber tmp(other);
		my_swap(tmp);
		return *this;
	}

	char * getSurname() { return this->surname; }
	void setSurname(char * str) {
		delete[] surname;
		try { this->surname = new char[strlen(str) + 1]; }
		catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
		strcpy(surname, str);
	};

	char * getName() { return this->name; }
	void setName(char * str) {
		delete[] name;
		try { this->name = new char[strlen(str) + 1]; }
		catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
		strcpy(name, str);
	};

	char * getStreet() { return this->street; }
	void setStreet(char * str) {
		delete[] street;
		try { this->street = new char[strlen(str) + 1]; }
		catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
		strcpy(street, str);
	};

	int getHouse() { return this->house; };
	void setHouse(int h) { this->house = h; };

	int getTel() { return this->tel; };
	void setTel(int t) { this->tel = t; };

	friend ostream &operator << (ostream &myStream, Subscriber &tmp) {
		myStream << tmp.surname << " " << tmp.name << ": " << tmp.street << ", house " << tmp.house << ", tel. " << tmp.tel << endl;
		return myStream;
	};

	friend istream &operator >> (istream &input, Subscriber &tmp) {
		char tt[MAX];

		cout << "Введите фамилию: " << endl;
		fflush(stdin);
		input.getline(tt, MAX);
		tmp.setSurname(tt);

		cout << "Введите имя: " << endl;
		fflush(stdin);
		input.getline(tt, MAX);
		tmp.setName(tt);

		cout << "Введите название улицы: " << endl;
		fflush(stdin);
		input.getline(tt, MAX);
		tmp.setStreet(tt);

		cout << "Введите номер дома: " << endl;
		input >> tmp.house;

		cout << "Ввелите телефон: " << endl;
		input >> tmp.tel;

		return input;
	};
};

typedef void fff(Subscriber *, Subscriber *, int &, char *, char *, int, int, int);
typedef fff * pfff;


void printArray(Subscriber arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i];
	}
}

void swap(Subscriber &x, Subscriber &y) {
	Subscriber tmp = y;
	y = x;
	x = tmp;
}

void sortAscendTel(Subscriber arr[], int size) {
	int i = 0, j = 0;
	for (i; i < size; i++) {
		for (j = i; j < size; j++) {
			if (arr[i].getTel() > arr[j].getTel())
				swap(arr[i], arr[j]);
		}
	}
}

int getFirstDigit(int A)
{
	int i = 0, digit = 0, rez = 0;
	rez = A;
	digit = rez % 10;
	while (rez > 0) {
		i++;
		rez = rez / 10;
		if (rez % 10 == 0) break;
		digit = rez % 10;
	}
	return digit;
}



void inputStreet(char * str) {
	fflush(stdin);
	cout << "Введите название улицы: " << endl;
	cin.ignore();
	cin.getline(str, MAX);
}

void inputSurname(char * str) {
	fflush(stdin);
	cout << "Введите фамилию: " << endl;
	cin.ignore();
	cin.getline(str, MAX);
}

void inputName(char * str) {
	fflush(stdin);
	cout << "Введите имя: " << endl;
	cin.ignore();
	cin.getline(str, MAX);
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



int outputSubFile(Subscriber arr[], const int size) {
	ofstream  fileOut;
	fileOut.open("D:\\subscribers.txt", ios::out | ios::binary);
	if (!fileOut) {
		cout << "Не удалось открыть файл.\n ";
		return 1;
	}
	for (int i = 0; i < size; i++) {
		auto tmpCh = arr[i].getSurname();
		fileOut.write(tmpCh, strlen(tmpCh) + 1);
		tmpCh = arr[i].getName();
		fileOut.write(tmpCh, strlen(tmpCh) + 1);
		tmpCh = arr[i].getStreet();
		fileOut.write(tmpCh, strlen(tmpCh) + 1);
		auto tmp = arr[i].getHouse();
		fileOut.write((char*)&tmp, sizeof(tmp));
		tmp = arr[i].getTel();
		fileOut.write((char*)&tmp, sizeof(int));
	}
	fileOut.close();
	return 0;
}

void inputSubFile(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y) {
	char a[MAX] = {};
	int b;
	int i = 0;
	ifstream fileIn;
	fileIn.open("D:\\subscribers.txt", ios::in | ios::binary);
	if (!fileIn) {
		cout << "Не удалось открыть файл.\n ";
		return;
	}
	while (i < SIZE) {
		if (fileIn) fileIn.getline(a, MAX, '\0');
		else break;
		arr[i].setSurname(a);
		if (fileIn) fileIn.getline(a, MAX, '\0');
		else break;
		arr[i].setName(a);
		if (fileIn) fileIn.getline(a, MAX, '\0');
		else break;
		arr[i].setStreet(a);
		if (fileIn) fileIn.read((char*)&b, sizeof(int));
		else break;
		arr[i].setHouse(b);
		if (fileIn) fileIn.read((char*)&b, sizeof(int));
		else break;
		arr[i].setTel(b);
		i++;
	}
	size = i;
	fileIn.close();
}



void printArray(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y) {
	for (int i = 0; i < size; i++) {
		cout << i << ") " << arr[i];
	}
}

void sortSubTelefons(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y) {
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	sortAscendTel(tmp, size);
	printArray(tmp, size);
}

void getSubStreet(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y) {
	inputStreet(str1);
	int i = 0, j = 0;
	for (i; i < size; i++) {
		if (!stricmp(arr[i].getStreet(), str1)) cout << arr[i];
	}
}

void getSubAddress(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y) {
	inputStreet(str2);
	cout << "Введите номер дома:  " << endl;
	cin >> h;
	int i = 0;
	for (i; i < size; i++) {
		if ((!stricmp(arr[i].getStreet(), str2)) && (h == arr[i].getHouse())) cout << arr[i];
	}
}

void ChangeTel(Subscriber arr[], int size, int x, int y) {
	int * A = nullptr;
	int a = 0, b = 0, i = 0, j = 0, k = 0;
	for (i = 0; i < size; i++) {
		if (getFirstDigit(arr[i].getTel()) != y) {
			a = i;
			b = i;
			break;
		}
	}
	for (i = 0; i < size; i++) {
		if ((getFirstDigit(arr[i].getTel()) == y) && (arr[i].getTel() != arr[a].getTel())) {
			k++;
			a = i;
		}
	}
	try {
		A = new int[k];
	}
	catch (...) {
		cout << "Ошибка выделения памяти";
		exit(0);
	}
	a = b;
	for (j = 0; j < k; j++) {
		for (i = 0; i < size; i++) {
			if ((getFirstDigit(arr[i].getTel()) == y) && (arr[i].getTel() != arr[a].getTel())) {
				A[j] = i;
				a = i;
				break;
			}
		}
	}
	j = 0;
	for (i = 0; i < size; i++) {
		if (getFirstDigit(arr[i].getTel()) == x) {
			arr[i].setTel(arr[A[j]].getTel());
			j++;
			if (j == k) j = 0;
		}
	}
	delete[] A;
}


void changeSubTelefons(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y) {
	cout << "Введите число x: " << endl;
	cin >> x;
	cout << "Введите число y: " << endl;
	cin >> y;
	ChangeTel(arr, size, x, y);
	printArray(arr, size);
	outputSubFile(arr, size);
}


void addSubInput(Subscriber arr[], int &size) {
	size++;
	char * s1 = nullptr;
	s1 = giveMemory(MAX);
	fflush(stdin);
	cout << "Введите фамилию: " << endl;
	cin.ignore();
	cin.getline(s1, MAX);
	arr[size - 1].setSurname(s1);
	delete[] s1;
	char * s2 = nullptr;
	s2 = giveMemory(MAX);
	fflush(stdin);
	cout << "Введите имя: " << endl;
	cin.getline(s2, MAX);
	arr[size - 1].setName(s2);
	delete[] s2;
	char * s3 = nullptr;
	s3 = giveMemory(MAX);
	fflush(stdin);
	cout << "Введите название улицы: " << endl;
	cin.getline(s3, MAX);
	arr[size - 1].setStreet(s3);
	delete[] s3;
	int a = 0, b = 0;
	cout << "Введите номер дома: " << endl;
	while (1) {
		cin >> a;
		if (a > 0) {
			arr[size - 1].setHouse(a);
			break;
		}
		else cout << "Ошибка. Повторите попытку" << endl;
	}
	cout << "Введите телефон: " << endl;
	while (1) {
		cin >> b;
		if ((b > 1000000) && (b < 10000000)) {
			arr[size - 1].setTel(b);
			break;
		}
		else cout << "Ошибка. Повторите попытку" << endl;
	}
}

void addSub(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y) {
	addSubInput(arr, size);
	outputSubFile(arr, size);
}

void editSub(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y) {
	int n = 0, k = 0;
	int a = 0, b = 0;
	char * s1 = nullptr;
	char * s2 = nullptr;
	char * s3 = nullptr;
	cout << "Введите индекс абонента, которого вы хотели бы отредактировать: " << endl;
	cin >> n;
	while (1) {
		cout << "Выбирите номер операции. Отредоктировать: 1 - фамилию, 2 - имя, 3 - название улицы, 4 - номер дома, 5 - номер телефона. Закончить редактирование - 6. " << endl;
		cin >> k;
		if (k == 6) break;
		switch (k) {
		case 1:
			s1 = giveMemory(MAX);
			inputSurname(s1);
			arr[n].setSurname(s1);
			delete[] s1;
			break;
		case 2:
			s2 = giveMemory(MAX);
			inputName(s2);
			arr[n].setName(s2);
			delete[] s2;
			break;
		case 3:
			s3 = giveMemory(MAX);
			inputStreet(s3);
			arr[n].setStreet(s3);
			delete[] s3;
			break;
		case 4:
			cout << "Введите номер дома: " << endl;
			while (1) {
				cin >> a;
				if (a > 0) {
					arr[n].setHouse(a);
					break;
				}
				else cout << "Ошибка. Повторите попытку" << endl;
			}
			break;
		case 5:
			cout << "Введите телефон: " << endl;
			while (1) {
				cin >> b;
				if ((b > 1000000) && (b < 10000000)) {
					arr[n].setTel(b);
					break;
				}
				else cout << "Ошибка. Повторите попытку" << endl;
			}
			break;
		}
	}
	outputSubFile(arr, size);
}

void initArray(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y) {
	size = 10;
	int n = 0;
	char * surnames[] = { "Crawford", "Watkins", "Cobb", "Richardson", "Summers", "Hunt", "Jones", "Weaver", "Ruves", "Bridges" };
	char * names[] = { "Michael", "Elizabeth", "William", "Linda", "Andrew", "Abigail", "Jared", "Dorothy", "Gerald", "Margaret" };
	char * streets[] = { "Oxford Street", "Bond Street", "Regent Street", "Abbey Road", "Downing Street", "Hambury Street", "Bridge Street", "New Kent Road", "Gaunt Street", "Apple Street" };
	int telefons[] = { 3356478, 4567890, 6734567, 5234565, 7278961, 6433456, 9097856, 1237854, 4314351, 3339843 };
	for (int i = 0; i < size; i++) {
		arr[i].setSurname(surnames[i]);
		arr[i].setName(names[i]);
		arr[i].setStreet(streets[rand() % 10]);
		arr[i].setTel(telefons[rand() % 10]);
		arr[i].setHouse(rand() % 100);
	}
	cout << "Хотите сохранить этот список в файл? (0 - нет, 1 - да) " << endl;
	cin >> n;
	if (n == 1)	outputSubFile(arr, size);
}

void inputArray(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y) {
	size = 0;
	int i = 0;
	int n = 0;
	cout << "Введите " << i << "-го абонента:" << endl;
	addSubInput(arr, size);
	i++;
	while (1) {
		cout << "Выбирите операцию: 0 - закончить ввод, 1 - продолжить ввод" << endl;
		cin >> n;
		if (n == 1) {
			cout << "Введите " << i << "-го абонента:" << endl;
			addSubInput(arr, size);
			i++;
		}
		if (n == 0) break;
	}
	cout << "Хотите сохранить этот список в файл? (0 - нет, 1 - да) " << endl;
	cin >> n;
	if (n == 1)	outputSubFile(arr, size);
}


void exit(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y) {
	exit(0);
}

void help(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y) {
	cout << "Объект  содержит информацию об абонентах междугородной телефонной станции : фамилия и имя абонента, адрес, номер телефона. \n a)	Вывести список абонентов по возрастанию номеров телефонов. \n b)	Вывести список абонентов дома, адрес которого вводится. \n c)	Все номера телефонов, начинающиеся с цифры х, заменить на номера, начинающиеся с цифры y." << endl;
}

void forEach(Subscriber arr[], Subscriber tmp[], int &size, char * str1, char * str2, int h, int x, int y, pfff pf) {
	pf(arr, tmp, size, str1, str2, h, x, y);
}



int main()
{
	setlocale(LC_ALL, "russian");
	int N = 0;
	Subscriber station[SIZE];
	Subscriber tmp[SIZE];
	char * street = nullptr;
	char * address = nullptr;
	street = giveMemory(MAX);
	address = giveMemory(MAX);
	int h = 0, x = 0, y = 0;
	int n = 0;

	fff * Fmenu[12] = { exit, help, inputSubFile, inputArray, initArray, printArray, sortSubTelefons, getSubStreet, getSubAddress, changeSubTelefons, addSub, editSub };
	while (1) {
		cout << "\n";
		cout << "Введите номер операции:" << endl;
		cout << "0 - выход" << endl;
		cout << "1 - вывести условие" << endl;
		cout << "2 - прочитать список абонентов из файла" << endl;
		cout << "3 - ввести новый список абонентов" << endl;
		cout << "4 - заполнить список абонентов случайными значениями" << endl;
		cout << "5 - вывести список всех абонентов станции" << endl;
		cout << "6 - вывести список абонентов по возрастанию номеров телефонов" << endl;
		cout << "7 - вывести список абонентов, которые проживают на одной улицы" << endl;
		cout << "8 - вывести список абонентов дома" << endl;
		cout << "9 - все номера телефонов, начинающиеся с цифры х, заменить на номера, начинающиеся с цифры y" << endl;
		cout << "10 - добавить абонента" << endl;
		cout << "11 - отредактировать абонента" << endl;
		cin >> n;
		forEach(station, tmp, N, street, address, h, x, y, Fmenu[n]);
	}
	delete[](street);
	delete[](address);
	system("pause");
	return 0;
}
