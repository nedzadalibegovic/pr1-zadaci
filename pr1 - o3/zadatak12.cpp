/*Napišite program, poštujući sve faze procesa programiranja, koji korisniku
omogućava da unese jedan pozitivan cijeli broj u binarnom brojevnom sistemu, a ispisuje
njegov ekvivalent u dekadskom brojevnom sistemu.*/

#include<iostream>
using namespace std;

int pretvaranje(int);

int main() {

	int broj;

	cout << "Unesite binarni broj: ";
	cin >> broj;

	cout << "Broj " << broj << " u dekadnom sistemu iznosi: " << pretvaranje(broj) << endl;

	system("pause");
	return 0;

}

int pretvaranje(int broj) {

	int dekadni = 0, i = 0;

	while (broj > 0) {

		// uzima se zadnja cifra, mnozi se sa 2^n sa svojim odgvorajucim tezinskim mjestom 
		dekadni += (broj % 10)*pow(2, i);
		broj /= 10;
		i++;

	}

	return dekadni;

}
