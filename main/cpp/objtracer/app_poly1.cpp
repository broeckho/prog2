/**
 * @file
 * Implementation file for demo programs for run-time polymorphism.
 * A C++ code example relating to the material in
 * Stroustrup (3 ed.) chapter 12: Derived classes
 * @author P. Klosiewicz, J.Broeckhove, 2011  CoMP/UA
 */

#include "demos.h"
#include "objtracer/demobj.h"
#include "tracer/tracer.h"

#include <iostream>
#include <list>
#include <memory>

using namespace std;
using namespace ODemo;

namespace {

void display_all(list<shared_ptr<Vehicle>> l)
{
        COMP_MISC_FUNCTION_TRACER;
        for(const auto& p: l) {
                p->info();
        }
}

} // end-of-anonymous-namespace

/**
 * Demonstrates late binding.
 * @return      status
 * @exception   None.
 */
int app_poly1()
{
        COMP_MISC_FUNCTION_TRACER;


        COMP_MISC_TRACER_OUTPUT_OFF;            // Setting the log output ON/OFF
        list<shared_ptr<Vehicle>> l1 {
                make_shared<RoadVehicle>(), make_shared<RoadVehicle>(), make_shared<PassengerRoadVehicle>(5)
        };

        COMP_MISC_TRACER_OUTPUT_ON;             // Setting the log output ON/OFF
        COMP_MISC_LOG_TRACER("invocation for l1:");
        display_all(l1);
        COMP_MISC_LOG_TRACER("done with l1.");

        COMP_MISC_TRACER_OUTPUT_OFF;            // Setting the log output ON/OFF
        list<shared_ptr<Vehicle>> l2 {
                make_shared<RoadVehicle>(), make_shared<Bicycle>("Honda", "black"), make_shared<SailBoat>("Freddy")
        };

        COMP_MISC_TRACER_OUTPUT_ON;             // Setting the log output ON/OFF
        COMP_MISC_LOG_TRACER("invocation for l2:");
        display_all(l2);
        COMP_MISC_LOG_TRACER("done with l2.");

        COMP_MISC_LOG_TRACER(">>>> statement: return 0;");
        return 0;
}
