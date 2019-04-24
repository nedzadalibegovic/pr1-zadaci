#include<iostream>
#include<cmath>
using namespace std;

int brojCifara(int);
int svakiTreci(int);

int main() {

	int broj;

	do {

		cout << "Unesite pozitivan cijeli broj: ";
		cin >> broj;

	} while (!(broj > 0));

	cout << "Suma svake trece cifre je: " << svakiTreci(broj) << endl;

	system("pause");
	return 0;

}

int brojCifara(int broj) {

	int temp = 0;

	while (broj > 0) {
		broj /= 10;
		temp++;
	}
	return temp;
}

int svakiTreci(int broj) {

	int suma = 0, eks = brojCifara(broj);

	while (eks-- > 0) {

		suma += broj / int(pow(10, eks)) % 10;
		eks -= 2;

	}

	return suma;
}
