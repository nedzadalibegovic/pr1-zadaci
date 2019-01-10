#include <iostream>
using namespace std;

int decimal(int num) {
	static int x = 0;
	if (num == 0)
		return 0;
	return (num % 10)*pow(2, x++) + decimal(num / 10);
}

int main() {

	int num;

	cout << "Unesite binarni broj: ";
	cin >> num;
	cin.ignore();

	cout << "Dekadni ekvivalent: " << decimal(num) << "\n";

	cin.get();
	return 0;
}