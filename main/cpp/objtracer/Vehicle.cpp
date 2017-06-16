/**
 * @file
 * Implementation for the class Vehicle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/Vehicle.h"

namespace ODemo {

/*
 * Nothing here except an empty virtual destructor because
 * Vehicle is a pure interface class!
 * All implementations are provided in its subclasses.
 */
/**
 * Destructor has to be virtual because we are in an inheritance hierarchy.
 * Only an empty virtual destructor is allowed for pure interface classes.
 * @return				None.
 * @exception			None.
 */
Vehicle::~Vehicle() {}
}
