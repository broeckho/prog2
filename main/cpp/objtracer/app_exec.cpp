/**
 * @file
 * Driver to select routines.
 * @author  Jan Broeckhove, CoMP/UA
 */

#include "demos.h"
#include "tclap/CmdLine.h"
#include "util/Exception.h"
#include <g3log/g3log.hpp>
#include <g3log/logworker.hpp>

using namespace std;
using UA_CoMP::Util::Exception;

namespace {

using Function = std::function<int()>;

class FunctionRegister : public map<string, Function>
{
public:
        ///
        bool is_valid(string const& fname) const { return find(fname) != end(); }

        ///
        void list(ostream& os) const
        {
                map<string, Function>::const_iterator itor;
                os << " The available tests are:" << endl << endl;
                for (itor = begin(); itor != end(); itor++) {
                        os << (*itor).first << endl;
                }
                os << endl;
        }
};
} // namespace

int main(int argc, char* argv[])
{
        try {
                //----------------------------------------------------------------------
                // Initialize logging library .
                //----------------------------------------------------------------------
                string logPath("./");
                std::unique_ptr<g3::LogWorker> g3log{g3::LogWorker::createLogWorker()};
                g3log->addDefaultLogger(argv[0], logPath);
                g3::initializeLogging(g3log.get());
                cout << "Process the log with \"cut -f 2 -d ] <logfile>\" to get a clean output." << endl;

                //----------------------------------------------------------------------
                // Command line definition and parsing.
                //----------------------------------------------------------------------
                TCLAP::CmdLine cmd("Driver for object tracer demos", ' ', "1.0");
                TCLAP::ValueArg<string> exec_arg("", "exec", "Demo to execute", false, "", "string", cmd);
                cmd.parse(argc, static_cast<const char* const*>(argv));

                LOG(INFO) << "Starting main program ...";

                //----------------------------------------------------------------------
                // Setting up the register with available tests
                //----------------------------------------------------------------------
                FunctionRegister f_reg;
                f_reg["app_copy"] = app_copy;
                f_reg["app_essentialops"] = app_essentialops;
                f_reg["app_exception"] = app_exception;
                f_reg["app_fcalls"] = app_fcalls;
                f_reg["app_hierarchies"] = app_hierarchies;
                f_reg["app_poly1"] = app_poly1;
                f_reg["app_poly2"] = app_poly2;

                //----------------------------------------------------------------------
                // Set demo to execute
                //----------------------------------------------------------------------
                string choice;
                if (exec_arg.isSet()) {
                        choice = exec_arg.getValue();
                } else {
                        f_reg.list(cout);
                        bool valid = false;
                        ios_base::iostate old_state = cin.exceptions();
                        cin.exceptions(ios_base::eofbit);
                        while (!valid) {
                                cout << "Select a demo by name: ";
                                cin >> choice;
                                if (f_reg.is_valid(choice)) {
                                        valid = true;
                                } else {
                                        cout << "error on input: invalid demo name" << endl;
                                }
                        }
                        cin.exceptions(old_state);
                }

                //----------------------------------------------------------------------
                // Execute it.
                //----------------------------------------------------------------------
                if (!f_reg.is_valid(choice)) {
                        throw UA_CoMP::Util::Exception("error: unknown demo name cannot be executed");
                }
                f_reg[choice]();

                //----------------------------------------------------------------------
                // Wrapping up and exiting
                //----------------------------------------------------------------------
                cout << endl << "Exiting ... " << endl;
                return (0);
        } catch (TCLAP::ArgException& e) {
                cerr << "error: " << e.error() << " for arg " << e.argId() << "  " << endl;
        } catch (exception& e) {
                cerr << endl << "Caught std exception" << endl;
                cerr << e.what() << endl << "Exiting ..." << endl;
        } catch (...) {
                cerr << endl << "Caught unknown exception. Exiting ..." << endl;
        }

        return 0;
}
