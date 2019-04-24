/*Napišite program kojim se za uneseni datum (dan, mjesec i godina) određuje koji je to
redni broj dana u godini. Voditi računa da godina može biti i prijestupna. Omogućite
korisniku da ponavlja unos datuma.
Npr: ako korisnik unese 15 2 2018 program treba ispisati uneseni dan je 46. dan u 2018
godini.*/

#include<iostream>
using namespace std;

int mjeseci(int);
bool prestupna(int);

int dan, mjesec, godina;

int main() {

	cout << "Unesite datum (format: dd mm gggg): ";
	cin >> dan >> mjesec >> godina;

	int suma = dan;

	for (int i = 1; i < mjesec; i++) {

		suma += mjeseci(i);

	}

	cout << "Uneseni datum je " << suma << ". dan u " << godina << ". godini." << endl;

	system("pause");
	return 0;

}

bool prestupna(int godina) {

	if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) {

		return true;

	}

	return false;

}

int mjeseci(int mjesec) {

	int temp = 0;

	switch (mjesec)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: {

			temp = 31;
			break;

		}

		case 2: {

			if (prestupna(godina)) {

				temp = 29;
				break;

			} 

			else {

				temp = 28;
				break;

			}
			
		}

		case 4:
		case 6:
		case 9:
		case 11: {

			temp = 30;
			break;

		}

		default:
			break;
	}

	return temp;

}
