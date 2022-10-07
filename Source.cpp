#include <iostream>
#include "BigPrime.h";

using namespace std;

#define MAX 1024
#define MIN 160

int main() {
	cout << "Hello world" << endl;

	BigPrime main(1000);


	BigInt a(16);
	BigInt b(17);

	a /= BigInt(2);
	b /= BigInt(2);

	cout << a << endl << b << endl;

	cout << main.generatePrime(1024) << endl;

	return 0;
}