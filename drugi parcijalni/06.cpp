#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Pregled {
	char *dijagnoza;
	double cijenaPregleda;

	void unos() {
		char buffer[30];

		cout << "Unesite dijagnozu: " << endl;
		cin.getline(buffer, 30);
		dijagnoza = new char[strlen(buffer) + 1];
		strcpy(dijagnoza, buffer);

		cout << "Unesite cijenu pregleda: ";
		cin >> cijenaPregleda;
		cin.ignore();
	}

	void ispis() {
		cout << "Dijagonza: " << endl << dijagnoza << endl;
		cout << "Cijena pregleda: " << cijenaPregleda << endl;

	}

	~Pregled() {
		delete dijagnoza;
	}
};

struct Pacijent {
	char *imePrezime;
	Pregled *preglediPacijenta[10];
	int brojPosjeta;

	~Pacijent() {
		delete[] imePrezime;

		for (int i = 0; i < brojPosjeta; i++)
			delete preglediPacijenta[i];

		delete preglediPacijenta;
	}

	void unos() {
		char buffer[30];

		cout << "Unesite ime i prezime: ";
		cin.getline(buffer, 30);
		imePrezime = new char[strlen(buffer) + 1];
		strcpy(imePrezime, buffer);

		brojPosjeta = 0;
	}

	void ispis() {
		cout << "Ime i prezime: " << imePrezime << endl;
		cout << "Broj posjeta: " << brojPosjeta << endl;

		for (int i = 0; i < brojPosjeta; i++)
			preglediPacijenta[i]->ispis();
	}

	void addPregled() {

		cout << "Ime i prezime: " << imePrezime << endl;
		cout << "Posjeta br: " << brojPosjeta + 1 << endl;

		preglediPacijenta[brojPosjeta] = new Pregled;
		preglediPacijenta[brojPosjeta++]->unos();
	}

	double getUkupneTroskove() {
		double suma = 0;

		for (int i = 0; i < brojPosjeta; i++)
			suma += preglediPacijenta[i]->cijenaPregleda;

		return suma;
	}
};

void povratNovca(Pacijent *pok, int max) {
	double kriteriji;

	cout << "Unesite sumu za kriteriji: ";
	cin >> kriteriji;
	cin.ignore();

	for (int i = 0; i < max; i++) {
		double suma = 0;
		for (int j = 0; j < pok[i].brojPosjeta; j++) {
			if (pok[i].preglediPacijenta[j]->cijenaPregleda > kriteriji) {
				suma += pok[i].preglediPacijenta[j]->cijenaPregleda * 0.10;
				pok[i].preglediPacijenta[j]->cijenaPregleda -= pok[i].preglediPacijenta[j]->cijenaPregleda * 0.10;
			}
		}
		pok[i].ispis();
		cout << "Iznos povrata: " << suma << endl;
	}
}

void PretragaPoDijagnozi(Pacijent *pok, int max) {
	char pretraga[30]; 
	int brojPacijenata = 0;

	cout << "Unesite dijagnozu za pretragu: " << endl;
	cin.getline(pretraga, 30);

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < pok[i].brojPosjeta; j++) {
			if (!strcmp(pretraga, pok[i].preglediPacijenta[j]->dijagnoza)) {
				cout << pok[i].imePrezime << endl;
				brojPacijenata++;
				break;
			}
		}
	}

	cout << "Broj pacijenata sa datom dijagnozom: " << brojPacijenata << endl;
}

int main() {

	int max;

	cout << "Unesite zeljeni broj pacijenata: ";
	cin >> max;
	cin.ignore();

	Pacijent *niz = new Pacijent[max];

	for (int i = 0; i < max; i++)
		niz[i].unos();

	for (int i = 0; i < max; i++)
		for (int j = 0; j < 3; j++)
			niz[i].addPregled();

	PretragaPoDijagnozi(niz, max);
	povratNovca(niz, max);

	system("pause");
	return 0;
}