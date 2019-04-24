/*Napišite program koji omogućava unos prirodnih brojeva n i m preko tastature te izračunava umnožak*/
/*S= (n+m) * (n-2*m) * (n+3*m) *...* (n+(-1)^m+1*m*m)*/

#include<iostream>
#include<cmath>

using namespace std;

int brojCifara(int);
int zamjenaCifara(int);
int umnozak(int, int);

int main() {

	int n, m;

	do {
		cout << "Unesite n: ";
		cin >> n;
	} while (!(n > 0));

	do {
		cout << "Unesite m: ";
		cin >> m;
	} while (!(m > 0));

	cout << "S= " << umnozak(n, m) << endl;
	
	system("pause");
	return 0;

}

int brojCifara(int broj) {

	int counter = 0;
	
	while (broj > 0) {
		broj /= 10;
		counter++;
	}

	return counter;
}

int zamjenaCifara(int broj) {

	int temp = 0, noviBroj = 0;

	while (broj > 0) {
		temp = broj % 10;
		noviBroj = noviBroj * 10 + temp;
		broj /= 10;
	}

	return noviBroj;
}

int umnozak(int n, int m) {

	int suma = 1;
	
	for (int i = 1; i <= m; i++) {
		suma *= n + pow(-1, i + 1)*i*m;
	}

	return suma;
}
