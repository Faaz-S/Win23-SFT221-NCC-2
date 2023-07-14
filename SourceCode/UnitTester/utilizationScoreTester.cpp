#include "pch.h"
#include "CppUnitTest.h"
#include "assert.h"
#include "mapping_r.h"
#include "Shipment_r.h"
#include "init_r.h"
#include "Truck_r.h"
#include "utils_r.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCases
{
	TEST_CLASS(UtilizationScoreTest)
	{
	public:
		//Black Box Test1
		TEST_METHOD(UtilizationBBT04)
		{
			int result = 0;
			result = calculateUtilizationScore(300, NULL);
			Assert::AreEqual(0, result);
		}


		TEST_METHOD(UtilizationBBT02)
		{
			int result = 0;
			result = calculateUtilizationScore(400, -1);
			Assert::AreEqual(0, result);
		}


		TEST_METHOD(UtilizationBBT03)
		{
			int result = 0;
			result = calculateUtilizationScore(NULL, 0.25);
			Assert::AreEqual(0, result);
		}
		//Black Box Test4
		TEST_METHOD(UtilizationBBT01)
		{
			int result = 0;
			result = calculateUtilizationScore(-1, 0.5);
			Assert::AreEqual(0, result);
		}


		//Black Box Test5
		TEST_METHOD(UtilizationBBT05)
		{
			int result = 0;
			result = calculateUtilizationScore(0, 1.0);
			Assert::AreEqual(0, result);
		}
		//Black Box Test6
		TEST_METHOD(UtilizationBBT06)
		{
			int result = 0;
			result = calculateUtilizationScore(300, 0);
			Assert::AreEqual(0, result);
		}
		//Black Box Test7
		TEST_METHOD(UtilizationBBT07)
		{
			int result = 0;
			result = calculateUtilizationScore(0, 0);
			Assert::AreEqual(0, result);
		}
		//Black Box Test8
		TEST_METHOD(UtilizationBBT10)
		{
			int result = 0;
			result = calculateUtilizationScore(300, 40);
			Assert::AreEqual(0, result);
		}

		//Black Box Test9
		TEST_METHOD(UtilizationBBT09)
		{
			int result = 0;
			result = calculateUtilizationScore(NULL, NULL);
			Assert::AreEqual(0, result);
		}
		//Black Box Test10
		TEST_METHOD(UtilizationBBT08)
		{
			int result = 0;
			result = calculateUtilizationScore(-1, -1);
			Assert::AreEqual(0, result);
		}

		//Black Box Test11
		TEST_METHOD(UtilizationBBT13)
		{
			int result = 0;
			result = calculateUtilizationScore(500, 1);
			Assert::AreEqual(18, result);
		}
	};
}