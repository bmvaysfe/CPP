//
//	prime sieve
//	test of bitset data type
//
//	Described in Chapter 12 of
//	Data Structures in C++ using the STL
//	Published by Addison-Wesley, 1997
//	Written by Tim Budd, budd@cs.orst.edu
//	Oregon State University
//
#include<iostream>
# include <string>
# include "bitset.h"
using namespace std;
//
//	sieve of Erastosthenes
//		algorithm for finding prime numbers
//		following execution,
//		one values in bit vector represent primes
//
//const unsigned int maxValue = 1000;

//   Sieves of Eratosphenes: O(n(log(log(n))) complexity

const unsigned int maxValue = 10;   //  For testing only, B.V., 12/01/14
void sieve(bitset<maxValue> & values)
{
	// first initialize all cells
	values.set();

	// now search for non-zero cells
	for (int i = 2; i*i <= maxValue; i++) {
		if (values.test(i)) {
			// inv: i has no factors 
			for (int j = i + i; j < maxValue; j += i) 
				values.reset(j);
			// inv: all multiples of i have been cleared
			}
		// all nonzero values smaller than i are prime
		}
	// inv: all nonzero values are prime
}
int main() 
{
	bitset<maxValue> bits;
	sieve(bits);
	for (int i = 0; i < maxValue; i++)
		if (bits.test(i))
			cout << i << " is prime\n";
    return 0;
}
