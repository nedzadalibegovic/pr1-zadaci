/*Napišite program, poštujući sve faze procesa programiranja, koji za uneseni prirodni
broj n i realni broj x izračunava:
S=cos(x) + cos^2(x) + cos^3(x) + … + cos^n(x)*/

#include<iostream>
using namespace std;

int main() {

	int n;
	float x, suma = 0;

	cout << "Unesite prirodni broj n: ";
	cin >> n;

	cout << "Unesite realan broj x: ";
	cin >> x;

	for (int i = 1; i <= n; i++) {

		suma += pow(cos(x),i);

	}

	cout << "S = " << suma << endl;

	system("pause");
	return 0;

}
