#include <iostream>
using namespace std;

void rekurzija(char znak1, char znak2, int i) {
	if (znak1 > znak2)
		rekurzija(znak2, znak1, i);
	if (znak1 == znak2 - 1) {
		cout << "Ukupno ispisano " << i << " znaka.\n";
		return;
	}
	cout << "Znak => " << --znak2 << endl;
	rekurzija(znak1, znak2, i + 1);
}

int main() {

	rekurzija('a', 'e', 0);

	system("pause");
	return 0;
}