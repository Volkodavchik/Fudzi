/**
*  Elementary algorithms from e-maxx.ru library
*  Great thanks to Maksim Ivanov
**/

#pragma once

#include <vector>
#include <string>

namespace Fudzi
{

class Strings
{
private:
protected:
public:
	// @brief Trivial algorithm for getting zet function for string
	// @param s string
	// @return vector of zet function for given string
	std::vector<int> z_function_trivial(std::string s);
	// @brief Efficiency algorithm for getting zet function for string
	// @param s string
	// @return vector of zet function for given string
	std::vector<int> z_function(std::string s);
	// @brief Trivial algorithm for getting prefix function for string
	// @param s string
	// @return vector of prefix function for given string
	std::vector<int> prefix_function_trivial(std::string s);
	// @brief Trivial algorithm for getting prefix function for string
	// @param s string
	// @return vector of prefix function for given string
	std::vector<int> prefix_function(std::string s);

};

} // namespace Fudzi
