#include "pch.h"
#include "CppUnitTest.h"
#include "assert.h"
#include "mapping_r.h"
#include "Shipment_r.h"
#include "Truck_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(ValidateTest)
	{
	public:
		
		//BB TESTS
		TEST_METHOD(ValidateTest1)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 500, dest);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(validateTest2)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.25, 500, dest);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(validateTest3)
		{
			struct Point dest = { 2, 2 };
			int result = validate(1, 500, dest);
			Assert::AreEqual(1, result);

		}

		TEST_METHOD(validateTest4)
		{
			struct Point dest = { 2, 2 };
			int result = validate(-1, 500, dest);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(validateTest5)
		{
			struct Point dest = { 2, 2 };
			int result = validate(NULL, 500, dest);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(validateTest6)
		{
			struct Point dest = { 2, 2 };
			int result = validate(2, 500, dest);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(validateTest7)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5678, 500, dest);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(validateTest8)
		{
			struct Point dest = { 2, 2 };
			int result = validate(1234567890, 500, dest);
			Assert::AreEqual(-1, result);
		}

		//Test 3a-3c: tests a variety of valid shipment weight inputs
		TEST_METHOD(validateTest9)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 1, dest);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(validateTes10)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 1000, dest);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(validateTest11)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 300, dest);
			Assert::AreEqual(1, result);
		}

		//Test 4a-4e: tests a variety of invalid shipment weight inputs
		TEST_METHOD(validateTest12)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 0, dest);
			Assert::AreEqual(-2, result);
		}
		TEST_METHOD(validateTest13)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 100000000, dest);
			Assert::AreEqual(-2, result);
		}
		TEST_METHOD(validateTest14)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, NULL, dest);
			Assert::AreEqual(-2, result);
		}
		TEST_METHOD(validateTest15)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, -1, dest);
			Assert::AreEqual(-2, result);
		}
		TEST_METHOD(validateTest16)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 1001, dest);
			Assert::AreEqual(-2, result);
		}

		//Test 5a-5d: tests a variety of valid destination inputs
		TEST_METHOD(validateTest17)
		{
			struct Point dest2 = { 2, 2 };
			int result = validate(0.5, 1, dest2);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(validateTest18)
		{
			struct Point dest3 = { 25, 25 };
			int result = validate(0.5, 1, dest3);
			Assert::AreEqual(1, result);
		}
		
		
		TEST_METHOD(validateTest19)
		{
			struct Point dest7 = { 25, NULL };
			int result = validate(0.5, 400, dest7);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest20)
		{
			struct Point dest8 = { 0, 26 };
			int result = validate(0.5, 400, dest8);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest21)
		{
			struct Point dest9 = { 26, 0 };
			int result = validate(0.5, 400, dest9);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest22)
		{
			struct Point dest10 = { 0, 0 };
			int result = validate(0.5, 400, dest10);
			Assert::AreEqual(-3, result);
		}
	
		
		TEST_METHOD(validateTest23)
		{
			struct Point dest13 = { -1, -1 };
			int result = validate(0.5, 400, dest13);
			Assert::AreEqual(-3, result);
		}
		
		
		TEST_METHOD(validateTest24)
		{
			struct Point dest13 = { 10, 10 };
			int result = validate(0.5, '@', dest13);
			Assert::AreEqual(-3, result);
		}
		
	};
}