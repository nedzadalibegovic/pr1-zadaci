#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Datum {
	int dan, mjesec, godina;

	bool operator < (Datum &a) {
		if (godina <= a.godina)
			if (mjesec <= a.mjesec)
				if (dan < a.dan)
					return true;
		return false;
	}

	/*bool operator > (Datum &a) {
		if (godina > a.godina)
			if (mjesec > a.mjesec)
				if (dan > a.dan)
					return true;
		return false;
	}*/

	void unos() {
		cout << "Unesite dan: ";
		cin >> dan;
		cout << "Unesite mjesec: ";
		cin >> mjesec;
		cout << "Unesite godinu: ";
		cin >> godina;
		cin.ignore();
	}
	
	void ispis() {
		cout << dan << "." << mjesec << "." << godina << ".\n";
	}
};

struct Student {
	char indeks[9]; //IB180130
	char imePrezime[30];
	Datum datumRodjenja;

	void ispis() {
		cout << "Indeks: " << indeks << "\n";
		cout << "Ime i prezime: " << imePrezime << "\n";
		datumRodjenja.ispis();
	}
};

char *GetSljedeciBrojIndeksa(char *posljednji) {
	/*Funkcija treba da vrati sljedeći broj indeksa (u odnosu na onaj koji je primljen kao parametar)
	prateći format IB130XXX pri cemu je fiksni dio u oznaci indeksa IB180, a posljednje 3 oznake se mijenjaju.
	Voditi racuna da broj indeksa uvijek posjeduje 8 znakova*/
	
	int indeksInt = atoi(posljednji + 5); // uzmi string od 5-og indeksa i pretvori u int
	char indeksChar[9] = "IB180"; // konstantni elementi niza
	char temp[4]; // buffer
	_itoa(++indeksInt, temp, 10); // uvecaj int za 1 i pretvori u string
	strcat(indeksChar, temp); // dodaj buffer na kraj stringa

	return indeksChar; // vrati adresu niza
}

Student * GetStudentePoDatumuRodjenja(Student *lista, int max, Datum starijiOd, int &novi) {
	/*Funkcija treba da vrati niz studenata koji su rođeni nakon datuma rođenja definisanog parametrom starijiOD.
	Ako ne postoji niti jedan student koji zadovoljava uslove pretrage, onda funkcija vraća NULL*/

	int j = 0;
	Student *noviNiz = nullptr;

	for (int i = 0; i < max; i++)
		if (starijiOd < lista[i].datumRodjenja)
			novi++;

	if (novi == 0)
		return NULL;

	noviNiz = new Student[novi];

	for (int i = 0; i < max; i++)
		if (starijiOd < lista[i].datumRodjenja)
			noviNiz[j++] = lista[i];

	return noviNiz;
}

int main() {
	//1. korisniku omoguciti da odredi koliko objekata tipa Student zeli kreirati. 
	// Objekte kreirati u dinamickoj memoriji 
	//2. korisniku omoguciti da unutar main funkcije inicijalizuje vrijednosti 
	// atributa svakog studenta. Tom prilikom iskoristiti funkciju 
	// GetSljedeciBrojIndeksa 
	//3. korisniku omoguciti pretragu studenata po datumu rodjenja, te ispisati 
	// rezultat pretrage 
	//4. izvrsiti potrebne dealokacije

	int brojObj = 0, brojStarijiOd = 0;
	Student *nizObj = nullptr, *starijiOdNiz = nullptr;
	Datum starijiOd;

	cout << "Unesite zeljeni broj objekata: ";
	cin >> brojObj;
	cin.ignore();

	nizObj = new Student[brojObj];

	cout << "Unesite broj indeksa (IB180xxx): ";
	cin.getline(nizObj[0].indeks, 9);

	cout << "Unesite ime i prezime: ";
	cin.getline(nizObj[0].imePrezime, 30);

	cout << "Unesite datum rodjenja: ";
	nizObj[0].datumRodjenja.unos();

	for (int i = 1; i < brojObj; i++) {
		strcpy(nizObj[i].indeks, GetSljedeciBrojIndeksa(nizObj[i - 1].indeks));
		cout << "Broj indeksa: " << nizObj[i].indeks << "\n";

		cout << "Unesite ime i prezime: ";
		cin.getline(nizObj[i].imePrezime, 30);

		cout << "Unesite datum rodjenja: ";
		nizObj[i].datumRodjenja.unos();
	}
	
	cout << "Unesite datum za pretragu: ";
	starijiOd.unos();

	starijiOdNiz = GetStudentePoDatumuRodjenja(nizObj, brojObj, starijiOd, brojStarijiOd);

	for (int i = 0; i < brojStarijiOd; i++)
		starijiOdNiz[i].ispis();

	// DEALOKACIJA
	delete[] nizObj;
	nizObj = nullptr;

	delete[] starijiOdNiz;
	starijiOdNiz = nullptr;

	cin.get();
	return 0;
}