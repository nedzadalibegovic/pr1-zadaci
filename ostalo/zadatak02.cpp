#include <iostream>

using namespace std;

bool samoglasnik(char);

int main() {

	int ogr;

	char znakovi[100];

	cout << "Unesite koliko zelite znakova unijeti: ";
	cin >> ogr;

	for (int i = 0; i < ogr; i++) {
		cout << i + 1 << " -> ";
		cin >> znakovi[i];
	}

	int samoglasnici = 0, konsonanti = 0, ostali = 0;

	for (int i = 0; i < ogr; i++) {
		if (isalpha(znakovi[i])) {
			if (samoglasnik(znakovi[i]))
				samoglasnici++;
			else
				konsonanti++;
		}
		else
			ostali++;
	}

	cout << "Vokali: " << samoglasnici << endl;
	cout << "Konsonanti: " << konsonanti << endl;
	cout << "Ostali znakovi: " << ostali << endl;

	system("pause");
	return 0;
}

bool samoglasnik(char znak) {

	switch (znak) {
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			return true;
			break;
	}

	return false;
}
