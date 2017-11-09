/**
 * @file
 * Implementation for LogTest.
 */

#include "tclap/CmdLine.h"
#include "tracer/tracer.h"
#include <g3log/logworker.hpp>

using namespace std;

int main(int argc, char* argv[])
{
        try {
                // Initialize Google logging library.
                string logPath("/tmp");
                if (getenv("G3LOG_log_dir") != nullptr) {
                        logPath = *getenv("G3LOG_log_dir");
                }
                std::unique_ptr<g3::LogWorker> g3log{g3::LogWorker::createLogWorker()};
                g3log->addDefaultLogger(argv[0], logPath);
                g3::initializeLogging(g3log.get());
                cout << "If you do not want log in /tmp, define environment "
                     << "variable G3LOG_log_dir e.g. with value ./ " << endl;
                // cout << "If you want log on stderr, specify environment" << " variable
                // GLOG_logtostderr with value
                // true. "
                //	<< endl;
                cout << "Process the objdriver output with \"cut -f 2 -d ] <logfile>\" to "
                        "get a reasonable output."
                     << endl;

                UA_CoMP::Misc::TracerOutput::set_severity(INFO);

                // Command line description.
                TCLAP::CmdLine cmd("Command description message", ' ', "0.9");
                TCLAP::ValueArg<string> nameArg("n", "name", "Name to print", true, "homer", "string", cmd);
                TCLAP::SwitchArg reverseSwitch("r", "reverse", "Print name backwards", cmd, false);

                // Parse command line and get the value each argument.
                cmd.parse(argc, static_cast<const char* const *>(argv));
                std::string name(const_cast<const std::string&>(nameArg.getValue()));
                bool reverseName = reverseSwitch.getValue();

                // Do what you intend.
                if (reverseName) {
                        reverse(name.begin(), name.end());
                        cout << "My name (spelled backwards) is: " << name << endl;
                } else {
                        cout << "My name is: " << name << endl;
                }

                // Straight logging to google log
                LOG(INFO) << "hello there: " << endl;

        } catch (TCLAP::ArgException& e) {
                cerr << "error: " << e.error() << " for argument " << e.argId() << std::endl;
        } catch (exception& e) {
                cerr << e.what() << endl;
        } catch (...) {
                cerr << "Unknown exception" << endl;
        }
        cout << "Done, exiting ..." << endl;
        return 0;
}
