/**
 *	@file main.cpp
 *	@brief Self education project. Focus on interesting algorithms
 *	@author Ivan Deviatkin <devyatkin.ivan@gmail.com>
**/

#include <iostream>
#include <vector>
#include <string>
#include "Strings.hpp"

using namespace std;

void printVectorOfIntsInRow(vector<int> input)
{
	for(vector<int>::const_iterator it = input.begin(); it != input.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

unsigned SearchSubstringInText(string substring, string text, string divider)
{
	string final = substring + divider + text;

	vector<int> zValues = Fudzi::Strings::z_function(final);
	unsigned len = substring.length(), numof = 0;
	for (unsigned i = len + 1; i < zValues.size(); i++)
	{
		if (zValues.at(i) == len)
		{
			numof++;
		}
	}
	return numof;
}

int main()
{
	string strTest("");
	cout << "!!!Fudzi project!!!" << endl;
/*
	//! test for string z_function_trivial
	strTest = "aaaaa";
	cout << "For a string: "<< strTest << " z function values are: "<< endl;
	printVectorOfIntsInRow(Fudzi::Strings::z_function_trivial(strTest));
	strTest = "aaabaab";
	cout << "For a string: "<< strTest << " z function values are: "<< endl;
	printVectorOfIntsInRow(Fudzi::Strings::z_function_trivial(strTest));
	strTest = "abacaba";
	cout << "For a string: "<< strTest << " z function values are: "<< endl;
	printVectorOfIntsInRow(Fudzi::Strings::z_function_trivial(strTest));
*/
	//! test for string z_function_trivial
	strTest = "aaaaa";
	cout << "For a string: "<< strTest << " z function values are: "<< endl;
	printVectorOfIntsInRow(Fudzi::Strings::z_function(strTest));
	strTest = "aaabaab";
	cout << "For a string: "<< strTest << " z function values are: "<< endl;
	printVectorOfIntsInRow(Fudzi::Strings::z_function(strTest));
	strTest = "abacaba";
	cout << "For a string: "<< strTest << " z function values are: "<< endl;
	printVectorOfIntsInRow(Fudzi::Strings::z_function(strTest));

	strTest = "abc";
	string Text("ABCknsdbfcudfbjebf_abc_abc_kjdfslfbv_abc");
	unsigned num = SearchSubstringInText(strTest, Text, "#");
	cout << "For a string: "<< strTest << " and text: "<< Text << " num of substrings are "<< num<< endl;

	return 0;
}
