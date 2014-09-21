/**
 *	@file strings.cpp
 *  @brief Elementary algorithms from e-maxx.ru library
 *  @author Ivan Deviatkin <devyatkin.ivan@gmail.com>, great thanks to Maksim Ivanov
**/

#include <vector>
#include <string>
#include <iterator>
#include <math.h>
#include "strings.hpp"

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

unsigned Strings::SearchSubstringInText(string substring, string text, string divider)
{
	string final = substring + divider + text;

	vector<int> zValues = Fudzi::Strings::z_function(final);
	unsigned len = substring.length(), numof = 0;
	for (unsigned i = len + 1; i < zValues.size(); i++)
	{
		if (static_cast<unsigned>(zValues.at(i)) == len)
		{
			numof++;
		}
	}
	return numof;
}

void Strings::permutationUnordered(int k, string &s)
{
    for(unsigned int j = 1; j < s.size(); ++j)
    {
        swap(s[k % (j + 1)], s[j]);
        k = k / (j + 1);
    }
}

string Strings::reverseWithSTL(string &input)
{
	std::string output("");
	for (std::string::reverse_iterator rit=input.rbegin(); rit!=input.rend(); ++rit)
    output += *rit;

	return output;
}

} // namespace Fudzi
