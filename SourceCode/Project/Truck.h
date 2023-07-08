#pragma once
#ifndef TRUCK_H
#define TRUCK_H
#define MAX_CARGO_WEIGHT 1000 // in KGs
#define MAX_CARGO_VOL 36      // in m^3
#include "mapping.h"

/**
 * Struct: Truck
 * Author: Faaz Sherwani
 * Description: Defines a Trucks state =>  determines if it can accept additional shipment, it includes:
 *   - current cargo weight
 *   - current cargo volume
 *   - path the truck will take
 */

struct Truck
{
    int cargoWeight;
    double cargoVol;
    struct Route* route;
    // set limit
    // struct Route *diversions[100];
};



#endif