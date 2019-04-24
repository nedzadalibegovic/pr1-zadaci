/*Napišite program, poštujući sve faze procesa programiranja, u kojem ćete unijeti jedan
prirodan broj koji predstavlja vrijeme u minutama, a izračunati i ispisati koliko je to
vremena u danima, satima i minutama.*/

#include<iostream>
using namespace std;

void dani(int);

int main() {

	int vrijeme;

	cout << "Unesite vrijeme u minutama: ";
	cin >> vrijeme;

	// 60 min = 1 sat
	// 1440 min = 1 dan

	dani(vrijeme);

	system("pause");
	return 0;

}

void dani(int vrijeme) {

	int dani, sati, minute;

	dani = vrijeme / 1440;
	sati = (vrijeme % 1440) / 60;
	minute = (vrijeme % 1440) % 60;

	cout << "Dani: " << dani << ", sati: " << sati << ", minute: " << minute << endl;

}
