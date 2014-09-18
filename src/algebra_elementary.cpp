/**
 *	@file algebra_elementary.cpp
 *	@brief Self education project. Focus on interesting algorithms
 *	@author Ivan Deviatkin <devyatkin.ivan@gmail.com>
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include "algebra_elementary.hpp"

using namespace std;

namespace Fudzi
{

int AlgebraElementary::phi(int n)
{
	int result = n;

	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n /= i;
			}
			result -= result / i;
		}
	}

	if (n > 1)
	{
		result -= result / n;
	}

	return result;
}

int AlgebraElementary::binpow(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n % 2 == 1)
	{
		return binpow (a, n-1) * a;
	}
	else
	{
		int b = binpow (a, n/2);
		return b * b;
	}
}

int AlgebraElementary::binpowEx(int a, int n)
{
	int res = 1;

	while (n)
	{
		if (n & 1)
		{
			res *= a;
		}
		a *= a;
		n >>= 1;
	}
	return res;
}

int AlgebraElementary::gcdRecursive(int a, int b)
{
	return b ? gcdRecursive(b, a % b) : a;
}

int AlgebraElementary::gcdNonRecursive(int a, int b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}

	return a;
}

int AlgebraElementary::gcdExtended(int a, int b, int &x, int &y)
{
	if (a == 0)
	{
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcdExtended(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int AlgebraElementary::lcm(int a, int b)
{
	return a / gcdNonRecursive(a, b) * b;
}

vector<char> AlgebraElementary::sieveOfEratosthenes(int n)
{
	vector<char> prime (n+1, true);
	prime[0] = prime[1] = false;

	for (int i = 2; i * i <= n; ++i)
	{
		if (i%2)
		{
			if (prime[i])
			{
				if (i * 1ll * i <= n)
				{
					for (int j = i * i; j <= n; j += i)
					{
						prime[j] = false;
					}
				}
			}
		}
		else
		{
			prime[i] = false;
		}
	}

	return prime;
}

int fibNumberBinet(int n)
{
	const double
		tmpVal1 = static_cast<double>(sqrt(5)),
		tmpVal2 = (1 + tmpVal1)/static_cast<double>(2),
		tmpVal3 = (1 - tmpVal1)/static_cast<double>(2);

	return static_cast<int>((pow(tmpVal2, n) - pow(tmpVal3, n))/tmpVal1);
}

unsigned long long int factorialRecursive(unsigned long long int n)
{
	return (n)? (n * factorialRecursive(n-1)): 1;
}

unsigned long long int factorialNonRecursive(unsigned long long int n)
{

	return n;
}

} // namespace Fudzi

// eof
