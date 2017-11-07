/**
 * @file
 * Demo code for deep vs. shallow copy.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "demos.h"
#include "demobj.h"
#include "tracer/tracer.h"

using namespace std;
using namespace ODemo;

/**
 * Demo prog to demonstrate deep & shallow copy operations.
 * @return      status
 * @exception   None.
 */
int app_copy()
{
        COMP_MISC_FUNCTION_TRACER;

        COMP_MISC_LOG_TRACER(" statement: shared_ptr<Engine> e1Ptr(new Engine(100));");
        shared_ptr<Engine> e1Ptr(new Engine(100));

        COMP_MISC_LOG_TRACER(" statement: Person* p1Ptr = new Person(\"Owner 1\");");
        auto p1Ptr = new Person("Owner 1");

        COMP_MISC_LOG_TRACER(" statement: Motorcycle* m1Ptr = new Motorcycle(e1Ptr, p1Ptr);");
        auto m1Ptr = new Motorcycle(e1Ptr, p1Ptr);

        COMP_MISC_LOG_TRACER(" statement: m1Ptr->startEngine();");
        m1Ptr->startEngine();

        COMP_MISC_LOG_TRACER(" statement: Motorcycle* m2Ptr = new Motorcycle(*m1Ptr);");
        auto m2Ptr = new Motorcycle(*m1Ptr);

        COMP_MISC_LOG_TRACER(" statement: Motorcycle m3(shared_ptr<Engine>(new Engine(77)));");
        Motorcycle m3(make_shared<Engine>(77));

        COMP_MISC_LOG_TRACER(" statement: m3 = *m2Ptr;");
        m3 = *m2Ptr;

        COMP_MISC_LOG_TRACER(" statement: m3.stopEngine();");
        m3.stopEngine();

        COMP_MISC_LOG_TRACER(" statement: delete p1Ptr;");
        delete p1Ptr;

        COMP_MISC_LOG_TRACER(" statement: delete m1Ptr;");
        delete m1Ptr;

        COMP_MISC_LOG_TRACER(" statement: delete m2Ptr;");
        delete m2Ptr;

        COMP_MISC_LOG_TRACER(" statement: return 0;");
        return 0;
}
