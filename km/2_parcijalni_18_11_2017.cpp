/*Napisati program koji omogucava unos pozitivnog broja n te pronalazi njegove parne cifre i formira novi
broj u kojem su parne cifre zamijenjene cifrom '5'. Dodatno program treba ispisati razliku unesenog i broja
koji se dobije nakon zamjene cifara.*/

#include <iostream>
using namespace std;

int zamjena(int);

int main() {

	int broj,promjena;

	do {

		cout << "Unesite pozitivan broj: ";
		cin >> broj;

	} 
	
	while (broj < 1);

	promjena = zamjena(broj);

	cout << "Izmjenjeni broj: " << promjena << endl;
	cout << "Razlika unesenog i izmjenjenog broja je: " << promjena - broj << endl;
		 
	system("pause");
	return 0;

}

int zamjena(int broj) {

	int novi = 0, temp = 0, pw=0;

	while (broj > 0) {

		temp = broj % 10;

		if (temp % 2 == 0) {

			novi += 5 * pow(10, pw);

		}

		else {

			novi += temp * pow(10, pw);

		}

		broj /= 10;
		pw++;

	}

	return novi;

}
