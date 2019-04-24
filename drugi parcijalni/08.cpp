#include <iostream>
using namespace std;

int rekurzija(char *niz, int max, int i) {
	if (i >= max)
		return 0;
	if (niz[i] == 'a' || niz[i] == 'e')
		return 1 + rekurzija(niz, max, i + 2);
	else
		return rekurzija(niz, max, i + 2);
}

int main() {

	char niz[] = "ehello";
	cout << rekurzija(niz, strlen(niz), 0) << endl;

	system("pause");
	return 0;
}