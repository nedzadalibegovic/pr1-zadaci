#include <iostream>
using namespace std;

void unos(int **, int, int);
void ispis(int **, int, int);
int suma(int **, int, int);
int sumaPozitivnih(int **, int, int);
int sumaParnihIndeksa(int **, int, int);


int main() {

	int brojRedova, brojKolona;
	int **matrica = nullptr;

	cout << "Unesite broj redova u matrici: ";
	cin >> brojRedova;
	cin.ignore();

	matrica = new int *[brojRedova];

	cout << "Unesite broj kolona u matrici: ";
	cin >> brojKolona;
	cin.ignore();

	for (int i = 0; i < brojRedova; i++)
		matrica[i] = new int[brojKolona];

	unos(matrica, brojRedova, brojKolona);
	cin.ignore();
	ispis(matrica, brojRedova, brojKolona);
	cout << "Suma svih elemenata: " << suma(matrica, brojRedova, brojKolona) << "\n";
	cout << "Suma pozitivnih elemenata: " << sumaPozitivnih(matrica, brojRedova, brojKolona) << "\n";
	cout << "Suma elemenata sa parnim indeksom: " << sumaParnihIndeksa(matrica, brojRedova, brojKolona) << "\n";

	// DEALOKACIJA
	for (int i = 0; i < brojRedova; i++) {
		delete[] matrica[i];
		matrica[i] = nullptr;
	}
	delete[] matrica;
	matrica = nullptr;

	cin.get();
	return 0;
}

void unos(int **matrica, int brojRedova, int brojKolona) {
	static int i = 0, j = 0;

	if (j == brojKolona) {
		j = 0;
		i++;
	}
	if (i == brojRedova)
		return;

	cout << "[" << i << "." << j << "]->";
	cin >> matrica[i][j++];

	unos(matrica, brojRedova, brojKolona);
}

void ispis(int **matrica, int brojRedova, int brojKolona) {
	static int i = 0, j = 0;

	if (j == brojKolona) {
		j = 0;
		i++;
		cout << "\n";
	}
	if (i == brojRedova)
		return;

	cout << matrica[i][j++] << " ";
	ispis(matrica, brojRedova, brojKolona);
}

int suma(int **matrica, int brojRedova, int brojKolona) {
	static int i = 0, j = 0, sum = 0;

	if (j == brojKolona) {
		j = 0;
		i++;
	}
	if (i == brojRedova)
		return 0;
	//return matrica[i][j++] + suma(matrica, brojRedova, brojKolona); // ne moze u VS
	sum += matrica[i][j++];
	suma(matrica, brojRedova, brojKolona);
	return sum;
}

int sumaPozitivnih(int **matrica, int brojRedova, int brojKolona) {
	static int i = 0, j = 0, sum = 0;

	if (j == brojKolona) {
		j = 0;
		i++;
	}
	if (i == brojRedova)
		return 0;
	
	if (matrica[i][j] > 0) {
		sum += matrica[i][j++];
		sumaPozitivnih(matrica, brojRedova, brojKolona);
	}
	else {
		j++;
		sumaPozitivnih(matrica, brojRedova, brojKolona);
	}
	return sum;
}
int sumaParnihIndeksa(int **matrica, int brojRedova, int brojKolona) {
	static int i = 0, j = 0, sum = 0;

	if (j == brojKolona) {
		j = 0;
		i++;
	}
	if (i == brojRedova)
		return 0;

	if (i % 2 == 0 && j % 2 == 0) {
		sum += matrica[i][j++];
		sumaParnihIndeksa(matrica, brojRedova, brojKolona);
	}
	else {
		j++;
		sumaParnihIndeksa(matrica, brojRedova, brojKolona);
	}
	return sum;
}