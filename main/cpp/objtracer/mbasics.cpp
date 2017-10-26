/**
 * @file
 * Demo code for essential operators (Stroustrup ch 17).
 * @author J. Broeckhove  CoMP/UA
 */

#include "objtracer/Body.h"
#include "objtracer/Motorcycle.h"
#include "objtracer/Unicycle.h"
#include "tracer/tracer.h"
#include <iostream>

using namespace std;
using namespace ODemo;

int mbasics();

/**
 * Demo prog for features of ctor/dtor.
 * @return      status
 * @exception   None.
 */
int mbasics()
{
        cout << __FUNCTION__ << "  haha  " << __PRETTY_FUNCTION__ << endl;
        COMP_MISC_FUNCTION_TRACER;
        {
                COMP_MISC_BLOCK_TRACER("First block");

                COMP_MISC_LOG_TRACER(" statement: shared_ptr<Engine> e1(new Engine(50));");
                shared_ptr<Engine> e1(new Engine(50));

                COMP_MISC_LOG_TRACER(" statement: Unicycle u1();");
                Unicycle u1;

                COMP_MISC_LOG_TRACER(" statement: Motorcycle m1(&e1);");
                Motorcycle m1(e1);
        }
        {
                COMP_MISC_BLOCK_TRACER("Second block");

                COMP_MISC_LOG_TRACER(" statement: Motorcycle m1;");
                Motorcycle m1;

                COMP_MISC_LOG_TRACER(" statement: m.accelerate(1.0);");
                m1.accelerate(1.0);

                COMP_MISC_LOG_TRACER(" statement: Motorcycle m2(m1);");
                Motorcycle m2(m1);

                COMP_MISC_LOG_TRACER(" statement: Motorcycle m3(std::move(m1));");
                Motorcycle m3(std::move(m1));

                COMP_MISC_LOG_TRACER(" statement: m3 = std::move(m2);");
                m3 = std::move(m2);
        }
        {
                COMP_MISC_BLOCK_TRACER("Block for free store ctor/dtor");

                COMP_MISC_LOG_TRACER(" statement: shared_ptr<Engine> ep1(new Engine(80));");
                shared_ptr<Engine> ep1(new Engine(80));

                COMP_MISC_LOG_TRACER(" statement: auto mp1 = new Motorcycle(ep1);");
                auto mp1 = new Motorcycle(ep1);

                COMP_MISC_LOG_TRACER(" statement: delete mp1;");
                delete mp1;
        }

        COMP_MISC_LOG_TRACER(" statement: return 0;");
        return 0;
}
