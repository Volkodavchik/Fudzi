/**
 *	@file main.cpp
 *	@brief Self education project. Focus on interesting algorithms
 *	@author Ivan Deviatkin <devyatkin.ivan@gmail.com>
**/

//#define GOOGLE_TEST_SUITE

#ifdef GOOGLE_TEST_SUITE
#include "gtest/gtest.h"
#endif
#include "graphs_elementary.hpp"

using namespace std;

int main(int argc, char **argv) 
{
	Vertex<std::string, int> testGraph;


#ifdef GOOGLE_TEST_SUITE
	  ::testing::InitGoogleTest(&argc, argv);
	  return RUN_ALL_TESTS();
#endif
}
