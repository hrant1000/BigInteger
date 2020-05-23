#include "big_integer.h"

BigInteger::BigInteger() 
{
	sign_ = true;
	size_ = 1;
	words_ = new Word[size_];
	for (int i = 0; i < size_; ++i)
	{
		words_[i] = 0;
	}
}

BigInteger::BigInteger(const std::string& num) 
{
	if (num.size() == 0)
	{
		sign_ = true;
		size_ = 1;
		words_ = new Word[size_];
		for (int i = 0; i < size_; ++i)
		{
			words_[i] = 0;
		}
		return;
	}

	sign_ = true;
	int digit_start = 0;
	int digit_end = num.size() - 1;
	if (num[0] == '-')
	{
		sign_ = false;
		digit_start = 1;	
	}
	else if (num[0] == '+')
	{
		digit_start = 1;	
	}
	size_ = (digit_end - digit_start + WORD_DIGIT_CNT) / WORD_DIGIT_CNT;
	words_ = new Word[size_];
	int i = size_ - 1;
	int j = digit_end;
	while (j >= digit_start)
	{
		int k = j - WORD_DIGIT_CNT + 1;
		if (k < digit_start)
		{
			k = digit_start;
		}
		std::string w = num.substr(k, j - k + 1);
		words_[i] = std::stoll(w);
		j = k - 1;
		--i;
	}
}

BigInteger::BigInteger(const long long num)
	: BigInteger(std::to_string(num))
{
}

BigInteger::BigInteger(const unsigned long long num)
	: BigInteger(std::to_string(num))
{
}

BigInteger::~BigInteger()
{
	delete[] words_;
}

std::ostream& operator<<(std::ostream& os, const BigInteger& num)
{
	if (!num.sign_)
	{
		os << '-';
	}
	for (int i = 0; i < num.size_; ++i)
	{
		os << num.words_[i];
	}
	return os;
}

