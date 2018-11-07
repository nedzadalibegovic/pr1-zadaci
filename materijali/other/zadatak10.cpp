#include<iostream>
using namespace std;

bool dobar(int);

const int velicina = 10;

int main() {

	int n;

	int niz_0[velicina] = {}, niz_1[velicina] = {};

	cout << "Unesite koliko zelite brojeva unijeti (max. 10): ";
	cin >> n;

	for (int i = 0; i < n; i++) {

		cout << i + 1 << "->";
		cin >> niz_0[i];

	}

	int i = 0, j = 0;

	do {

		if (dobar(niz_0[i])) {

			niz_1[j] = niz_0[i];
			j++;

		}

		i++;

	} while (i < n);

	cout << "Velicina novog niza: " << j << endl;

	for (i = 0; i < j; i++) {

		cout << niz_1[i] << endl;

	}

	system("pause");
	return 0;

}

bool dobar(int broj) {

	int suma = 0;

	while (broj > 0) {

		int temp = broj % 10;

		if (temp < suma) {
			
			return false;
		
		}
		
		suma += temp;
		broj /= 10;

	}

	return true;

}
