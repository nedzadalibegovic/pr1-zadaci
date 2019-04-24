/*Data su dva prirodna broja X i Y iz intervala od 10 do 5000. Postujuci sve faze procesa
programiranja, kreirati program koji ce proebrojati i ispisati koliko brojeva od X do Y
(ukljucujuci granicne vrijednosti) zadovoljava uslov da im je suma svih cifara djeljiva sa
brojem koji se dobije kad se saberu prva i zadnja cifra. U rjesenju koristiti najmanje jednu
funkciju.
Npr. Za broj 162 vrijedi da mu je suma cifara 9, a suma prve i zadnje cifre je 1+2=3. Broj 9 je
djeljiv brojem 3.
————————————————————————————————————————————————————————————————————————————————————————————————
Definisite vrijednosti intervala [X, Y]: 10 499
Dati uslov ispunjava: 184 broja.*/

#include <iostream>
using namespace std;

int PrvaCifra(int);
int ZadnjaCifra(int);
int ZbirPrvaZadnja(int);
int ZbirSvih(int);

int main() {

	int brojX, brojY, br=0;

	cout << "Unesite dva prirodna broja iz intervala od 10 do 5000" << endl;

	do {

		cout << "Unesite broj X (donja granica): ";
		cin >> brojX;

	} while (brojX < 10 || brojX > 5000);

	do {

		cout << "Unesite broj Y (gornja granica): ";
		cin >> brojY;

	} while (brojY < 10 || brojY > 5000 || brojY<brojX);

	for (int i = brojX; i <= brojY; i++) {

		if (ZbirSvih(i) % ZbirPrvaZadnja(i) == 0) {

			cout << i << endl;
			br++;

		}

	}

	cout << "Dati uslov ispunjava: " << br << " broja." << endl;

	system("pause");
	return 0;

}

int PrvaCifra(int broj) {

	while (broj >= 10) {

		broj /= 10;

	}

	return broj;

}

int ZadnjaCifra(int broj) {

	return broj % 10;

}

int ZbirPrvaZadnja(int broj) {

	return PrvaCifra(broj) + ZadnjaCifra(broj);

}

int ZbirSvih(int broj) {

	int suma = 0, temp = 0;

	while (broj > 0) {

		temp = broj % 10;
		suma += temp;

		broj /= 10;

	}

	return suma;

}
