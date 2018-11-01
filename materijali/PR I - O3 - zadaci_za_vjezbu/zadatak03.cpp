/*Napišite program, poštujući sve faze procesa programiranja, koji će ispisati sve
četveroznamenkaste brojeve kojima su: sve znamenke neparne i ne sadrži znamenku 0.*/

#include<iostream>
using namespace std;

bool neparan(int);

int main() {

	for (int i = 1000; i <= 9999; i++) {

		if (neparan(i)) {

			cout << i << endl;

		}

	}

	system("pause");
	return 0;

}

bool neparan(int broj) {

	int temp = 0;

	while (broj > 0) {

		temp = broj % 10;

		if (temp % 2 == 0 || temp == 0) {

			return false;

		}

		broj /= 10;

	}

	return true;

}
