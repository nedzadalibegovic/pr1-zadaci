#include <iostream>
using namespace std;

int rekurzija(int *niz, int max) {
	if (max <= 0)
		return 0;
	if ((max - 1) % 2 == 0)
		return niz[max - 1] + rekurzija(niz, max - 2);
	return rekurzija(niz, max - 1);
}

int main() {

	int max;

	cout << "Unesite koliko zelite brojeva unijeti: ";
	cin >> max;

	int *niz = new int[max];

	for (int i = 0; i < max; i++)
		cin >> niz[i];

	cout << "Suma brojeva sa parnim indeksom: " << rekurzija(niz, max) << endl;

	system("pause");
	return 0;
}