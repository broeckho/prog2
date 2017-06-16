/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include "tracer.hpp"

long int SortTracer::n_created = 0;
long int SortTracer::n_destroyed = 0;
long int SortTracer::n_max_live = 0;
long int SortTracer::n_assigned = 0;
long int SortTracer::n_compared = 0;
