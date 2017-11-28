/**
 * @file
 * Demo for inheritance hierarchies.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "demos.h"
#include "objtracer/demobj.h"
#include "tracer/tracer.h"
#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "TemplateArgumentsIssues"
using namespace ODemo;
using std::cout;
using std::endl;
using std::vector;
using std::exception;

/**
 * Demo prog for ctor/dtor features in class derivation.
 * @return      status
 * @exception   None.
 */
int app_hierarchies()
{
        COMP_MISC_FUNCTION_TRACER;

        COMP_MISC_LOG_TRACER(" statement: Bicycle m1(\"Honda\", \"red\");");
        Bicycle m1("Honda", "red");

        COMP_MISC_LOG_TRACER(" statement: m1.displayInfo();");
        COMP_MISC_LOG_TRACER(m1.get_info());

        COMP_MISC_LOG_TRACER(" statement: Bicycle m2(m1);");
        Bicycle m2(m1);

        COMP_MISC_LOG_TRACER(" statement: m2.addPassenger();");
        m2.add_passenger();

        COMP_MISC_LOG_TRACER(" statement: m2.displayInfo();");
        COMP_MISC_LOG_TRACER(m2.get_info());

        COMP_MISC_LOG_TRACER(" statement: Bicycle* m3Ptr = new Bicycle(m2);");
        auto m3Ptr = new Bicycle(m2);

        COMP_MISC_LOG_TRACER(" statement: m3Ptr->displayInfo()");
        COMP_MISC_LOG_TRACER(m3Ptr->get_info());

        COMP_MISC_LOG_TRACER(" statement: m2 = m1;");
        m2 = m1;

        COMP_MISC_LOG_TRACER(" statement: delete m3Ptr;");
        delete m3Ptr;

        COMP_MISC_LOG_TRACER(" statement: SailBoat s1(\"Marina\");");
        SailBoat s1("Marina");

        COMP_MISC_LOG_TRACER(" statement: SailBoat s1(\"Freddy\");");
        SailBoat s2("Freddy");

        vector<double> direction(2);
        direction[0] = 1.0;
        direction[1] = -1.0;
        COMP_MISC_LOG_TRACER(" statement: s1.move(4, direction);");
        s1.move(4, direction);

        COMP_MISC_LOG_TRACER(" statement: s1.startSinking();");
        s1.start_sinking();

        COMP_MISC_LOG_TRACER(" statement: s1.displayInfo();");
        COMP_MISC_LOG_TRACER(s1.get_info());

        COMP_MISC_LOG_TRACER(" statement: Vehicle* v1Ptr = &s1;");
        Vehicle* v1Ptr = &s1;

        COMP_MISC_LOG_TRACER(" statement: v1Ptr->displayInfo();");
        v1Ptr->get_info();

        COMP_MISC_LOG_TRACER(" statement: s2 = s1;");
        s2 = s1;

        COMP_MISC_LOG_TRACER(" statement: s2.displayInfo();");
        COMP_MISC_LOG_TRACER(s2.get_info());

        // The following won't compile because WaterVehicle has pure virtual
        // functions.
        // WaterVehicle wv1(s1);

        COMP_MISC_LOG_TRACER(" statement: return 0;");
        return 0;
}

#pragma clang diagnostic pop