#include<iostream>
using namespace std;

int main() {

	const float g = 9.81;
	int t = 3;
	

	for (int i = 1; i <= 20; i++, t += 3) {

		float s = (g / 2)*pow(t, 2);
		float v = g * t;

		cout << "Situacija u " << t << "-oj sekundi je: " << endl;
		cout << "Brzina: " << v << endl;
		cout << "Predjeni put: " << s << endl;


	}

	system("pause");
	return 0;

}
