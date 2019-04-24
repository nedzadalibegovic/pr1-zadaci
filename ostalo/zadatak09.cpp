#include<iostream>
#include<iomanip>
using namespace std;

int fib(int);
double suma(int, int);

int main() {

	int x, n;

	cin >> x >> n;

	cout << setprecision(4) << suma(x, n) << endl;

	system("pause");
	return 0;

}

int fib(int broj) {

	int a = 0, b = 1, c;

	for (int i = 0; i <= broj; i++) {

		if (i <= 1) {

			c = i;

		}

		else {

			c = a + b;
			a = b;
			b = c;

		}
		
	}

	return c;

}

double suma(int x, int n) {

	double sum = 0;

	for (int i = 0; i <= n; i++) {

		sum += (fib(i) + x) / pow((x + i), i + 1);

	}

	return sum;

}
