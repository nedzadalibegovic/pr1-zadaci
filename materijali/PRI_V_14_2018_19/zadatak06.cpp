#include <iostream>
using namespace std;

struct obuca {
	int velicina;
	char boja[11];
	char model[20];

	void unos() {
		cout << "Unesite velicinu: ";
		cin >> velicina;
		cout << "Unesite boju: ";
		cin >> boja;
		cout << "Unesite model: ";
		cin >> model;
	}

	void ispis() {
		cout << "Velicina: " << velicina << endl;
		cout << "Boja: " << boja << endl;
		cout << "Model: " << model << endl;
	}
};

bool provjeraSandale(obuca);
int prebrojSandale(obuca[], int);
void adresaSandale(obuca[], int);

int main() {

	int brojObj = 0;
	obuca *nizObj = nullptr;

	cout << "Unesite zeljeni broj objekata: ";
	cin >> brojObj;

	nizObj = new obuca[brojObj];

	for (int i = 0; i < brojObj; i++)
		nizObj[i].unos();

	cout << "Broj objekata tipa sandale: " << prebrojSandale(nizObj, brojObj) << endl;
	cout << "Adrese objekata tipa sandale: " << endl;
	adresaSandale(nizObj, brojObj);

	delete[] nizObj;

	cin.ignore();
	cin.get();
	return 0;
}

bool provjeraSandale(obuca test) {
	char comp[8] = "sandale";
	return !strcmp(test.model, comp);
}

int prebrojSandale(obuca niz[], int vel) {
	int br = 0;
	for (int i = 0; i < vel; i++)
		if (provjeraSandale(niz[i]))
			br++;
	return br;
}

void adresaSandale(obuca niz[], int vel) {
	for (int i = 0; i < vel; i++)
		if (provjeraSandale(niz[i]))
			cout << &niz[i] << endl;
}