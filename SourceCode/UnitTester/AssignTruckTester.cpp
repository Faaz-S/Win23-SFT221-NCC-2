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
	

	
	TEST_CLASS(AssignTruckTest)
	{
		const struct Map baseMap = populateMap();
	public:

		//**BLACK BOX TESTS**//

		//destination closest to green route
		TEST_METHOD(AssignTruckTest01)
		{
			init();
			struct Point destination = { 7, 24 };
			struct Shipment package = { 10, 0.5, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(4, result);
		}

		//Testing destination closest to yellow route
		TEST_METHOD(AssignTruckTest02)
		{
			init();
			struct Point destination = { 15,0 };
			struct Shipment package = { 40, 1, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(8, result);
		}

		//Testing destination closest to blue route
		TEST_METHOD(AssignTruckTest03)
		{
			init();
			struct Point destination = { 10,12 };
			struct Shipment package = { 100, 0.5, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(2, result);
		}

		//Testing if Trucks are Full
		TEST_METHOD(AssignTruckTest04)
		{
			init();
			struct Point destination = { 22,1 };
			trucks[0].cargoWeight = trucks[1].cargoWeight = trucks[2].cargoWeight = 500;
			struct Shipment package = { 1000, 1, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(-1, result);
		}

		//Testing destination closest to yellow route but full
		TEST_METHOD(AssignTruckTest05)
		{
			init();
			trucks[2].cargoWeight = 1000;
			struct Point destination = { 15,0 };
			struct Shipment package = { 40, 1, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(2, result);
		}

		//Testing destination closest to blue route but full
		TEST_METHOD(AssignTruckTest07)
		{
			init();
			trucks[0].cargoWeight = 1000;
			trucks[1].cargoWeight = 1000;
			struct Point destination = { 10,12 };
			struct Shipment package = { 100, 0.5, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(8, result);
		}

		//WHITEBOX TESTING

		//Testing destination closest to yellow and blue
		TEST_METHOD(AssignTruckWTest05)
		{
			init();
			struct Point destination = { 6,1 };
			struct Shipment package = { 500, 0.5, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(2, result);
		}
		//Testing destination closest to green route
		TEST_METHOD(AssignTruckWTest06)
		{
			init();
			struct Point destination = { 1,21 };
			struct Shipment package = { 900, 1, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(4, result);
		}
		//Testing destination closest to Yellow route 
		TEST_METHOD(AssignTruckWTest07a)
		{
			init();
			struct Point destination = { 14,4 };
			struct Shipment package = { 40, 0.25, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(8, result);
		}
		//Testing destination closest blue and green
		TEST_METHOD(AssignTruckWTest08)
		{
			init();
			struct Point destination = { 13,20 };
			struct Shipment package = { 900, 1, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(2, result);
		}

	};







}