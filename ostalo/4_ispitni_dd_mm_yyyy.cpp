/*
	Kreirati program koji ce pronaci i ispisati sve brojeve od X do Y (ukljucujuci granicne vrijednosti)
	koji su djeljivi svim svojim ciframa. 
	Na primjer, broj 36 je djeljiv sa brojevima 3 i 6. (36/6=6 i 36/3=12).
	Brojeve X i Y unosi korisnik i moraju biti u opsegu od 10 do 6000. Obavezno koristiti bar jednu funkciju.

	Primjer:
	Unesite granice intervala: 32 37
	Brojevi u navedenom opsegu koji zadovoljavaju uslov su: 33, 36.

*/

#include <iostream>
using namespace std;

bool djeljivost(int);

int main() {

	int brojX, brojY;

	do {

		cout << "Unesite X (donja granica): ";
		cin >> brojX;

	} while (brojX < 10 || brojX > 6000);

	do {

		cout << "Unesite Y (gornja granica): ";
		cin >> brojY;

	} while (brojY < 10 || brojY > 6000 || brojY < brojX);

	cout << "Brojevi koji su djeljivi svim svojim ciframa: " << endl;

	for (int i = brojX; i <= brojY; i++) {

		if (djeljivost(i)) {

			cout << i << endl;

		}

	}

	system("pause");
	return 0;

}

bool djeljivost(int broj) {

	int zadnja, temp=broj;

	while (broj > 0) {

		zadnja = broj % 10;

		if (zadnja != 0) {

			if (temp%zadnja != 0) {

				return false;

			}

		}

		broj /= 10;

	}

	return true;

}