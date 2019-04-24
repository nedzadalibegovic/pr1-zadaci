#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

enum Opstina { Opstina1, Opstina2, Opstina3, Opstina4 };

char *OpstineChar[] = {"Opstina1", "Opstina2", "Opstina3", "Opstina4"};

enum Kandidati { Kandidat1, Kandidat2, Kandidat3, Kandidat4 };

char *KandidatiChar[] = {"Kandidat1", "Kandidat2", "Kandidat3", "Kandidat4"};

struct Datum {
	int _dan, _mjesec, _godina;

	void Unos(int d, int m, int g) {
		_dan = d;
		_mjesec = m;
		_godina = g;
	}

	void Ispis() { cout << _dan << "/" << _mjesec << "/" << _godina << endl; }
};

struct Osoba {
	Datum _datumRodjenja;
	char *_imePrezime;
	char _JMBG[14];
	Opstina _Prebivaliste;

	void unos(Datum d, char *ip, char jmbg[], Opstina p) {
		_datumRodjenja = d;
		_imePrezime = new char[strlen(ip) + 1];
		strcpy(_imePrezime, ip);
		strcpy(_JMBG, jmbg);
		_Prebivaliste = p;
	}

	void Dealociraj() {
		delete[] _imePrezime;
		_imePrezime = nullptr;
	}

	void Info() {
		_datumRodjenja.Ispis();
		cout << _imePrezime << " " << _JMBG << " " << OpstineChar[_Prebivaliste] << endl;
	}
};

struct Glas {
	Osoba _glasac;
	Kandidati _glasZa;

	void Unos(Osoba o, Kandidati k) {
		_glasac.unos(o._datumRodjenja, o._imePrezime, o._JMBG, o._Prebivaliste);
		_glasZa = k;
	}

	void Ispis() {
		_glasac.Info();
		cout << KandidatiChar[_glasZa] << endl;
	}

	void Dealociraj() {
		_glasac.Dealociraj();
	}
};

struct Izbori2014 {
	Opstina _glasackoMjesto;
	Glas *_glasovi = new Glas[0];
	int _brojGlasaca = 0;

	void Unos(Opstina *o) {
		/*na osnovu vrijednosti primljenih parametara, inicijalizovati vrijednosti atributa strukture.*/
		_glasackoMjesto = *o;
	}

	bool AddGlas(Glas *g) {
		/*funkcija treba da omoguci dodavanje informacija o novom glasu
		tom prilikom:
		
		-	onemoguciti da ista osoba glasa vise puta
		-	onemoguciti glasanje osobama mladjim od 18 godina (uzeti u obzir samo mjesec i godinu rodjenja) 
		-	onemoguciti glasanje osobama iz drugih opstina
		-	u zavisnosti od uspjesnosti operacije funkcija vraca true ili false
		*/
		for (int i = 0; i < _brojGlasaca; i++)
			if (!strcmp(_glasovi[i]._glasac._JMBG, g->_glasac._JMBG)) {
				cout << "Osoba je vec glasala!\n";
				return false;
			}
		if ((2019 - g->_glasac._datumRodjenja._godina) < 18) {
			cout << "Glasac mladji od 18 godina!\n";
			return false;
		}
		if (g->_glasac._Prebivaliste != _glasackoMjesto) {
			cout << "Glasac nije u istoj opcini!\n";
			return false;
		}

		Glas *newArr = new Glas[++_brojGlasaca];
		copy(_glasovi, _glasovi + (_brojGlasaca - 2), newArr);
		newArr[_brojGlasaca - 1] = *g;
		delete[] _glasovi;
		_glasovi = newArr;

		return true;
	}

	void Dealociraj() {
		/*definisati funkciju vodeci racuna o oslobadjanju svih resursa koji su alocirani za potrebe objekta tipa Izbori2014*/
		delete[] _glasovi;
	}
};

Opstina ProglasiPobjednika(Izbori2014 *izbornaMjesta, const int &brojIzbornihMjesta) {
	/*
	u zavisnosti od postignutog uspjeha, 
	-	funkcija treba ispisati listu kandidata sortiranu opadajucim redoslijedom, a uz svakog kandidata je potrebno ispisati i osvojeni procenat glasova 
	-	funkcija vraca opstinu u kojoj je pobjednicki kandidat ostvario najveci broj glasova
	-	ukoliko je pobjednicki kandidat ostvario podjednak broj glasova u vise opstina, funkcija vraca prvu koja se nalazi u nizu na koji pokazuje pokazivac izbornaMjesta
	*/
	int ukupanBrojGlasova = 0;
	int brojGlasovaKand[4] = {};
	Kandidati pobjednik = Kandidat1;
	int najveci = 0;

	// brojanje glasova
	for (int i = 0; i < brojIzbornihMjesta; i++)
		for (int j = 0; j < izbornaMjesta[i]._brojGlasaca; j++) {
			switch (izbornaMjesta[i]._glasovi[j]._glasZa) {
				case Kandidat1:
					brojGlasovaKand[0]++;
					break;
				case Kandidat2:
					brojGlasovaKand[1]++;
					break;
				case Kandidat3:
					brojGlasovaKand[2]++;
					break;
				case Kandidat4:
					brojGlasovaKand[3]++;
					break;
				default:
					break;
			}
			ukupanBrojGlasova++;
		}

	// ispis kandidata
	for (int i = 0; i < 4; i++)
		cout << "Kandidat " << i + 1 << " ima " << brojGlasovaKand[i] << "(" << (brojGlasovaKand[i] / ukupanBrojGlasova)
			*
			100 << "%)\n";

	for (int i = 1; i < 4; i++) {
		if (brojGlasovaKand[najveci] < brojGlasovaKand[i])
			najveci = i;
		switch (najveci) {
			case 1:
				pobjednik = Kandidat2;
				break;
			case 2:
				pobjednik = Kandidat3;
				break;
			case 3:
				pobjednik = Kandidat4;
				break;
			default:
				pobjednik = Kandidat1;
				break;
		}
	}

	cout << "Kandidat " << pobjednik << " je pobjednik!\n";
}

int main() {

	/*provjeriti validnost izvrsenja svih dostupnih funkcionalnosti. 
	izbjegavajte koristenje vlastitog imena i prezimena*/
	return 0;
}
