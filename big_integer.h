#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H 

#include <cstdint>
#include <ostream>
#include <string>

class BigInteger
{
	using Word = uint32_t;
	static const int WORD_DIGIT_CNT = 9;
public:
	// constructors, assignment and destructor
	BigInteger();
	explicit BigInteger(const std::string& num);
	explicit BigInteger(const long long num);
	explicit BigInteger(const unsigned long long num);
	BigInteger(const BigInteger& obj);
	BigInteger(BigInteger&& obj);
	BigInteger& operator=(const BigInteger& obj);
	BigInteger& operator=(BigInteger&& obj);
	~BigInteger();

	// operators
	friend std::ostream& operator<<(std::ostream& os, const BigInteger& num);
	friend BigInteger operator+(const BigInteger& num1, const BigInteger& num2);  
	
private:
	bool sign_; // true is +, false is -
	int size_;
	Word* words_;
};

#endif // BIG_INTEGER_H  

