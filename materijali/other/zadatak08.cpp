#include<iostream>
#include <iomanip>
using namespace std;

int faktorijel(int);

int main() {

	int broj;
	float suma = 0;

	do {

		cout << "Unesite prirodan broj: ";
		cin >> broj;

	} while (broj < 1);

	for (int i = 1; i <= broj; i++) {

		suma += pow(-1, i - 1)*(float(i) / (broj + faktorijel(i)));

	}

	cout << setprecision(2) <<suma << endl;
	

	system("pause");
	return 0;

}

int faktorijel(int broj) {

	int suma = 1;

	for (int i = 1; i <= broj; i++) {

		suma *= i;

	}

	return suma;

}
