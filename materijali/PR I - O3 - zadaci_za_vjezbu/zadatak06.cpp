/*Napišite program, poštujući sve faze procesa programiranja, koji omogućava unos
prirodnog broja n preko tastature te izračunava sumu.*/

#include<iostream>
using namespace std;

int main() {

	int n;
	float suma = 0;

	cout << "Unesite prirodni broj n: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {

		suma += 1 / pow((2*i + 1), 2);

	}

	cout << "S: " << suma << endl;

	system("pause");
	return 0;

}
