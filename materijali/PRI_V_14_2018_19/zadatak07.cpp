#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

char *charAlloc(char *);

struct Datum {
	int dan, mjesec, godina;

	void unos() {
		do {
			cout << "Dan: ";
			cin >> dan;
		} while (dan < 1 || dan > 31);

		do {
			cout << "Mjesec: ";
			cin >> mjesec;
		} while (mjesec < 1 || mjesec > 12);

		do {
			cout << "Godina: ";
			cin >> godina;
		} while (godina < 1 || godina > 2019);
	}

	void ispis() {
		cout << dan << "." << mjesec << "." << godina << "." << endl;
	}

	// definisanje operatora za poredjenje
	bool operator == (Datum &a) {
		if (dan != a.dan)
			return false;
		if (mjesec != a.mjesec)
			return false;
		if (godina != a.godina)
			return false;
		return true;
	}
};

struct Cijepljenje {
	Datum datum;
	char *opis;

	void unos() {
		char temp[30];

		cout << "Unesite datum cijepljenja!" << endl;
		datum.unos();

		cout << "Unesite opis cijepljenja: ";
		cin.ignore();
		cin.getline(temp, 30);
		opis = charAlloc(temp);
	}

	void ispis() {
		cout << "Datum: ";
		datum.ispis();

		cout << "Opis cijepljenja: " << opis << endl;
	}
};

struct Ljubimac {
	char *ime;
	int dob;
	char *vrsta;
	char *spol;
	Cijepljenje cijep;

	void _unos() {
		char tempIme[10], tempVrsta[20], tempSpol[7];

		cout << "\nUnesite ime: ";
		cin.getline(tempIme, 10);

		cout << "Unesite vrstu: ";
		cin.getline(tempVrsta, 20);

		cout << "Unesite spol: ";
		cin.getline(tempSpol, 7);

		unos(tempIme, tempVrsta, tempSpol);
	}

	// ne znam za sta je uopste trebalo tri int-a 
	// orginalno: void ljubimac :: unos(char *, char*, char*, int, int, int);
	void unos(char *tempIme, char *tempVrsta, char *tempSpol) {
		cout << "Dob: ";
		cin >> dob;

		cijep.unos();

		ime = charAlloc(tempIme);
		vrsta = charAlloc(tempVrsta);
		spol = charAlloc(tempSpol);
	}

	void ispis() {
		cout << "Ime: " << ime << endl;
		cout << "Dob: " << dob << endl;
		cout << "Vrsta: " << vrsta << endl;
		cout << "Spol: " << spol << endl;
		cijep.ispis();
	}

	void deloc() {
		delete[] ime;
		delete[] vrsta;
		delete[] spol;
		delete[] cijep.opis;
	}
};

void pronadjiVrstu(Ljubimac *, int);
void pronadjiCijep(Ljubimac *, int);
Ljubimac najkraceIme(Ljubimac *, int);
Ljubimac *mladjiOd13(Ljubimac *, int, int &);
bool provjeraIstih(Ljubimac *, int);
void dealociraj(Ljubimac &);

int main() {

	// pointeri na funkcije
	void (*_pronadjiVrstu) (Ljubimac *, int) = pronadjiVrstu;
	void (*_pronadjiCijep) (Ljubimac *, int) = pronadjiCijep;
	Ljubimac (*_najkraceIme) (Ljubimac *, int) = najkraceIme;
	Ljubimac *(*_mladjiOd13) (Ljubimac *, int, int &) = mladjiOd13;
	bool (*_provjeraIstih) (Ljubimac *, int) = provjeraIstih;

	int brojObj = 0, new_brojObj = 0;
	Ljubimac *nizObj = nullptr;
	Ljubimac *new_nizObj = nullptr;

	cout << "Unesite zeljeni broj ljubimaca: ";
	cin >> brojObj;
	cin.ignore();

	nizObj = new Ljubimac[brojObj];

	// unos atributa u objekte
	for (int i = 0; i < brojObj; i++)
		nizObj[i]._unos();

	_pronadjiVrstu(nizObj, brojObj);
	_pronadjiCijep(nizObj, brojObj);

	cout << "\nLjubimac sa najkracim imenom: " << endl;
	_najkraceIme(nizObj, brojObj).ispis();

	cout << "\nLjubimci mladji od 13 mjeseci: " << endl;
	new_nizObj = _mladjiOd13(nizObj, brojObj, new_brojObj);
	for (int i = 0; i < new_brojObj; i++)
		new_nizObj[i].ispis();

	_provjeraIstih(nizObj, brojObj) ? cout << "\nPostoje dva ljubimca sa isitim imenom!" << endl 
		: cout << "\nNe postoje dva ljubimca sa istim imenom!" << endl;

	// DEALOKACIJA
	for (int i = 0; i < brojObj; i++) {
		nizObj[i].deloc();
	}
	delete[] nizObj;
	nizObj = nullptr;

	// Ne treba brisati atribute elemenata jer su kopirane iz 
	// orginalnog niza po referenci, samo treba izbrisati niz

	/*for (int i = 0; i < new_brojObj; i++) {
		new_nizObj[i].deloc();
	}*/
	delete[] new_nizObj;
	new_nizObj = nullptr;

	system("pause");
	return 0;
}

char *charAlloc(char *temp) {
	// +1 za terminirajucu nulu
	char *retVal = new char[strlen(temp) + 1];
	strcpy(retVal, temp);
	return retVal;
}

void pronadjiVrstu(Ljubimac *niz, int vel) {
	char pretraga[20];

	cout << "\nUnesite vrstu koju zelite pronaci: ";
	cin.getline(pretraga, 20);

	for (int i = 0; i < vel; i++)
		if (!strcmp(niz[i].vrsta, pretraga))
			niz[i].ispis();
}

void pronadjiCijep(Ljubimac *niz, int vel) {
	Datum pretraga;

	cout << "\nUnesite datum za pretragu!" << endl;
	pretraga.unos();

	for (int i = 0; i < vel; i++)
		if (pretraga == niz[i].cijep.datum)
			niz[i].ispis();
}

Ljubimac najkraceIme(Ljubimac *niz, int vel) {
	Ljubimac najkrace = niz[0];

	for (int i = 1; i < vel; i++) {
		if (strlen(niz[i].ime) < strlen(najkrace.ime))
			najkrace = niz[i];
	}
	return najkrace;
}

Ljubimac * mladjiOd13(Ljubimac *niz, int vel, int &newVel) {
	int j = 0;
	Ljubimac *noviNiz = nullptr;

	for (int i = 0; i < vel; i++)
		if (niz[i].dob < 13)
			newVel++;

	noviNiz = new Ljubimac[newVel];

	for (int i = 0; i < vel; i++)
		if (niz[i].dob < 13)
			noviNiz[j++] = niz[i];

	return noviNiz;
}

bool provjeraIstih(Ljubimac *niz, int vel) {
	for (int i = 1; i < vel; i++)
		if (!strcmp(niz[i - 1].ime, niz[i].ime))
			return true;
	return false;
}