#include "pch.h"
#include "CppUnitTest.h"
#include "../ЛР 6.4 рек/ЛР 6.4 рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test64rec
{
	TEST_CLASS(test64rec)
	{
	public:

		TEST_METHOD(TestMinAbsIndex)
		{
			double x[5] = { 3.0, -2.0, 0.5, -4.0, 1.0 };
			int result = MinAbsIndex(x, 5, 1, 0);
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(TestFirstNegativeIndex)
		{
			double x[5] = { 3.0, -2.0, 0.5, -4.0, 1.0 };
			int result = FirstNegativeIndex(x, 5, 0);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(TestSumAbsAfterFirstNegative)
		{
			double x[5] = { 3.0, -2.0, 0.5, -4.0, 1.0 };
			double result = SumAbsAfterFirstNegative(x, 5);
			Assert::AreEqual(5.5, result, 1e-6);
		}

		TEST_METHOD(TestSumAbs_NoNegative)
		{
			double x[2] = { 1.0, 2.0 };
			double result = SumAbsAfterFirstNegative(x, 2);
			Assert::AreEqual(0.0, result, 1e-6);
		}

		TEST_METHOD(TestCompress)
		{
			double x[5] = { 3.0, -2.0, 0.5, -4.0, 1.0 };
			int k = Compress(x, 5, -1, 2, 0, 0);
			Assert::AreEqual(3, k);
			Assert::AreEqual(3.0, x[0], 1e-6);
			Assert::AreEqual(-2.0, x[1], 1e-6);
			Assert::AreEqual(-4.0, x[2], 1e-6);
		}

		TEST_METHOD(TestFillZeros)
		{
			double x[5] = { 3.0, -2.0, -4.0, 9.0, 9.0 };
			FillZeros(x, 5, 3);
			Assert::AreEqual(0.0, x[3], 1e-6);
			Assert::AreEqual(0.0, x[4], 1e-6);
			Assert::AreEqual(-4.0, x[2], 1e-6);
		}
	};
}