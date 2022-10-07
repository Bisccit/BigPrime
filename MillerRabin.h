#pragma once

#include "BigInt.h";

class MillerRabin
{
private:
	int numTrials;

public:
	MillerRabin();

	~MillerRabin();

	bool isValid(BigInt prime);

	bool trialComposite(BigInt roundTester, BigInt evenComponent, BigInt prime, BigInt maxDivisionsByTwo);

	bool powMod(BigInt b, BigInt e, BigInt m);
};

