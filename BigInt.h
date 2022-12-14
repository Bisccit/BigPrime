#pragma once

// This code is contributed
// by Gatea David

#include <iostream>
#include <vector>

using namespace std;

class BigInt
{
	string digits;

public:
	BigInt(unsigned long long n = 0);
	BigInt(string&);
	BigInt(const char*);
	BigInt(BigInt&);

	//Helper Functions:
	friend void divide_by_2(BigInt& a);
	friend bool Null(const BigInt&);
	friend int Length(const BigInt&);
	int operator[](const int)const;

	/* * * * Operator Overloading * * * */

//Direct assignment
	BigInt& operator=(const BigInt&);

	//Post/Pre - Incrementation
	BigInt& operator++();
	BigInt operator++(int temp);
	BigInt& operator--();
	BigInt operator--(int temp);

	//Addition and Subtraction
	friend BigInt& operator+=(BigInt&, const BigInt&);
	friend BigInt operator+(const BigInt&, const BigInt&);
	friend BigInt operator-(const BigInt&, const BigInt&);
	friend BigInt& operator-=(BigInt&, const BigInt&);

	//Comparison operators
	friend bool operator==(const BigInt&, const BigInt&);
	friend bool operator!=(const BigInt&, const BigInt&);

	friend bool operator>(const BigInt&, const BigInt&);
	friend bool operator>=(const BigInt&, const BigInt&);
	friend bool operator<(const BigInt&, const BigInt&);
	friend bool operator<=(const BigInt&, const BigInt&);

	//Multiplication and Division
	friend BigInt& operator*=(BigInt&, const BigInt&);
	friend BigInt operator*(const BigInt&, const BigInt&);
	friend BigInt& operator/=(BigInt&, const BigInt&);
	friend BigInt operator/(const BigInt&, const BigInt&);

	//Modulo
	friend BigInt operator%(const BigInt&, const BigInt&);
	friend BigInt& operator%=(BigInt&, const BigInt&);

	//Power Function
	friend BigInt& operator^=(BigInt&, const BigInt&);
	friend BigInt operator^(const BigInt&, const BigInt&);
	//friend BigInt operator^(BigInt&, const BigInt&);

	//Square Root Function
	friend BigInt sqrt(BigInt& a);

	//Read and Write
	friend ostream& operator<<(ostream&, const BigInt&);
	friend istream& operator>>(istream&, BigInt&);
};

