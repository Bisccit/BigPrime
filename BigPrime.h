#pragma once

#include "BigInt.h";
#include "MillerRabin.h";
#include <cstdlib>;

class BigPrime
{

private:
	int maxTries;

public:
	BigPrime(int maxTries) {
		this->maxTries = maxTries;
	}

	BigInt generatePrime(int n);

	BigInt generateSafePrime(int n);

	BigInt generateSignaturePrimePair(int N, int L);

	bool isPrime(BigInt prime);
};

