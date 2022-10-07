#include "MillerRabin.h"

MillerRabin::MillerRabin(unsigned int n) {
    numTrials = n;
}

bool MillerRabin::isValid(BigInt prime) {
	BigInt maxDivisionsByTwo(2);
	BigInt evenComponent(prime - BigInt(1));

    //cout << evenComponent << endl;

	while (evenComponent % BigInt(2) == BigInt()) {
        
		evenComponent /= BigInt(2); // substitution for >>= 1, i assumed that comes down to the same thing
		maxDivisionsByTwo += BigInt(1);
	}

	if ((BigInt(2) ^ maxDivisionsByTwo) * evenComponent != prime - BigInt(1)) {
		return false;
	}

	for (int i = 0; i < numTrials; i++) {
		BigInt round_tester(long(0));
		long random = rand() % 100;
		BigInt randomBigInt(random);
		round_tester = (randomBigInt * (prime - BigInt(2)) + BigInt(2)) / BigInt(100);

		if (trialComposite(round_tester, evenComponent, prime, maxDivisionsByTwo)) {
			return false;
		}
	}

	return true;
}

bool MillerRabin::trialComposite(BigInt roundTester, BigInt evenComponent, BigInt prime, BigInt maxDivisionsByTwo) {

    if (powMod(roundTester, evenComponent, prime) == BigInt(1)) {
        return false;
    }

    for (int i = 0; i < maxDivisionsByTwo; i++) {
        BigInt a((long)pow(2, i));
        if (powMod(roundTester, a * evenComponent, prime) == BigInt(prime - BigInt(1))) {
            return false;
        }
    }

    return true;
}

BigInt MillerRabin::powMod(BigInt b, BigInt e, BigInt m) {
    if (m == BigInt(1)) return BigInt();

    BigInt result(1);

    b %= m;

    while (e > BigInt()) {
        if (e % BigInt(2) == BigInt(1)) {
            result = (result * b) % m;
        }
        e /= BigInt(2);
        b = (b * b) % m;
    }
    return result;
}