#ifndef INIT_H
#define INIT_H
#include "Truck.h"
#include "Shipment.h"
#include "mapping.h"

//struct Map* baseMap: will contain the map featuring our delivery range, building, and base.
struct Map* baseMap;
//struct Truck* trucks : will contain our 3 trucks, each assigned to the blue, green, or yellow route.
struct Truck trucks[3]; 

 


#endif
