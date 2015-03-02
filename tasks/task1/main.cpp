/**
 *	@file main.cpp
 *	@brief Prints unordered permutations for a given string
 *	@author Ivan Deviatkin <devyatkin.ivan@gmail.com>
**/

#include <iostream>
#include <string>
// Fudzi
#include "algebra_elementary.hpp"
#include "strings.hpp"

using namespace std;

int main()
{
    string input = "abc";

    cout << "Prints unordered permutations for a string: " << input << endl;
    unsigned len = input.size();
    const unsigned maxStringLen = 12;   // some max limit for factorial calculation
    if (len > maxStringLen)
    {
        cout << "String is too long!" << endl;
    }
    else
    {
        Fudzi::AlgebraElementary fudzi_algebra_el;
        Fudzi::Strings fudzi_strings;
        for (unsigned long long i = 0; i < static_cast<unsigned long long>(fudzi_algebra_el.factorialRecursive(len)); ++i)
        {
            fudzi_strings.permutationUnordered(i, input);
            cout << "Permutation " << i << " : " << input << endl;
        }
    }

    return 0;
}
