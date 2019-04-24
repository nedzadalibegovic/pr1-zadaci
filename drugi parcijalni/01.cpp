#include <iostream>
using namespace std;

struct Datum {

	void unos();
	void ispis();

	int dan, mjesec, godina;
};

struct Student {
	int brojIndeksa;
	char imePrezime[20];
	Datum datumRodjenja;

	void ispis() {
		cout << "Broj indeksa: " << brojIndeksa << endl;
		cout << "Ime i prezime: " << imePrezime << endl;
		cout << "Datum rodjenja: ";
		datumRodjenja.ispis();
	}
};

void Datum::unos() {

	cout << "Dan: ";
	cin >> dan;

	cout << "Mjesec: ";
	cin >> mjesec;

	cout << "Godina: ";
	cin >> godina;
}

void Datum::ispis() {
	cout << dan << "." << mjesec << "." << godina << ".\n";
}

void unos(Student *niz, int max) {
	for (int i = 0; i < max; i++) {
		cout << "Broj indeksa: ";
		cin >> niz[i].brojIndeksa;
		cin.ignore();

		cout << "Unesite ime i prezime: ";
		cin.getline(niz[i].imePrezime, 20);

		cout << "Unesite datum rodjenja: ";
		niz[i].datumRodjenja.unos();
	}
}

bool isPrestupna(int year) {
	bool result;
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				result = true;
			else
				result = false;
		}
		else
			result = true;
	}
	else
		result = false;
	return result;
}

bool isDatumOk(Datum obj) {
	if (obj.dan == 31)
		switch (obj.mjesec) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return true;
		default:
			break;
		}

	if (obj.dan == 30) {
		switch (obj.mjesec) {
		case 4:
		case 6:
		case 9:
		case 11:
			return true;
		default:
			break;
		}
	}

	if (obj.dan == 29 && isPrestupna(obj.godina) && obj.mjesec == 2)
		return true;

	if ((2019 - obj.godina) > 17 && (2019 - obj.godina) < 55)
		return true;

	return false;
}

int BR = 0;

Student *getStudente(Student *niz, int max) {
	int j = 0;
	for (int i = 0; i < max; i++) {
		if (isDatumOk(niz[i].datumRodjenja))
			BR++;
	}
	Student *pok = new Student[BR];
	for (int i = 0; i < max; i++) {
		if (isDatumOk(niz[i].datumRodjenja))
			pok[j++] = niz[i];
	}

	return pok;
}

int main() {

	int brojStudenata;
	Student *noviNiz = nullptr;

	cout << "Unesite zeljeni broj studenata: ";
	cin >> brojStudenata;

	Student *niz = new Student[brojStudenata];

	unos(niz, brojStudenata);
	noviNiz = getStudente(niz, brojStudenata);

	for (int i = 0; i < BR; i++)
		noviNiz[i].ispis();

	system("pause");
	return 0;
}