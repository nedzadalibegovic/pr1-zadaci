#include <iostream>
#include <algorithm>
using namespace std;

int euklid(int a, int b) {
	if (a == 0)
		return b;
	return euklid(b%a, a);
}

int main() {

	int(*pok)(int, int) = euklid;
	int max, suma = 0;

	cout << "Koliko zelite unijeti brojeva: ";
	cin >> max;

	int *niz = new int[max];

	for (int i = 0; i < max; i++)
		cin >> niz[i];

	sort(niz, niz + max);

	for (int i = 1; i < max; i++)
		suma+= pok(niz[i - 1], niz[i]);

	cout << "Suma NZD vrijednosti je: " << suma << endl;

	system("pause");
	return 0;
}