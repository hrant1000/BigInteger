#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H 

#include <cstdint>
#include <string>

class BigInteger
{
	using WordType = uint_fast32_t;
	using DoubleWordType = uint_fast64_t;

public:
	// constructors, assignment and destructor
	BigInteger();
	explicit BigInteger(const long long num);
	BigInteger(const std::string& num);
	BigInteger(const BigInteger& obj);
	BigInteger(BigInteger&& obj);
	BigInteger& operator=(const BigInteger& obj);
	BigInteger& operator=(BigInteger&& obj);
	~BigInteger();

	// operators
	friend BigInteger operator+(const BigInteger& num1, const BigInteger& num2);  
	
private:
	WordType* digits_;
	int size_;
	bool sign_; // true is +, false is -
};

#endif // BIG_INTEGER_H  

