/**
 *	@file main.cpp
 *	@brief Network of friends print
 *	@author Ivan Deviatkin <devyatkin.ivan@gmail.com>
**/

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <tuple>
// Fudzi
#include "algebra_elementary.hpp"
#include "strings.hpp"

using namespace std;

void insert_or_assign(string person, vector<string> friends, std::map <string, vector<string>> & network)
{
    auto search = network.find(person);

    if (search != network.end())
    {
        //std::cout << "Found " << search->first << '\n';
        if (!friends.empty())
        {
            //add all elements
            for (auto fr : friends)
            {
                search->second.push_back(fr);
            }
        }
    }
    else
    {
        //std::cout << "Not found " << person << " lets add it \n";
        network.insert(std::make_pair(person, friends));
    }
}

void parseGivenString(string input, std::map <string, vector<string>> & network)
{
    string head;
    vector<string> friends;
    string temp;
    for (auto el : input)
    {
        if(el == ':')
        {
            head = temp;
            std::cout << "head "<< head << std::endl;
            temp.erase();
        }
        else if( el == ',')
        {
            friends.push_back(temp);
            std::cout << "friend "<< temp << std::endl;
            insert_or_assign(temp, vector<string>(), network);
            temp.erase();
        }
        else
        {
            temp += el;
        }
    }
    if (!temp.empty())
    {
        std::cout << "friend "<< temp << std::endl;
        insert_or_assign(temp, vector<string>(), network);
        friends.push_back(temp);
        temp.erase();
    }
    insert_or_assign(head, friends, network);
}

void search_wide(std::map <string, vector<string>> & g, string start)
{
    vector<string> res;

    std::map <string, bool> used;
    for (auto el : g)
    {
        used.insert(make_pair(el.first, false));
    }
    used[start] = true;
    //
    queue<string> q;
    q.push (start);

    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        string friends;
        for (auto el : g[v])
        {
            if (!used[el])
            {
                used[el] = true;
                q.push(el);
                friends += el + ",";
            }
        }
        if (!friends.empty())
        {
            string out = v + ": " + friends;
            std::cout << out << endl;
            res.push_back(out);
        }
    }
}

int main()
{
    vector<string> input;
    input.push_back("A:B,C,D");
    input.push_back("B:A,D");
    input.push_back("C:B,E");

    // create graph
    std::map <string, vector<string>> network;
    for(const auto &el : input)
    {
        parseGivenString(el, network);
        cout << endl;
    }
    // check of graph
    for (const auto &p : network)
    {
        auto friends = p.second;
        cout << p.first << " has " << friends.size() << " friends:" << endl;
        for (const auto &el : p.second)
        {
            cout << el << endl;
        }
    }
    // search for all friends from start point
    search_wide(network, "A");

    return 0;
}
