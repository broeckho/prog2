/**
 * @file
 * A C++ code example relating to the material in Stroustrup (3 ed.) chapter 10.
 * @author J. Broeckhove  CoMP/UA, 2011.
 */

#include "demos.h"
#include "objtracer/Motorcycle.h"
#include "tracer/tracer.h"

using namespace std;
using namespace ODemo;

namespace {
void f1(Motorcycle b)
{
        COMP_MISC_FUNCTION_TRACER;
        b.halt();
        b.getSpeed();
}
void f2(Motorcycle& b)
{
        COMP_MISC_FUNCTION_TRACER;
        b.halt();
}
void f2p(Motorcycle* bp)
{
        COMP_MISC_FUNCTION_TRACER;
        bp->halt();
}
void f3(Motorcycle const& b)
{
        COMP_MISC_FUNCTION_TRACER;
        b.is_running();
}
void f3p(Motorcycle const* bp)
{
        COMP_MISC_FUNCTION_TRACER;
        bp->is_running();
}
Motorcycle g() { return Motorcycle(); }
}

/**
 * Demo prog for features of essential ops.
 *
 * @return      status
 * @exception   None.
 */
int fcalls()
{
        COMP_MISC_FUNCTION_TRACER;

        COMP_MISC_LOG_TRACER(" statement: Motorcycle bvar1(shared_ptr<Engine>(new Engine(1.0)));");
        Motorcycle bvar1(shared_ptr<Engine>(new Engine(1.0)));

        COMP_MISC_LOG_TRACER(" statement: f1(bvar1);");
        f1(bvar1);

        COMP_MISC_LOG_TRACER(" statement: f2(bvar1);");
        f2(bvar1);

        COMP_MISC_LOG_TRACER(" statement: f2p(&bvar1);");
        f2p(&bvar1);

        COMP_MISC_LOG_TRACER(" statement: f3(bvar1);");
        f3(bvar1);

        COMP_MISC_LOG_TRACER(" statement: f3p(&bvar1);");
        f3p(&bvar1);

        COMP_MISC_LOG_TRACER(" statement: g();");
        Motorcycle m;
        m = g();

        COMP_MISC_LOG_TRACER(" statement: return 0;");
        return 0;
}
