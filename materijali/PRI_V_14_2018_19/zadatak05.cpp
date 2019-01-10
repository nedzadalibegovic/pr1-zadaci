#include <iostream>
#include <string>
using namespace std;

struct Obuca {
	int velicina;
	char boja[10];
	char model[20];
};

void unos(Obuca *, int);
void ispis(Obuca *, int);
int provjeraSandale(Obuca *, int);

int main() {

	int brojObj = 0, brojSandala = 0;
	Obuca *nizObj = nullptr;

	cout << "Unesite zeljeni broj objekata: ";
	cin >> brojObj;
	cin.ignore();

	nizObj = new Obuca[brojObj];
	
	unos(nizObj, brojObj);
	ispis(nizObj, brojObj);

	cout << "Adrese sandala:\n";
	brojSandala = provjeraSandale(nizObj, brojObj);

	cout << "Broj sandala: " << brojSandala << "\n";

	// DEALOKACIJA
	delete[] nizObj;
	nizObj = nullptr;

	cin.get();
	return 0;
}

void unos(Obuca *niz, int vel) {
	for (int i = 0; i < vel; i++) {
		cout << "Unesite velicinu: ";
		cin >> (niz + i)->velicina;
		cin.ignore();

		cout << "Unesite boju: ";
		cin.getline(niz[i].boja, 10);

		cout << "Unesite model: ";
		cin.getline((*(niz+i)).model, 20);
	}
}

void ispis(Obuca *niz, int vel) {
	for (int i = 0; i < vel; i++) {
		cout << "Velicina: " << (niz + i)->velicina << "\n";
		cout << "Boja: " << niz[i].boja << "\n";
		cout << "Model: " << (*(niz + i)).model << "\n";
	}
}

int provjeraSandale(Obuca *niz, int vel) {
	cout << "Pozvana je funkcija!" << "\n";
	int br = 0;
	for (int i = 0; i < vel; i++) {
		if (!strcmp("sandale", niz[i].model)) {
			//cout << &niz[i];
			cout << (niz + i) << "(" << niz[i].boja << ")\n";
			br++;
		}
	}
	return br;
}