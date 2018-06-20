#include "stdafx.h"
#include "CppUnitTest.h"
#include "stringalgs.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace fudzi;

namespace string_test_vs_project
{		
	TEST_CLASS(UnitTest1)
	{
		fudzi::stringAlgs mInstance;
	public:
		
		TEST_METHOD(Test_z_function_trivial)
		{
			// str  = "aaaaaa"
			// Z[] = { x, 5, 4, 3, 2, 1 }
			std::vector<int> aaaaa = mInstance.z_function_trivial("aaaaaa");
			std::vector<int> aaaaa_checkValues = { 0, 5, 4, 3, 2, 1 };
			for (int i = 0; i < aaaaa.size(); i++) {
				Assert::AreEqual(aaaaa[i], aaaaa_checkValues[i], L"Assert on z_function_trivial(\"aaaaaa\")", LINE_INFO());
			}
			// str = "aabaacd"
			// Z[] = { x, 1, 0, 2, 1, 0, 0 }
			std::vector<int> aabaacd = mInstance.z_function_trivial("aabaacd");
			std::vector<int> aabaacd_checkValues = { 0, 1, 0, 2, 1, 0, 0 };
			for (int i = 0; i < aabaacd.size(); i++) {
				Assert::AreEqual(aabaacd[i], aabaacd_checkValues[i], L"Assert on z_function_trivial(\"aabaacd\")", LINE_INFO());
			}
			// str = "abababab"
			// Z[] = { x, 0, 6, 0, 4, 0, 2, 0 }
			std::vector<int> abababab = mInstance.z_function_trivial("abababab");
			std::vector<int> abababab_checkValues = { 0, 0, 6, 0, 4, 0, 2, 0 };
			for (int i = 0; i < abababab.size(); i++) {
				Assert::AreEqual(abababab[i], abababab_checkValues[i], L"Assert on z_function_trivial(\"abababab\")", LINE_INFO());
			}
		}

	};
}