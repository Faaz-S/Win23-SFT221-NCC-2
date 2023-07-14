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
	TEST_CLASS(containsDestinationTest)
	{
		struct Shipment shipment = { 10,1,{7,24} };

	public:

		//containsDestination blackbox test 1
		TEST_METHOD(containsDestinationBB1)
		{
			struct Point destination = { 20, 10 };
			shipment.destination = destination;
			struct Route testRoute = { 0 };
			for (int i = 0; i < 20; i++) {
				char a = i + 1;
				testRoute.points[i] = { a, 10 };
			}
			testRoute.numPoints = 20;
			testRoute.points[20] = { 20, 10 };
			int result = containsDestination(&testRoute, shipment);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(containsDestinationBB2)
		{
			struct Point destination = { 20, 10 };
			shipment.destination = destination;
			struct Route testRoute = { 0 };
			for (int i = 0; i < 20; i++) {
				char a = i + 1;
				testRoute.points[i] = { 10, a };
			}
			testRoute.numPoints = 20;
			testRoute.points[20] = { 10, 20 };
			int result = containsDestination(&testRoute, shipment);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(containsDestinationBB3)
		{
			struct Point destination = { 20, 10 };
			shipment.destination = destination;
			struct Route testRoute = { 0 };
			testRoute.points[20] = { NULL, 10 };
			int result = containsDestination(&testRoute, shipment);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(containsDestinationBB4)
		{
			struct Point destination = { 10, 10 };
			shipment.destination = destination;
			struct Route testRoute = { 0 };
			testRoute.points[20] = { 29, 50 };
			int result = containsDestination(&testRoute, shipment);
			Assert::AreEqual(0, result);
		}
	};


}