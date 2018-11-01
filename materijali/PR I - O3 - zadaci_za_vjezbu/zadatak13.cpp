/*Napišite programu kojem ćete omogućiti unos dva prirodna broja. Provjerite čine li
uneseni brojevi prijateljski par. Prirodni brojevi a i b čine prijateljski par brojeva ako je
zbir pravih djelitelja broja a (onih koji su manji od a) jednak broju b i istovremeno zbir
pravih djelitelja broja b jednak je broju a.*/

#include<iostream>
using namespace std;

int sumaDjelitelja(int);
bool prijatelji(int, int);

int main() {

	int broj_A, broj_B;

	cout << "Unesite broj a: ";
	cin >> broj_A;

	cout << "Unesite broj b: ";
	cin >> broj_B;

	if (prijatelji(broj_A, broj_B)) {

		cout << "Brojevi " << broj_A << " i " << broj_B << " su prijateljski brojevi!" << endl;

	}

	else {

		cout << "Brojevi " << broj_A << " i " << broj_B << " NISU prijateljski brojevi!" << endl;

	}

	system("pause");
	return 0;

}

int sumaDjelitelja(int broj) {

	int suma=0;

	// provjeravaj sve brojeve od 1 do n
	for (int i = 1; i < broj; i++) {

		// ako je djeljiv sa i dodaj u sumu
		if (broj%i == 0) {

			suma += i;

		}

	}

	return suma;

}

bool prijatelji(int broj1, int broj2) {

	//ako je zbir djelitelja broja a jednak broju b i zbir djelitelja broja b jednak broju a
	if (sumaDjelitelja(broj1) == broj2 && sumaDjelitelja(broj2) == broj1) {

		return true;

	}

	return false;

}
