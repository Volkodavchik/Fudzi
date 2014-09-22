/**
 *	@file algebra_elementary.hpp
 *	@brief Self education project. Focus on interesting algorithms
 *	@author Ivan Deviatkin <devyatkin.ivan@gmail.com>
**/

#pragma once

#include <algorithm>

namespace Fudzi
{
/*
 * Class stores algorithms related to strings operations
 */
class AlgebraElementary
{
private:
protected:
public:
	//! @brief Euler function calculation
	//! @param n natural upper border
	//! @return total amount of simple numbers with n in range [0;n)
	static int phi(int n);
	//! @brief Binary power a^n
	//! @param a number
	//! @param n power
	//! @return value a^n
	static int binpow(int a, int n);
	//! @brief Binary power a^n faster version
	//! @param a number
	//! @param n power
	//! @return value a^n
	static int binpowEx(int a, int n);
	//! @brief Greatest common divisor, Euklid algorithm (recursive)
	//! @param a first number
	//! @param b second number
	//! @return gcd for a and b
	static int gcdRecursive(int a, int b);
	//! @brief Greatest common divisor, Euklid algorithm, faster version
	//! @param a first number
	//! @param b second number
	//! @return gcd for a and b
	static int gcdNonRecursive(int a, int b);
	//! @brief Greatest common divisor, Euklid algorithm, faster version
	//! @param a first number
	//! @param b second number
	//! @param x coefficient for first number
	//! @param y coefficient for second number
	//! @return gcd for a and b
	static int gcdExtended(int a, int b, int &x, int &y);
	//! @brief Lowest common multplier
	//! @param a first number
	//! @param b second number
	//! @return lcm for a and b
	static int lcm(int a, int b);
	//! @brief Searches all simple numbers in range [1;n]
	//! @param n right border of alg
	//! @return vector of simple marks in range [1;n]
	static std::vector<char> sieveOfEratosthenes(int n);
	//! @brief Fibonacchi number of n index, uses Binet formula for calculation
	//! @param n index of Fibonacchi number
	//! @return Fibonacchi number of n index
	static int fibNumberBinet(int n);

};

} //! namespace Fudzi
