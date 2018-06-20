/**
 *	@file strings.cpp
 *  @brief Elementary algorithms from e-maxx.ru library
 *  @author Ivan Deviatkin <devyatkin.ivan@gmail.com>, great thanks to Maksim Ivanov
**/

#include <vector>
#include <string>
#include <iterator>
#include <math.h>

#include "stringAlgs.hpp"

using namespace std;

namespace fudzi
{

// Given a string S of length n.
// Z Algorithm produces an array Z where Z[i] is the length of the longest substring starting from S[i] which is also a prefix of S, i.e.
// the maximum k such that S[j] = S[i + j] for all 0 ≤ j < k. Note that Z[i] = 0 means that S[0] ≠ S[i]. For easier terminology, we will refer to
// substrings which are also a prefix as prefix-substrings.
// Пусть дана строка s длины n.
// Тогда Z-функция ("зет-функция") от этой строки — это массив длины n, i-ый элемент которого равен наибольшему числу символов, начиная с позиции i,
// совпадающих с первыми символами строки s.
// Иными словами, z[i] — это наибольший общий префикс строки s и её i-го суффикса.
// Example 1: str = "aaaaa":
// z[0] = 0,
// z[1] = 4,
// z[2] = 3,
// z[3] = 2,
// z[4] = 1.
// Example 2: str = "aaabaab":
// z[0] = 0,
// z[1] = 2,
// z[2] = 1,
// z[3] = 0,
// z[4] = 2,
// z[5] = 1,
// z[6] = 0.
// Example 3: str = "abacaba":
// z[0] = 0,
// z[1] = 0,
// z[2] = 1,
// z[3] = 0,
// z[4] = 3,
// z[5] = 0,
// z[6] = 1.

// O(n^2) efficiency
vector<int> stringAlgs::z_function_trivial(string in)
{
	int n = static_cast<int>(in.length());
	vector<int> z(n);

	for (int i = 1; i < n; ++i)
	{
		while (i + z[i] < n && in[z[i]] == in[i + z[i]])
		{
			++z[i];
		}
	}

	return z;
}
// O(n) efficiency
vector<int> stringAlgs::z_function(string in)
{
	int n = static_cast<int>(in.length());
	vector<int> z(n);

	for (int i = 1, l = 0, r = 0; i < n; ++i) 
	{
		if (i <= r)
		{
			z[i] = static_cast<int>(std::fmin(r - i + 1, z[i - l]));
		}
		while (i + z[i] < n && in[z[i]] == in[i + z[i]])
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

vector<int> stringAlgs::prefix_function_trivial(string s)
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

vector<int> stringAlgs::prefix_function(string s)
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

long long stringAlgs::hash_string(std::string s, long long weightCoef)
{
	long long hash = 0;
	unsigned int id = 1;

	for(std::string::iterator it = s.begin(); it != s.end(); ++it, ++id)
	{
		hash += (*it)*(long long)pow(weightCoef, id);
	}

	return hash;
}

unsigned stringAlgs::SearchSubstringInText(string substring, string text, string divider)
{
	string final = substring + divider + text;

	vector<int> zValues = fudzi::stringAlgs::z_function(final);
	unsigned len = static_cast<unsigned>(substring.length()), 
		numof = 0;
	for (unsigned i = len + 1; i < zValues.size(); i++)
	{
		if (static_cast<unsigned>(zValues.at(i)) == len)
		{
			numof++;
		}
	}
	return numof;
}

void stringAlgs::permutationUnordered(int k, string &s)
{
    for(unsigned int j = 1; j < s.size(); ++j)
    {
        swap(s[k % (j + 1)], s[j]);
        k = k / (j + 1);
    }
}

string stringAlgs::reverseWithSTL(string &input)
{
	std::string output("");
	for (std::string::reverse_iterator rit=input.rbegin(); rit!=input.rend(); ++rit)
    output += *rit;

	return output;
}

} // namespace Fudzi
