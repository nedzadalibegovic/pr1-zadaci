#include <iostream>
using namespace std;

// ispitni 5

int main() {

	int max;

	cout << "Unesite koliko zelite unijeti brojeva: ";
	cin >> max;

	int *niz = new int[max];

	for (int i = 0; i < max; i++)
		cin >> niz[i];



	system("pause");
	return 0;
}