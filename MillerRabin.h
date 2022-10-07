#pragma once

#include "BigInt.h";
#include <math.h>

class MillerRabin
{
private:
	int numTrials;

public:
	MillerRabin(unsigned int n = 20);

	bool isValid(BigInt prime);

	bool trialComposite(BigInt roundTester, BigInt evenComponent, BigInt prime, BigInt maxDivisionsByTwo);

	BigInt powMod(BigInt b, BigInt e, BigInt m);
};

