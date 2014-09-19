/**
 *	@file main.cpp
 *	@brief Self education project. Focus on interesting algorithms
 *	@author Ivan Deviatkin <devyatkin.ivan@gmail.com>
**/

#include <iostream>
#include <vector>
#include <string>
#include "strings.hpp"

using namespace std;

void printVectorOfIntsInRow(vector<int> input)
{
	for(vector<int>::const_iterator it = input.begin(); it != input.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main()
{
	string strTest("");
	cout << "!!!Fudzi project!!!" << endl;
	//! TODO: move to google test
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
/*
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
*/
/*
	strTest = "Abc";
	string Text("ABCknsdbfcudfbjebf_abc_abc_kjdfslfbv_abc");
	unsigned num = Fudzi::Strings::SearchSubstringInText(strTest, Text, "#");
	cout << "For a string: "<< strTest << " and text: "<< Text << " num of substrings are "<< num<< endl;
*/
/*
	//! permutations check
	strTest = "abcdefghijklmnop";
	unsigned len = strTest.size();
	for(unsigned i = 0; i < static_cast<unsigned>(factorial(len)); ++i)
	{
		Fudzi::Strings::permutationUnordered(i, strTest);
		cout << "Permutation " << i << " : "<< strTest << endl;
	}
*/

	return 0;
}
