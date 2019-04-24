#include<iostream>
using namespace std;

float suma(int, int);

int main() {

	int brojN, brojM;

	do {
		cout << "Unesite broj n: ";
		cin >> brojN;
	} while (!(brojN > 0));

	do {
		cout << "Unesite broj m: ";
		cin >> brojM;
	} while (!(brojM > 0));

	cout << "S = " << suma(brojN, brojM) << endl;

	system("pause");
	return 0;

}

float suma(int n, int m) {

	float sum = 0;

	for (int i = 1; i <= m; i++) {
		sum += pow(-1, i + 1) * (float(1) / (n + i * m));
	}

	return sum;
}
