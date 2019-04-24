#include <iostream>
using namespace std;

int binary(int num) {
	if (num == 0)
		return 0;
	return (num % 2) + binary(num / 2) * 10;
}

int main() {

	int num;

	cout << "Unesite broj: ";
	cin >> num;
	cin.ignore();

	cout << "Binarni ekvivalent: " << binary(num) << "\n";

	cin.get();
	return 0;
}