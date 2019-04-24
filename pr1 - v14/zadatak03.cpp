#include <iostream>
using namespace std;

// http://www.onemathematicalcat.org/Math/Algebra_II_obj/loans_and_investments.htm#partB

double kamata(double novac, int godine, double procenat) {

	if (godine == 0)
		return novac;
	return (1 + procenat / 100) * kamata(novac, godine - 1, procenat);
}

int main() {

	double novac, procenat;
	int godine;

	cout << "Unesite iznos novca koje zelite uloziti: ";
	cin >> novac;

	cout << "Unesite kamatnu stopu u %: ";
	cin >> procenat;

	cout << "Unesite na koliko godina zelite odlezati novac: ";
	cin >> godine;

	cout << "Na kraju " << godine << ". godine, imat cete " << kamata(novac, godine, procenat) 
		<< " KM.\n";

	cin.ignore();
	cin.get();
	return 0;
}