/*
Napišite program, poštujući sve faze procesa programiranja, u kojem ćete omogućiti
unos dva prirodna broja te izračunati i ispisati njihov najveći zajednički djelitelj.
Npr. ako korisnik unese brojeve 12 i 16 program treba ispisati da je najveći zajednički
djelitelj ova dva broja broj 4.*/

#include<iostream>
using namespace std;

int nzd(int, int);

int main() {

	int broj1, broj2;

	cout << "Unesite 1. prirodan broj: ";
	cin >> broj1;

	cout << "Unesite 2. prirodan broj: ";
	cin >> broj2;

	cout << nzd(broj1, broj2) << endl;

	system("pause");
	return 0;

}

int nzd(int a, int b) {

	if (a == 0) {

		return b;

	}

	return nzd(b % a, a);

}
