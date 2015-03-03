/**
 *	@file strings.hpp
 *  @brief Elementary algorithms from e-maxx.ru library
 *  @author Ivan Deviatkin <devyatkin.ivan@gmail.com>, great thanks to Maksim Ivanov
**/

#pragma once

#include <vector>
#include <string>

namespace Fudzi
{
/*
 * Class stores algorithms related to strings operations
 */
class Strings
{
private:
protected:
public:
	//! @brief Trivial algorithm for getting zet function for string
	//! @param s string
	//! @return vector of zet function for given string
	static std::vector<int> z_function_trivial(std::string s);
	//! @brief Efficiency algorithm for getting zet function for string
	//! @param s string
	//! @return vector of zet function for given string
	std::vector<int> z_function(std::string s);
	//! @brief Trivial algorithm for getting prefix function for string
	//! @param s string
	//! @return vector of prefix function for given string
	std::vector<int> prefix_function_trivial(std::string s);
	//! @brief Trivial algorithm for getting prefix function for string
	//! @param s string
	//! @return vector of prefix function for given string
	std::vector<int> prefix_function(std::string s);
	//! @brief Calculates hash for string with using provided weight coefficient
	//! @param s string
	//! @param weightCoef coefficient for calculating hash, default value 31
	//! @return hash for provided string
	long long hash_strung(std::string s, long long weightCoef = 31);
	//! @brief Searches and returns all substrings in given string(text)
	//! @param substring string for looking
	//! @param text given text in which we are looking for a substring
	//! @param divider symbol which is not present in text/substring
	//! @return number of substrings in given string
	unsigned SearchSubstringInText(std::string substring, std::string text, std::string divider);
	//! @brief Non-recursive algorithm for unordered generation of permutations.
	//! For the string s of length n, for any k from 0 to n! - 1 inclusive, the following
	//! modifies s to provide a unique permutation (that is, different from those generated for
	//! any other k value on that range). To generate all permutations, run it for all n! k
	//! values on the original value of s.Searches and returns all substrings in given string(text)
	//! @param k value for permutation alg
	//! @param s string for generating new permutation
	void permutationUnordered(int k, std::string &s);
	//! @brief Reverse string with reverse iterator
	//! @param input string for revrse
	//! @return reversed string
	std::string reverseWithSTL(std::string &input);


};

} //! namespace Fudzi
