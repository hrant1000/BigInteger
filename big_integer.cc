#include "big_integer.h"

BigInteger::BigInteger()
{
	size_ = 1;
	digits_ = new WordType[size_];
	for (int i = 0; i < size_; ++i)
	{
		digits_[i] = 0;
	}
	sign_ = true;
}

BigInteger::~BigInteger()
{
	delete[] digits_;
}
