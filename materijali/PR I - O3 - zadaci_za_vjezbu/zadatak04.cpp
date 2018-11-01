/*Napišite program koji će korisniku omogućiti unos znakova s tastature. Unos znakova se
prekida kad korisnik unese znak „0“. Program treba prebrojati i ispisati koliko je među
unesenim znakovima bilo malih slova, koliko velikih slova i koliko je među unesenim
znakovima bilo onih koji nisu slova (interpunkcijski znakovi, znamenke, zagrade i sl.)*/

#include<iostream>
using namespace std;

bool malaSlova(char);
bool velikaSlova(char);
bool neodredjeni(char);

int brMala = 0, brVelika = 0, brNeodredjeni = 0;

int main() {

	char znak;

	do {

		cout << "Unesite znak: ";
		cin >> znak;

		if (malaSlova(znak)) {

			brMala++;

		}

		else if (velikaSlova(znak)) {

			brVelika++;

		}

		else {

			brNeodredjeni++;

		}

	} while (znak != '0');

	cout << "Broj unesenih malih slova: " << brMala << endl;
	cout << "Broj unesenih velikih slova: " << brVelika << endl;
	cout << "Broj ostalih znakova: " << brNeodredjeni << endl;

	system("pause");
	return 0;

}

bool malaSlova(char znak) {

	if (znak >= 97 && znak <= 122) {

		return true;

	}

	return false;

}

bool velikaSlova(char znak) {

	if (znak >= 65 && znak <= 90) {

		return true;

	}

	return false;

}
