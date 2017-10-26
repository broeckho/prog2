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

using namespace std;
using namespace ODemo;

namespace {

void display(Vehicle* p)
{
        COMP_MISC_FUNCTION_TRACER;
        p->get_info();
}

void displayBis(Vehicle& b)
{
        COMP_MISC_FUNCTION_TRACER;
        b.get_info();
}

} // end-of-anonymous-namespace

/**
 * Demonstrates late binding.
 * @return      status
 * @exception   None.
 */
int vpoly()
{
        COMP_MISC_FUNCTION_TRACER;

        COMP_MISC_LOG_TRACER(">>>> statement: RoadVehicle rv1;");
        RoadVehicle rv1;

        COMP_MISC_LOG_TRACER(">>>> statement: Bicycle m1(\"Honda\", \"black\");");
        Bicycle m1("Honda", "black");

        COMP_MISC_LOG_TRACER(">>>> statement: PassengerRoadVehicle prv1(5);");
        PassengerRoadVehicle prv1(5);

        COMP_MISC_LOG_TRACER(">>>> statement: SailBoat b1(\"Freddy\");");
        SailBoat b1("Freddy");

        COMP_MISC_LOG_TRACER(">>>> statement: displayBis(rv1);");
        displayBis(rv1);

        COMP_MISC_LOG_TRACER(">>>> statement: displayBis(m1);");
        displayBis(m1);

        COMP_MISC_LOG_TRACER(">>>> statement: displayBis(prv1);");
        displayBis(prv1);

        COMP_MISC_LOG_TRACER(">>>> statement: displayBis(b1);");
        displayBis(b1);

        COMP_MISC_LOG_TRACER(">>>> statement: auto rv2Ptr = new RoadVehicle();");
        auto rv2Ptr = new RoadVehicle();

        COMP_MISC_LOG_TRACER(" statement: Bicycle* m1Ptr = &m1;");
        Bicycle* m1Ptr = &m1;

        COMP_MISC_LOG_TRACER(" statement: auto prv2Ptr = new PassengerRoadVehicle(10);");
        auto prv2Ptr = new PassengerRoadVehicle(10);

        COMP_MISC_LOG_TRACER(">>>> statement: SailBoat* b1Ptr = &b1;");
        auto b1Ptr = &b1;

        COMP_MISC_LOG_TRACER(">>>> statement: display(rv2Ptr);");
        display(rv2Ptr);

        COMP_MISC_LOG_TRACER(">>>> statement: display(m1Ptr);");
        display(m1Ptr);

        COMP_MISC_LOG_TRACER(">>>> statement: displayBis(m1);");
        displayBis(m1);

        COMP_MISC_LOG_TRACER(">>>> statement: display(prv2Ptr);");
        display(prv2Ptr);

        COMP_MISC_LOG_TRACER(">>>> statement: display(b1Ptr);");
        display(b1Ptr);

        // delete b1Ptr;
        // Runtime error because of assignment b1Ptr = &b1;
        // So b1Ptr points to local variable that should not be deleted
        // Should have been:
        // delete b1Ptr; b1Ptr = &b1s;
        // in the code a couple of lines earlier.

        // Notice the dynamically allocated object do NOT get destructed: memory
        // leakage.

        COMP_MISC_LOG_TRACER(">>>> statement: return 0;");
        return 0;
}
