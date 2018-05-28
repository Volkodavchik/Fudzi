#include "stdafx.h"
#include "CppUnitTest.h"
#include "algebra.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace algebra_test_vs_project
{		
	TEST_CLASS(UnitTest1)
	{
		fudzi::algebra algebraInstance;
	public:
		
		TEST_METHOD(BinPowTest1)
		{
			Assert::AreEqual(1, algebraInstance.binpow(1, 1), L"Assert on algebra::binpow(1, 1)", LINE_INFO());
			Assert::AreEqual(4, algebraInstance.binpow(2, 2), L"Assert on algebra::binpow(2, 2)", LINE_INFO());
			Assert::AreEqual(27, algebraInstance.binpow(3, 3), L"Assert on algebra::binpow(3, 3)", LINE_INFO());
		}
	};
}