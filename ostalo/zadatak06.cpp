/*Napisati program koji omogućava unos pozitivnog broja n te pronalazi njegovu najmanju cifru i formira novi
broj u kojem je najmanja cifra zamijenjena cifrom '3'. Ukoliko uneseni broj n sadrži više istih cifara koje su
najmanje, tada je potrebno zamijeniti svaku od njih. Dodatno program treba ispisati razliku unesenog i broja
koji se dobije nakon zamjene najmanje cifre.*/
#include<iostream>
using namespace std;

int najmnaji(int);
int zamjena(int);

int main() {

	int broj;

	do {

		cout << "Unesite pozitivan broj: ";
		cin >> broj;

	} while (broj < 1);

	cout << zamjena(broj) << endl;
	cout << broj - zamjena(broj) << endl;



	system("pause");
	return 0;

}

int najmnaji(int broj) {

	int temp = 0, najmanji = 9;

	while (broj > 0) {

		temp = broj % 10;

		if (temp <= najmanji) {

			najmanji = temp;

		}

		broj /= 10;


	}

	return najmanji;

}

int zamjena (int broj) {

	int noviBroj = 0, temp = 0, brojac = 0;

	while (broj > 0) {

		temp = broj % 10;
		
		if (temp == najmnaji(broj)) {

			temp = 3;

		}

		noviBroj = noviBroj + temp * int(pow(10, brojac));
		broj /= 10;
		brojac++;

	}

	return noviBroj;

}
