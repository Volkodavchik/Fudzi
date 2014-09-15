/**
 *	@file strings.cpp
 *  @brief Elementary algorithms from e-maxx.ru library
 *  @author Ivan Deviatkin <devyatkin.ivan@gmail.com>, great thanks to Maksim Ivanov
**/

#include <vector>
#include <string>
#include <iterator>
#include <math.h>
#include "Strings.hpp"

using namespace std;

namespace Fudzi
{

vector<int> Strings::z_function_trivial(string s)
{
	int n = static_cast<int>(s.length());
	vector<int> z (n);

	for (int i = 1; i < n; ++i)
	{
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
		{
			++z[i];
		}
	}

	return z;
}

vector<int> Strings::z_function(string s) 
{
	int n = static_cast<int>(s.length());
	vector<int> z(n);

	for (int i = 1, l = 0, r = 0; i < n; ++i) 
	{
		if (i <= r)
		{
			z[i] = min(r - i + 1, z[i - l]);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
		{
			++z[i];
		}
		if (i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

vector<int> Strings::prefix_function_trivial(string s)
{
	int n = static_cast<int>(s.length());
	vector<int> pi (n);

	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k <= i; ++k)
		{
			if (s.substr(0, k) == s.substr(i - k + 1, k))
			{
				pi[i] = k;
			}
		}
	}

	return pi;
}

vector<int> Strings::prefix_function(string s)
{
	int n = static_cast<int>(s.length());
	vector<int> pi (n);

	for (int i = 1; i < n; ++i)
	{
		int j = pi[i - 1];

		while (j > 0 && s[i] != s[j])
		{
			j = pi[j - 1];
		}
		if (s[i] == s[j])
		{
			++j;
		}
		pi[i] = j;
	}

	return pi;
}

long long Strings::hash_strung(std::string s, long long weightCoef)
{
	long long hash = 0;
	unsigned int id = 1;

	for(std::string::iterator it = s.begin(); it != s.end(); ++it, ++id)
	{
		hash += (*it)*pow(weightCoef, id);
	}

	return hash;
}

} // namespace Fudzi
