/*Napišite program, poštujući sve faze procesa programiranja, koji omogućava da se ispišu
svi brojevi koji zadovoljavaju uvjet da im je zapis jednak zapisu posljednjih znamenki
njihovog kvadrata. (Npr. 6^2 = 36, 25^2 = 625 …) Provjeru vršiti za prvih 150 prirodnih
brojeva.*/

#include<iostream>
using namespace std;

int brojCifara(int);
int zadnjeCifre(int);

int main() {

	int n;

	cout << "Unesite velicinu opsega (od 1 do n): ";
	cin >> n;

	for (int i = 1; i <= n; i++) {

		//ako broj postoji u zadnjim ciframa i.e. 25 u 625
		if (i == zadnjeCifre(i)) {

			cout << i << "^2=" << i * i << endl;

		}

	}

	system("pause");
	return 0;

}

int brojCifara(int broj) {

	int brojac=0;

	//dijeli sa 10 dok ne dodje do 0
	while (broj > 0) {

		broj /= 10;
		brojac++;

	}

	return brojac;

}

int zadnjeCifre(int broj) {

	int ostatak;
	
	//uzmi onoliko cifara sa kraja od kvadrata koliko cifara ima orginalni broj
	ostatak = int(pow(broj, 2)) % int(pow(10, brojCifara(broj)));

	return ostatak;

}
