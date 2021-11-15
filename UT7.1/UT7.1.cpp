#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.1(Find)/Lab_07_1(Find)cpp.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT71
{
	TEST_CLASS(UT71)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;

			int** z = new int* [2];
			for (int i = 0; i < 2; i++)
				z[i] = new int[2];

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					z[i][j] = 0;
				}
			}
		
			int S = 0;
			int k = 0;
			Calc(z, 2, 2, S, k);

			t = S;
			Assert::AreEqual(0, t);
		}
	};
}