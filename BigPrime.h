#pragma once

#include "BigInt.h";
#include "MillerRabin.h";
#include <cstdlib>;

class BigPrime
{

private:
	int maxTries;

public:
	BigPrime(int n = 1000);

	BigInt generatePrime(int);

	BigInt generateSafePrime(int);

	BigInt generateSignaturePrimePair(int, int);

	bool isPrime(BigInt);
};

