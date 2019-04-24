/*Napišite program, poštujući sve faze procesa programiranja (analiza, specifikacija,
dizajn, kod, validacija/testiranje), u kojem ćete omogući unos jednog malog slova
engleske abecede. Program treba ispisati neposrednog prethodnika i neposrednog
sljedbenika slova kojeg je korisnik upisao preko tastature. U slučaju da je korisnik
napravio pogrešan unos (upisao karakter koji nije malo slovo) program treba ispisati
odgovarajuću poruku. Vodite računa da slovo a nema prethodnika, a slovo z nema
sljedbenika. Omogućite korisniku da ponavlja unos slova dok god to želi.*/

#include<iostream>
using namespace std;

int main() {

	char slovo;
	bool uslov;

	do {

		do {

			cout << "Unesite malo slovo engleske abecede: ";
			cin >> slovo;

		} while (!(slovo >= 94 && slovo <= 122));

		if (slovo == 'a') {

			cout << "Njegov sljedbenik: " << char(slovo + 1) << endl;

		}

		else if (slovo == 'z') {

			cout << "Njegov prethodnik: " << char(slovo - 1) << endl;

		}

		else {

			cout << "Njegov prethodnik: " << char(slovo - 1) << endl;
			cout << "Njegov sljedbenik: " << char(slovo + 1) << endl;

		}

		cout << "Da li zelite ponovo unijeti slovo? (0: ne, 1: da): ";
		cin >> uslov;

	} while (uslov != 0);

	system("pause");
	return 0;

}
