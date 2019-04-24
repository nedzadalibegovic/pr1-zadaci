#include <iostream>
using namespace std;

struct Datum {
	int dan, mjesec, godina;

	void unos() {
		cout << "Dan: ";
		cin >> dan;
		cout << "Mjesec: ";
		cin >> mjesec;
		cout << "Godina: ";
		cin >> godina;
	}
};

struct Student {
	char imePrezime[30];
	int godinaStudija;
	Datum datumRodjenja;
};

void unos(Student &obj) {
	cout << "Unesite ime i prezime: ";
	cin.getline(obj.imePrezime, 30);

	cout << "Unesite godinu studija: ";
	cin >> obj.godinaStudija;

	cout << "Unesite datum rodjenja: ";
	obj.datumRodjenja.unos();
	cin.ignore();
}

bool isDatumEq(const Datum &datum1, const Datum &datum2) {
	if (datum1.dan == datum2.dan)
		if (datum1.mjesec == datum2.mjesec)
			if (datum1.godina == datum2.godina)
				return true;
	return false;
}

bool Provjera(const Student &student1, const Student &student2) {
	if (!strcmp(student1.imePrezime, student2.imePrezime))
		if (student1.godinaStudija == student2.godinaStudija)
			if (isDatumEq(student1.datumRodjenja, student2.datumRodjenja))
				return true;
	return false;
}

int getBrojChar(const Student &student) {
	auto br = 0;
	for (int i = 0; i < strlen(student.imePrezime); i++) {
		if (student.imePrezime[i] != ' ')
			br++;
	}
	return br;
}

int main() {
	Student Hamo, Pipa;

	unos(Hamo);
	unos(Pipa);

	cout << Provjera(Hamo, Pipa) << endl;

	cout << getBrojChar(Hamo) << endl;

	system("pause");
	return 0;
}