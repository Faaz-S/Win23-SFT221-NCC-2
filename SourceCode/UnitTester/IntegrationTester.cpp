#include "pch.h"
#include "CppUnitTest.h"
#include "assert.h"
#include "mapping_r.h"
#include "Shipment_r.h"
#include "init_r.h"
#include "Truck_r.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	//IntegrationTests
	//Author: Jubril Akolade

	TEST_CLASS(IntegrationTest)
	{
	
	public:
	
		//Testing valid package with destination closest to green route
		
		TEST_METHOD(IntegrationTest01)
		
		{
			init();
		
			int result = 0;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 10, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
			}
				
			else
			{
				result = -1;
				
				Assert::AreEqual(4, result);
			}
				
		}

		

		//Testing valid package with destination closest to blue route
		
		TEST_METHOD(IntegrationTest02)
		
		{
		
			init();
			
			int result = 0;
			
			struct Point destination = { 11,11 };//12L
			
			struct Shipment package = { 10, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
			}
				
			else
			{
				result = -1;
				Assert::AreEqual(2, result);
			}
				
		}
		
		//Author : Frank Perez
		//Testing valid package with destination closest to yellow route
		
		TEST_METHOD(IntegrationTest03)
		
		{
		
			init();
			
			int result = 0;
			
			struct Point destination = { 14,3 };
			
			struct Shipment package = { 10, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
			}
				
			else
			{
				result = -1;
				
				Assert::AreEqual(8, result);
			}
				
		}

		//Author: Aum Patel
		//Testing with invalid package weight
		TEST_METHOD(IntegrationTest04)
		{
			
			init();
			
			int result = 0;
			
			struct Point destination = { 14,3 };//15C
			
			struct Shipment package = { 2000, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
			}
				
			else
			{
				result = -1;
				
				Assert::AreEqual(-1, result);
			}
			
		}
		
		//Author: Iraklis
		//Testing with invalid package volume
		TEST_METHOD(IntegrationTest05)
		
		{
		
			init();
			
			int result = 0;
			
			struct Point destination = { 14,3 };//15C
			
			struct Shipment package = { 400, 0.3, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
			}
				
			else
			{
				result = -1;
				
				Assert::AreEqual(-1, result);
			}
				
		}
		
		//Testing with invalid package dest
		
		TEST_METHOD(IntegrationTest06)
		{
		
			init();
			
			int result = 0;
			
			struct Point destination = { 20,0 };//21A
			
			struct Shipment package = { 400, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
			}
				
			else
			{
				result = -1;
				
				Assert::AreEqual(-1, result);
			}
				
		}
		
		//Author: Rutarj Shah
		//Testing with valid package 
		
		TEST_METHOD(IntegrationTest07)
		{
			init();
		
			trucks[1].cargoWeight = 999;
			
			int result = 0;
			
			struct Point destination = { 7,24 };//8Y
			
			struct Shipment package = { 400, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
			}
				
			else
			{
				result = -1;
			
				Assert::AreEqual(2, result);
			}
				
		}
		
		//Testing with valid package 
		TEST_METHOD(IntegrationTest08)
		{
			init();
			
			trucks[2].cargoWeight = 999;
			
			int result = 0;
			
			struct Point destination = { 14,3 };//15C
			
			struct Shipment package = { 400, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
			}
				
			else
			{
				result = -1;
				
				Assert::AreEqual(2, result);
			}
				
		}

		//Testing with valid package 
		TEST_METHOD(IntegrationTest09)
		{
			init();
		
			trucks[0].cargoWeight = 999;
			
			int result = 0;
			
			struct Point destination = { 15,11 };//15L
			
			struct Shipment package = { 400, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
			}
				
			else
			{
				result = -1;
				
				Assert::AreEqual(8, result);
			}
			
		}

		//Author: Faaz Sherwani
		//Testing with valid package 
		TEST_METHOD(IntegrationTest10)
		{
			init();
			
			trucks[0].cargoWeight = 999;
			
			trucks[1].cargoWeight = 999;
			
			trucks[2].cargoWeight = 999;
			
			int result = 0;
			
			struct Point destination = { 15,11 };//15L
			
			struct Shipment package = { 400, 0.5, destination };
			
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
				result = (result == 0 ? -1 : result);
			}
			else
			{
				result = -1;
				
				Assert::AreEqual(-1, result);
			}
				
		}
	};
}

