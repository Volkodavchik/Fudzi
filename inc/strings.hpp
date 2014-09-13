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
	static std::vector<int> z_function(std::string s);
	//! @brief Trivial algorithm for getting prefix function for string
	//! @param s string
	//! @return vector of prefix function for given string
	static std::vector<int> prefix_function_trivial(std::string s);
	//! @brief Trivial algorithm for getting prefix function for string
	//! @param s string
	//! @return vector of prefix function for given string
	static std::vector<int> prefix_function(std::string s);
	//! @brief Calculates hash for string with using provided weight coefficient
	//! @param s string
	//! @param weightCoef coefficient for calculating hash, default value 31
	//! @return hash for provided string
	static long long hash_strung(std::string s, long long weightCoef = 31);

};

} //! namespace Fudzi
