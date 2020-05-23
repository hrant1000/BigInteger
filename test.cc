#include "big_integer.h"

#include <iostream>

int main()
{
	BigInteger a;
	BigInteger b(1234567890123456789LL);
	BigInteger c(-1234567890123456789LL);
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "c = " << c << "\n";
}

