/**
 * @file
 * Demo for exceptions.
 * @author J.Broeckhove  CoMP/UA
 */

#include "demos.h"
#include "objtracer/demobj.h"
#include "tracer/tracer.h"
#include <iostream>

using namespace ODemo;
using namespace std;

/**
 * Demo prog for ctor/dtor features in class derivation.
 * @return      status
 * @exception   None.
 */
int app_exception()
{
        COMP_MISC_FUNCTION_TRACER;
        try {
                COMP_MISC_BLOCK_TRACER("Try block");

                COMP_MISC_LOG_TRACER(" statement: Bicycle m1(\"Honda\", \"red\");");
                Bicycle m1("Honda", "red");

                COMP_MISC_LOG_TRACER(" statement: m1.get_nfo();");
                m1.info();

                COMP_MISC_LOG_TRACER(" statement: SailBoat s1(\"Marina\");");
                SailBoat s1("Marina");;

                vector<double> direction(2);
                direction[0] = 1.0;
                direction[1] = -1.0;
                COMP_MISC_LOG_TRACER(" statement: s1.move(4, direction);");
                s1.move(4, direction);

                if (direction[0] == 1.0)
                {
                        throw SailingException("Help");
                }

                COMP_MISC_LOG_TRACER(" statement: s1.startSinking();");
                s1.start_sinking();

                COMP_MISC_LOG_TRACER(" statement: s1.displayInfo();");
                s1.info();
        }
        catch(LoadingException& e) {
                COMP_MISC_LOG_TRACER(" catch clause with LoadingException");
                e.info();
        }
        catch(SailingException& e) {
                COMP_MISC_LOG_TRACER(" catch clause with SailingException");
                e.info();
        }
        catch(Exception& e) {
                COMP_MISC_LOG_TRACER(" catch clause with Exception");
                e.info();
                COMP_MISC_LOG_TRACER(e.what());
        }
        COMP_MISC_LOG_TRACER(" statement: return 0;");
        return 0;
}
