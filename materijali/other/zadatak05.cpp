/*Napisati program u kojem je potrebno unijeti odabrani broj znamenaka počevši od znamenke najveće težinske vrijednosti, 
pa od njih sastaviti i ispisati prirodni broj. Unos znamenaka se prekida kada se unese broj manji od 0 ili veći od 9. 
Ispisati poruku ukoliko je dobiveni broj savršen*/
#include<iostream>
using namespace std;

bool isSavrsen(int);

int main() {

	int cifra = 0, broj=0;

	cout << "Unesite cifru: ";
	cin >> cifra;

	while (!(cifra < 0 || cifra > 9)) {

		broj = broj * 10 + cifra;

		cout << "Unesite cifru: ";
		cin >> cifra;
	}

	cout << "Broj sastavljen od zadanih cifara je " << broj << "." << endl;
	
	if (isSavrsen(broj))
		cout << "Broj je savrsen." << endl;

	else
		cout << "Broj nije savrsen." << endl;

	system("pause");
	return 0;

}

bool isSavrsen(int broj) {

	int suma = 0;

	for (int i = 1; i < broj; i++) {
		if (broj%i == 0)
			suma += i;
	}

	if (suma == broj)
		return true;

	return false;

}
