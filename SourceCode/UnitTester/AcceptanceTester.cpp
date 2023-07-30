#include "pch.h"
#include "CppUnitTest.h"
#include "assert.h"
#include "mapping_r.h"
#include "Shipment_r.h"
#include "init_r.h"
#include "Truck_r.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{

	//Author: Faaz Sherwani
	// Acceptance Tests
	TEST_CLASS(AcceptanceTest)
	{
	public:
		//Testing valid package with destination closest to green route
		TEST_METHOD(AcceptanceTest01a)
		{
		
			init();
			
			int result = 0;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 10, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest01b)
		{
			
			init();
			
			int result = 0;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 10, 0.25, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
			
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest01c)
		{
			
			init();
			
			int result = 0;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 10, 1, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest01d)
		{
			
			init();
			
			int result = 0;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 10, 0.75, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			
			else
				result = -1;
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(AcceptanceTest02a)
		{
			
			init();
			
			int result = 0;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 999, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest02b)
		{
			
			init();
			
			int result = 0;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 1, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest02c)
		{
			
			init();
			
			int result = 0;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 0, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(AcceptanceTest02d)
		{
			
			init();
			
			int result = 0;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 1001, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(AcceptanceTest03a)
		{
			init();
			
			int result = 0;
			
			struct Point destination = { 11,11 }; //12L
			
			struct Shipment package = { 10, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(AcceptanceTest03b)
		{
			
			init();
			
			int result = 0;
			
			struct Point destination = { 11,10 }; //12L
			
			struct Shipment package = { 10, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(AcceptanceTest4)
		{
			
			init();
			
			int result = 0;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 10, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest5)
		{
			init();
			
			int result = 0;
			
			trucks[1].cargoWeight = 500;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 510, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(AcceptanceTest6)
		{
			
			init();
			
			int result = 0;
			
			trucks[1].cargoWeight = 300;
			
			trucks[1].cargoVol = 35.5;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 510, 1, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(AcceptanceTest7)
		{
			init();
			
			int result = 0;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 10, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest8)
		{
			
			init();
			
			int result = 0;
			
			trucks[1].cargoWeight = 500;
			
			struct Point destination = { 7,23 };//8Y
			
			struct Shipment package = { 510, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(AcceptanceTest9)
		{
			
			init();
			
			int result = 0;
			
			trucks[1].cargoWeight = 300;
			
			trucks[1].cargoVol = 35.5;
			
			struct Point destination = { 7,23 };//8Y
			
			struct Shipment package = { 510, 1, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(AcceptanceTest10)
		{
			
			init();
			
			int result = 0;
			
			struct Point destination = { 1,1 };//8Y
			
			struct Shipment package = { 510, 1, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(AcceptanceTest11)
		{
			init();
			int result = 0;
			
			trucks[0].cargoWeight = 700;
			
			trucks[1].cargoWeight = 700;
			
			trucks[2].cargoWeight = 700;
			
			struct Point destination = { 1,1 };//8Y
			
			struct Shipment package = { 510, 1, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
				result = (result == -1 ? 0 : result);
			}
			
			else
			{
				result = -1;
				
				Assert::AreEqual(0, result);
			}
				
		}
	};
}
