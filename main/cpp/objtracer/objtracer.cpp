/**
 * @file
 * Driver to select routines.
 * @author  Jan Broeckhove, CoMP/UA
 */

#include "demos.h"
#include "tclap/CmdLine.h"
#include "util/Exception.h"
#include <exception>
#include <functional>
#include <g3log/g3log.hpp>
#include <g3log/logworker.hpp>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <memory>
#include <string>

using namespace std;
using UA_CoMP::Util::Exception;

namespace {

typedef std::function<int()> Function;

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
}

int main(int argc, char* argv[])
{
	try {
		//----------------------------------------------------------------------
		// Initialize logging library .
		//----------------------------------------------------------------------
		string logPath("/tmp");
		if (getenv("G3LOG_log_dir") != NULL) {
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
		//		<< endl;
		cout << "Process the objdriver output with \"cut -f 2 -d ] <logfile>\" to "
			"get a reasonable output."
		     << endl;

		//----------------------------------------------------------------------
		// Command line definition and parsing.
		//----------------------------------------------------------------------
		TCLAP::CmdLine cmd("Driver for object tracer demos", ' ', "1.0");
		TCLAP::ValueArg<string> exec_arg("", "exec", "Demo to execute", false, "", "string", cmd);
		cmd.parse(argc, argv);

		LOG(INFO) << "Starting main program ...";

		//----------------------------------------------------------------------
		// Setting up the register with available tests
		//----------------------------------------------------------------------
		FunctionRegister f_reg;
		f_reg["exam01"] = exam01;
		f_reg["fcalls"] = fcalls;
		f_reg["mbasics"] = mbasics;
		f_reg["mcopy"] = mcopy;
		f_reg["vbasics"] = vbasics;
		f_reg["vpoly"] = vpoly;

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
