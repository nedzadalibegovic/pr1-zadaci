#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Datum {
	int dan, mjesec, godina;

	void unos(int d, int m, int g) {
		dan = d;
		mjesec = m;
		godina = g;
	}

	void ispis() {
		cout << dan << "." << mjesec << "." << godina << endl;
	}

	bool operator == (const Datum &a) {
		if (a.dan == dan)
			if (a.mjesec == mjesec)
				if (a.godina == godina)
					return true;
		return false;
	}
};

struct PolozeniPredmeti {
	char *naziv;
	int ocjena;
	Datum datumPolaganja;

	~PolozeniPredmeti() {
		delete naziv;
		naziv = nullptr;
	}

	void unos(char *naz, int ocj, Datum dat) {
		naziv = new char[strlen(naz) + 1];
		strcpy(naziv, naz);

		ocjena = ocj;

		datumPolaganja = dat;
	}

	void ispis() {
		cout << "Naziv polozenog predmeta: " << naziv << endl;
		cout << "Ocjena: " << ocjena << endl;
		cout << "Datum polaganja: ";
		datumPolaganja.ispis();
	}
};

struct Student {
	char *imePrezime;
	int indeks;
	PolozeniPredmeti *polozeni[40];
	int brojPolozenih;

	~Student() {
		delete imePrezime;
		imePrezime = nullptr;
		for (int i = 0; i < brojPolozenih; i++) {
			delete polozeni[i];
			polozeni[i] = nullptr;
		}
	}

	void unos(char *ime, int ind) {
		imePrezime = new char[strlen(ime) + 1];
		strcpy(imePrezime, ime);

		indeks = ind;

		brojPolozenih = 0;
	}

	void ispis() {
		cout << "Ime i prezime studenta: " << imePrezime << endl;
		cout << "Broj indeksa: " << indeks << endl;
		cout << "Broj polozenih ispita: " << brojPolozenih << endl;
		for (int i = 0; i < brojPolozenih; i++)
			polozeni[i]->ispis();
	}

	void addPolozeni(char *naz, int ocj, Datum dat) {
		if (brojPolozenih == 40) {
			cout << "Max broj predmeta dosegnut!" << endl;
			return;
		}
		polozeni[brojPolozenih] = new PolozeniPredmeti;
		polozeni[brojPolozenih++]->unos(naz, ocj, dat);
	}

	int pretragaPoDatumu(Datum datumPolaganja) {
		int sum = 0;
		for (int i = 0; i < brojPolozenih; i++) {
			if (polozeni[i]->datumPolaganja == datumPolaganja) {
				polozeni[i]->ispis();
				sum++;
			}
		}
		cout << "Broj polozenih predmeta na trazeni datum: ";
		return sum;
	}

	void pretragaPoNazivu(char *naz) {
		for (int i = 0; i < brojPolozenih; i++)
			if (strstr(polozeni[i]->naziv, naz) != nullptr)
				cout << polozeni[i]->naziv << endl;
	}
};

int pretragaPoProsjeku(Student *pok, int max) {
	cout << "\n<--Pretraga po prosjeku-->\n";

	int prosjek, brStudenata = 0;

	cout << "Unesite zeljeni prosjek: ";
	cin >> prosjek;

	for (int i = 0; i < max; i++) {
		float prStud = 0.f;
		for (int j = 0; j < pok[i].brojPolozenih; j++) {
			prStud += pok[i].polozeni[j]->ocjena;
		}
		prStud /= pok[i].brojPolozenih;
		if (prosjek < prStud)
			brStudenata++;
	}

	cout << "Broj studenata sa prosjekom vecim od unesenog: ";
	return brStudenata;
}

int main() {

	int max, intBuffer;
	char charBuffer[30];
	Datum datumBuffer;

	cout << "Unesite zeljeni broj studenata: ";
	cin >> max;
	cin.ignore();

	Student *niz = new Student[max];

	// unos imena i broja indeksa
	for (int i = 0; i < max; i++) {
		cout << "Unesite ime i prezime: ";
		cin.getline(charBuffer, 30);

		cout << "Broj indeksa: ";
		cin >> intBuffer;
		cin.ignore();

		niz[i].unos(charBuffer, intBuffer);
	}

	// unos polozenih predmeta
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "\nStudent: " << niz[i].imePrezime << endl;

			cout << "Unesite naziv predmeta: ";
			cin.getline(charBuffer, 30);

			cout << "Ocjena: ";
			cin >> intBuffer;
			cin.ignore();

			int dan, mjesec, godina;
			cout << "Unesite dan_mjesec_godina: ";
			cin >> dan >> mjesec >> godina;
			cin.ignore();
			datumBuffer.unos(dan, mjesec, godina);

			niz[i].addPolozeni(charBuffer, intBuffer, datumBuffer);
		}
	}

	{
		cout << "\n<--Pretraga po datumu-->\n";

		cout << "Unesite indeks zeljenog studenta: ";
		cin >> intBuffer;
		cin.ignore();

		int dan, mjesec, godina;
		cout << "Unesite dan_mjesec_godina: ";
		cin >> dan >> mjesec >> godina;
		cin.ignore();
		datumBuffer.unos(dan, mjesec, godina);

		cout << niz[intBuffer].pretragaPoDatumu(datumBuffer) << endl;
	}

	{
		cout << "\n<--Pretraga po nazivu-->\n";

		cout << "Unesite indeks zeljenog studenta: ";
		cin >> intBuffer;
		cin.ignore();

		cout << "Unesite trazeni dio teksta: ";
		cin.getline(charBuffer, 30);

		niz[intBuffer].pretragaPoNazivu(charBuffer);
		cout << endl;
	}
	
	cout << pretragaPoProsjeku(niz, max) << endl;

	delete[] niz;

	system("pause");
	return 0;
}