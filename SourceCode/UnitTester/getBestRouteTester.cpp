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
	TEST_CLASS(getBestRouteBB)
	{
		const struct Map* baseMap = &(populateMap());

		struct Shipment shipment = { 10,1,{7,24} };

		struct Route blueRoute = getBlueRoute();

		struct Route greenRoute = getGreenRoute();

		struct Route yellowRoute = getYellowRoute();

		struct Truck truck[3] =
		{
			{0, 0, &blueRoute},
			{0, 0, &greenRoute},
			{0, 0, &yellowRoute}
		};

	public:

		//Black Box Test 1
		TEST_METHOD(getBestRouteBT1)
		{
			struct Route testRoutes[100];
			int size = 0;
			int result = getBestRoute(testRoutes, size, shipment);
			Assert::AreEqual(0, result);
		}

		//Black Box Test 2
		TEST_METHOD(getBestRouteBT2)
		{
			struct Route routes[100];
			int size = -1;
			int result = getBestRoute(routes, size, shipment);
			Assert::AreEqual(0, result);
		}
		//Black Box Test 3
		TEST_METHOD(getBestRouteBT3)
		{
			struct Route routes[100];
			int size = NULL;
			int result = getBestRoute(routes, size, shipment);
			Assert::AreEqual(0, result);
		}
		//Black Box Test 4
		TEST_METHOD(getBestRouteBT4)
		{
			struct Route routes[10];
			int size = 10;
			routes[0].numPoints = 3;
			routes[0].points[0] = { 7,24 };
			int result = getBestRoute(routes, size, shipment);
			Assert::AreEqual(1, result);
		}
		//Black Box Test 5
		TEST_METHOD(getBestRouteBT5)
		{
			struct Route routes[10];
			int result = 7;
			int size = 10;
			struct Shipment s { 500, 0.5, { 7,9 } };
			struct Point p1[2] = { {8,10}, {7,10} };
			struct Route r1 = { *p1, 2, 2 };
			r1.numPoints = 3;
			struct Point p2[4] = { {4,10}, {5,10} };
			struct Route r2 = { *p2, 4, 4 };
			r2.numPoints = 4;
			struct Point p3[7] = { {10,5}, {10,6}, {10,7}, {9,7}, {9,8}, {8,8}, {8,9} };
			struct Route r3 = { *p3,7,8 };
			r3.numPoints = 9;
			struct Route routesTest[3] = { r1,r2,r3 };

			result = (getBestRoute(routesTest, size, shipment) ? 7 : result);
			Assert::AreEqual(7, result);
		}
		//Black Box Test 6
		TEST_METHOD(getBestRouteBT6)
		{
			int size = 3;
			
			init();
			
			//blue
			struct Point p1[2] = { {9,4}, {10,4} };
			struct Route r1 = { *p1, 2, 2 };
			r1.numPoints = 2;
			//yellow
			struct Point p2[10] = { {3,5}, {3,4}, {4,4}, {5,4}, {6,4}, {7,4}, {8,4}, {9,4}, {10,4}, {10,3} };
			struct Route r2 = { *p2, 10, 4 };
			r2.numPoints = 10;
			//green
			struct Point p3[1] = { {10,4} };
			struct Route r3 = { *p3, 1,8 };
			r3.numPoints = 1;
			struct Route routesT[3] = { r1,r2,r3 };
			struct Shipment s { 500, 0.5, { 10,3 } };
			int result = getBestRoute(routesT, size, s);
			Assert::AreEqual(2, result);
		}
	};
		
}