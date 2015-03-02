/**
 *	@file main.cpp
 *	@brief Network of friends print
 *	@author Ivan Deviatkin <devyatkin.ivan@gmail.com>
**/

#include <iostream>
#include <string>
// Fudzi
#include "algebra_elementary.hpp"
#include "strings.hpp"

using namespace std;

void parseGivenString(string input)
{
    string head;
    string temp;
    for (auto el : input)
    {
        if(el == ':')
        {
            head = temp;
            cout << "head friend: " << head << endl;
            temp.erase();
        }
        else if( el == ',')
        {
            cout << "next friend: " << temp << endl;
            temp.erase();
        }
        else
        {
            temp += el;
        }
    }
    if (!temp.empty())
    {
        cout << "next friend: " << temp << endl;
        temp.erase();
    }
}

int main()
{
    string input = "A:B,C,D";

    cout << "given string: " << input << endl;


    return 0;
}
