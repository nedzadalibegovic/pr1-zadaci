#include<iostream>
using namespace std;

// funkcije
void prolaznost();
void prosjek();
bool prosao(int);

// konstante
const int broj_studenata = 7;

// nizovi
int uspjeh[broj_studenata];

int main() {

	cout << "Unesite broj bodova postignutih na ispitu (od 0 do 100)" << endl;

	// nizovi pocinju uvijek od 0
	for (int i = 0; i < broj_studenata; i++) {

		do {

			cout << "Student " << i + 1 << ": ";
			cin >> uspjeh[i];

		// dozvoliti samo unos izmedju 0 i 100
		} while (!(uspjeh[i] >= 0 && uspjeh[i] <= 100));

	}

	prolaznost();
	prosjek();

	system("pause");
	return 0;

}

void prolaznost() {

	int polozili = 0, pali = 0;

	for (int i = 0; i < broj_studenata; i++) {

		if (prosao(uspjeh[i])) {

			polozili++;

		}

		else {

			pali++;

		}

	}

	// ukoliko je više od polovice studenata bilo neuspjesno na ispitu
	if (pali > (broj_studenata / 2)) {

		cout << "Potrebno vise sati instrukcija!" << endl;

	}

	cout << "Broj studenata koji su bili uspjesni na ispitu: " << polozili << endl;
	cout << "Broj studenata koji su bili neuspjesni na ispitu: " << pali << endl;

}

void prosjek() {

	float suma = 0;
	int br = 0;

	for (int i = 0; i < broj_studenata; i++) {

		if (prosao(uspjeh[i])) {

			suma += uspjeh[i];
			br++;

		}

	}

	float ars = suma / br;

	cout << "Prosjecan broj bodova za uspjesne studente: " << ars << endl;

}

bool prosao(int broj) {

	if (broj > 60) {

		return true;

	}

	return false;

}
