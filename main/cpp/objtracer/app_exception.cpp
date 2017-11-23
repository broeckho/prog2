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

/// Simple Exception root class.
class Exception : public std::exception
{
public:
        /// Constructor initializes message for the exception.
        Exception(const std::string m) : m_message(std::move(m)) {}

        /// Return message text.
        virtual const char* what() const noexcept {return m_message.c_str();}

        /// Get info.
        virtual string get_info() const {return "Exception";}
private:
        string m_message;
};


class MotionException: public Exception
{
public:
        /// Constructor initializes message for the exception.
        MotionException(const std::string m) : Exception(std::move(m)) {}

        /// Get info.
        string get_info() const override {return "MotionException";}
};

class LoadingException: public Exception
{
public:
        /// Constructor initializes message for the exception.
        LoadingException(const std::string m) : Exception(std::move(m)) {}

        /// Get info.
        string get_info() const override {return "LoadingException";}
};

class SailingException: public MotionException
{
public:
        /// Constructor initializes message for the exception.
        SailingException(const std::string m) : MotionException(std::move(m)) {}

        /// Get info.
        string get_info() const override {return "SailingException";}
};


/**
 * Demo prog for ctor/dtor features in class derivation.
 * @return      status
 * @exception   None.
 */
int app_exception()
{
        COMP_MISC_FUNCTION_TRACER;
        try{
                COMP_MISC_BLOCK_TRACER("Try block");

                COMP_MISC_LOG_TRACER(" statement: Bicycle m1(\"Honda\", \"red\");");
                Bicycle m1("Honda", "red");

                COMP_MISC_LOG_TRACER(" statement: m1.displayInfo();");
                m1.get_info();

                COMP_MISC_LOG_TRACER(" statement: SailBoat s1(\"Marina\");");
                SailBoat s1("Marina");;

                vector<double> direction(2);
                direction[0] = 1.0;
                direction[1] = -1.0;
                COMP_MISC_LOG_TRACER(" statement: s1.move(4, direction);");
                s1.move(4, direction);

                if (direction[0] == 1.0)
                {
                        throw MotionException("Help");
                }

                COMP_MISC_LOG_TRACER(" statement: s1.startSinking();");
                s1.start_sinking();

                COMP_MISC_LOG_TRACER(" statement: s1.displayInfo();");
                s1.get_info();
        }
        catch(Exception e) {                                            // TRY OUT ALL ALTERNATIVES HERE
                cout << "! Exception: " << e.get_info() << endl;        // AND ADD MORE CATCH CLAUSES
                cout << "! message  : " << e.what() << endl;
        }

        COMP_MISC_LOG_TRACER(" statement: return 0;");
        return 0;
}
