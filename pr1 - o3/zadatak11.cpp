/*Napišite program, poštujući sve faze procesa programiranja, koji korisniku omogućava
da unese jedan pozitivan cijeli broj u dekadskom brojevnom sistemu, a ispisuje njegov
ekvivalent u binarnom brojevnom sistemu.*/

#include<iostream>
using namespace std;

int pretvaranje(int);

int main() {

	int broj;

	cout << "Unesite broj: ";
	cin >> broj;

	cout << "Broj " << broj << " u binarnom sistemu iznosi: " << pretvaranje(broj) << endl;

	system("pause");
	return 0;

}

int pretvaranje(int broj) {

	int binarni = 0, i = 0;

	while (broj > 0) {

		// mnozi sa 10^i zato sto broj se cita od dna ka vrhu
		binarni += (broj % 2)*pow(10, i);
		broj /= 2;
		i++;

	}

	return binarni;

}
