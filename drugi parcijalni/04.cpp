#include <iostream>
using namespace std;

bool samoglasnik(char &a) {
	switch (a) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}

void prebroji(char *pok, int max) {
	static int samoglasnici = 0;
	static int suglasnici = 0;
	if (max == 0) {
		cout << "Samoglasnici: " << samoglasnici << endl;
		cout << "Suglasnici: " << suglasnici;
		return;
	}
	if (isalpha(pok[max - 1]))
		if (samoglasnik(pok[max - 1])) {
			samoglasnici++;
			prebroji(pok, max - 1);
		}
		else {
			suglasnici++;
			prebroji(pok, max - 1);
		}
	else
		prebroji(pok, max - 1);
}

void prebroji1(char *pok, int max, int i) {
	static int samoglasnici = 0;
	static int suglasnici = 0;
	if (max == i) {
		cout << "Samoglasnici: " << samoglasnici << endl;
		cout << "Suglasnici: " << suglasnici;
		return;
	}
	if (isalpha(pok[i]))
		if (samoglasnik(pok[i])) {
			samoglasnici++;
			prebroji1(pok, max, i+1);
		}
		else {
			suglasnici++;
			prebroji1(pok, max, i+1);
		}
	else
		prebroji1(pok, max, i+1);
}

int main() {

	char *pok = new char[200];

	cout << "Unesite tekst: ";
	cin.getline(pok, 200);

	prebroji(pok, strlen(pok));
	prebroji1(pok, strlen(pok), 0);

	cin.get();
	return 0;
}