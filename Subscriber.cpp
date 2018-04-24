/*Объект  содержит информацию об абонентах междугородной телефонной станции : фамилия и имя абонента, адрес, номер телефона.
a)	Вывести список абонентов по возрастанию номеров телефонов.
b)	Вывести список абонентов дома, адрес которого вводится.
c)	Все номера телефонов, начинающиеся с цифры х, заменить на номера, начинающиеся с цифры y.*/


#include <iostream>
#include <cstring>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;
const int MAX = 255;

class Subscriber {
private: char * surname;
		 char * name;
		 char * street;
		 unsigned int house;
		 unsigned int tel;

public:
	Subscriber() : surname(nullptr), name(nullptr), street(nullptr), house(0), tel(0) { };

	Subscriber(char * sn, char * n, char * st, unsigned int h = 0, unsigned int t = 0) : surname(nullptr), name(nullptr), street(nullptr), house(h), tel(t) {
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

	~Subscriber() { delete[] surname; delete[] name; delete[] street; };

	Subscriber(const Subscriber &other) : surname(nullptr), name(nullptr), street(nullptr), house(other.house), tel(other.tel) {

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

	void operator = (const Subscriber &other) {
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
	};

	friend ostream &operator << (ostream &myStream, Subscriber &tmp) {
		myStream << tmp.surname << " " << tmp.name << ": " << tmp.street << ", house " << tmp.house << ", tel. " << tmp.tel << endl;
		return myStream;
	};

	friend istream &operator >> (istream &input, Subscriber &tmp) {
		const int MAX = 255;
		delete[] tmp.surname;
		try { tmp.surname = new char[MAX]; }
		catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
		delete[] tmp.name;
		try { tmp.name = new char[MAX]; }
		catch (...) { cout << "Ошибка выделения памяти"; exit(0); }
		delete[] tmp.street;
		try { tmp.street = new char[MAX]; }
		catch (...) { cout << "Ошибка выделения памяти"; exit(0); }


		cout << "Введите фамилию: " << endl;
		fflush(stdin);
		cin.getline(tmp.surname, MAX);

		cout << "Введите имя: " << endl;
		fflush(stdin);
		cin.getline(tmp.name, MAX);

		cout << "Введите название улицы: " << endl;
		fflush(stdin);
		cin.getline(tmp.street, MAX);

		cout << "Введите номер дома: " << endl;
		input >> tmp.house;
		input.ignore();

		cout << "Ввелите телефон: " << endl;
		input >> tmp.tel;
		input.ignore();

		return input;
	};

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
};

typedef void fff(Subscriber *, Subscriber *, const int, char *, char *, int, int, int);
typedef fff * pfff;

void initArray(Subscriber arr[], const int size) {
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
}

void printArray(Subscriber arr[], const int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i];
	}
}

void swap(Subscriber &x, Subscriber &y) {
	Subscriber z = y;
	y = x;
	x = z;
}

void sortAscendTel(Subscriber arr[], const int size) {
	int i = 0, j = 0;
	for (i; i < size; i++) {
		for (j = i; j < size; j++) {
			if (arr[i].getTel() > arr[j].getTel())
				swap(arr[i], arr[j]);
		}
	}
}


int getDigit(int A)
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

void printArray(Subscriber arr[], Subscriber tmp[], const int size, char * str1, char * str2, int h, int x, int y) {
	for (int i = 0; i < size; i++) {
		cout << arr[i];
	}
}

void sortSubTelefons(Subscriber arr[], Subscriber tmp[], const int size, char * str1, char * str2, int h, int x, int y) {
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	sortAscendTel(tmp, size);
	printArray(tmp, size);
}


void getSubStreet(Subscriber arr[], Subscriber tmp[], const int size, char * str1, char * str2, int h, int x, int y) {
	inputStreet(str1);
	int i = 0, j = 0;
	for (i; i < size; i++) {
		if (!stricmp(arr[i].getStreet(), str1)) cout << arr[i];
	}
}

void getSubAddress(Subscriber arr[], Subscriber tmp[], const int size, char * str1, char * str2, int h, int x, int y) {
	inputStreet(str2);
	cout << "Введите номер дома:  " << endl;
	cin >> h;
	int i = 0;
	for (i; i < size; i++) {
		if ((!stricmp(arr[i].getStreet(), str2)) && (h == arr[i].getHouse())) cout << arr[i];
	}
}

void ChangeTel(Subscriber arr[], const int size, int x, int y) {
	int a = 0, i = 0, j = 0, k = 0;
	for (i = 0; i < size; i++) {
		if (getDigit(arr[i].getTel()) == y) k++;
	}

	for (i = 0; i < size; i++) {
		if (getDigit(arr[i].getTel()) == x) {
			if (k <= 0) {
				for (j = 0; j < size; j++) {
					if (getDigit(arr[j].getTel()) == y) {
						arr[i].setTel(arr[j].getTel());
						break;
					}
				}
			}
			for (j = a; j < size; j++) {
				if ((getDigit(arr[j].getTel()) == y) && (arr[j].getTel() != arr[a - 1].getTel())) {

					arr[i].setTel(arr[j].getTel());
					a = j + 1;
					k--;
					break;
				}
			}
		}
	}
}

void changeSubTelefons(Subscriber arr[], Subscriber tmp[], const int size, char * str1, char * str2, int h, int x, int y){
	cout << "Введите число x: " << endl;
	cin >> x;
	cout << "Введите число y: " << endl;
	cin >> y;
	ChangeTel(arr, size, x, y);
	printArray(arr, size);
}

void exit(Subscriber arr[], Subscriber tmp[], const int size, char * str1, char * str2, int h, int x, int y) {
	exit(0);
}

void help(Subscriber arr[], Subscriber tmp[], const int size, char * str1, char * str2, int h, int x, int y) {
	cout << "Объект  содержит информацию об абонентах междугородной телефонной станции : фамилия и имя абонента, адрес, номер телефона. \n a)	Вывести список абонентов по возрастанию номеров телефонов. \n b)	Вывести список абонентов дома, адрес которого вводится. \n c)	Все номера телефонов, начинающиеся с цифры х, заменить на номера, начинающиеся с цифры y." << endl;
}

void forEach(Subscriber arr[], Subscriber tmp[], const int size, char * str1, char * str2, int h, int x, int y, pfff pf) {
	pf(arr, tmp, size, str1, str2, h, x, y);
}



int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	const int N = 10;
	Subscriber station[N];
	Subscriber tmp[N];
	char * street = nullptr;
	char * address = nullptr;
	street = giveMemory(MAX);
	address = giveMemory(MAX);
	int h = 0, x = 0, y = 0;
	int n = 0;

	initArray(station, N);
	fff * Fmenu[7] = { exit, help, printArray, sortSubTelefons, getSubStreet, getSubAddress, changeSubTelefons };
	while (1) {
		cout << "Введите номер операции:" << endl;
		cout << "0 - выход" << endl;
		cout << "1 - вывести условие" << endl;
		cout << "2 - вывести список всех абонентов станции" << endl;
		cout << "3 - вывести список абонентов по возрастанию номеров телефонов" << endl;
		cout << "4 - вывести список абонентов, которые проживают на одной улицы" << endl;
		cout << "5 - вывести список абонентов дома" << endl;
		cout << "6 - все номера телефонов, начинающиеся с цифры х, заменить на номера, начинающиеся с цифры y" << endl;
		cin >> n;
		forEach(station, tmp, N, street, address, h, x, y, Fmenu[n]);
	}
	freeMemory(street);
	freeMemory(address);
	system("pause");
	return 0;

}