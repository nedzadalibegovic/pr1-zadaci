#include <iostream>
using namespace std;

const int VEL = 5;

bool vertikalna(int matrica[][VEL]);
bool horizontalna(int matrica[][VEL]);
bool glavna(int matrica[][VEL]);
bool sporedna(int matrica[][VEL]);

int main() {
	
	int matrica[VEL][VEL] = {};

	for (int i = 0; i < VEL; i++)
		for (int j = 0; j < VEL; j++)
			cin >> matrica[i][j];

	for (int i = 0; i < VEL; i++) {
		for (int j = 0; j < VEL; j++)
			cout << matrica[i][j] << " ";
		cout << endl;
	}

	if (vertikalna(matrica) &&
		horizontalna(matrica) &&
		glavna(matrica) &&
		sporedna(matrica))
		cout << "Matrica je centralno simetricna!" << endl;
	else
		cout << "Matrica nije centralno simetricna!" << endl;

	system("pause");
	return 0;
}

bool vertikalna(int matrica[][VEL]) {
	bool flag = false;
	int centar = int(VEL / 2);
	for (int i = 1; i <= centar; i++) {
		if (matrica[centar + i][centar] == matrica[centar - i][centar])
			flag = true;
		else
			return false;
	}
	return flag;
}

bool horizontalna(int matrica[][VEL]) {
	bool flag = false;
	int centar = int(VEL / 2);
	for (int i = 1; i <= centar; i++) {
		if (matrica[centar][centar + i] == matrica[centar][centar - i])
			flag = true;
		else
			return false;
	}
	return flag;
}

bool glavna(int matrica[][VEL]) {
	bool flag = false;
	int centar = int(VEL / 2);
	for (int i = 1; i <= centar; i++) {
		if (matrica[centar - i][centar - i] == matrica[centar + i][centar + i])
			flag = true;
		else
			return false;
	}
	return flag;
}

bool sporedna(int matrica[][VEL]) {
	bool flag = false;
	int centar = int(VEL / 2);
	for (int i = 1; i <= centar; i++) {
		if (matrica[centar - i][centar + i] == matrica[centar + i][centar - i])
			flag = true;
		else
			return false;
	}
	return flag;
}