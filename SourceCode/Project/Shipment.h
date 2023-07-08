#ifndef SHIPMENT_H
#define SHIPMENT_H

#define SMALL_BOX_VOL 0.25
#define MED_BOX_VOL 0.50
#define LARGE_BOX_VOL 1.0
//box volume unit -> metre cube
#include "mapping.h"
/**
 * Struct: Shipment
 * Author: Faaz Sherwani
 * Description: Defines customer package/shipment, includes:
 *   - shipment weight
 *   - shipment volume
 *   - shipment destination
 */
struct Shipment
{
    int weight;
    double vol;
    struct Point destination;
};


#endif
