#include<iostream>
using namespace std;

void zvjezdica(int);
void dolar(int);

int main() {

	char znak;
	int visina;

	cout << "Unesite znak: ";
	cin >> znak;

	cout << "Unesite visinu lika: ";
	cin >> visina;

	if (znak == '*') {

		zvjezdica(visina);

	}

	else if (znak == '$') {

		dolar(visina);

	}

	system("pause");
	return 0;

}

void zvjezdica(int visina) {

	for (int i = 1; i <= visina; i++) {

		for (int j = 1; j <= visina; j++) {

			if (i == 1 || j == visina || i <= j) {

				cout << "*";

			}

			else {

				cout << " ";

			}

		}

		cout << endl;

	}

}

void dolar(int visina) {

	for (int i = 1; i <= visina; i++) {

		for (int j = 1; j <= visina; j++) {

			if (i == visina || j == visina || i + j > visina) {

				cout << "$";

			}

			else {

				cout << " ";

			}

		}

		cout << endl;

	}

}
