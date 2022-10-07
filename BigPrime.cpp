#include "BigPrime.h"

BigPrime::BigPrime(int n) {
	maxTries = n;
}

BigInt BigPrime::generatePrime(int n) {
	BigInt res(-1);
	int x = 0;

	while (x < maxTries) {
		x++;

		BigInt max((long)0);
		BigInt min((long)0);
		BigInt primeCandidate(long(0));
		BigInt hundred(100);

		max = (BigInt(2) ^ BigInt(n)) - BigInt(1);
		min = (BigInt(2) ^ BigInt(n-1)) + BigInt(1);

		long random = rand() % 100;

		BigInt randomBigInt(random);

		primeCandidate = (randomBigInt * (max - min) + min) / BigInt(100);

		if (!isPrime(primeCandidate)) {
			continue;
		}
		else {
			return primeCandidate;
		}
	}
	return res;
}

bool BigPrime::isPrime(BigInt prime) {
	bool found = false;

	long firstPrimes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
		31, 37, 41, 43, 47, 53, 59, 61, 67,
		71, 73, 79, 83, 89, 97, 101, 103,
		107, 109, 113, 127, 131, 137, 139,
		149, 151, 157, 163, 167, 173, 179,
		181, 191, 193, 197, 199, 211, 223,
		227, 229, 233, 239, 241, 251, 257,
		263, 269, 271, 277, 281, 283, 293,
		307, 311, 313, 317, 331, 337, 347, 349 };

	for (int i = 0; i < sizeof(firstPrimes) / sizeof(long); i++) {
		if ((prime % BigInt(firstPrimes[i]) == BigInt((long)0)) && (BigInt(firstPrimes[i]) ^ BigInt('2')) <= prime) {
			found = true;
		}
	}

	if (found) {
		return false;
	}

	// miller rabin
	MillerRabin millerRabin(20);

	if (!millerRabin.isValid(prime)) {
		return false;
	}

	return true;
}