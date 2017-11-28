/**
 * @file
 * Implementation for class TrackerOutput.
 * @author J.Broeckhove  CoMP/UA
 */

#include "tracer/TracerOutput.h"

namespace UA_CoMP {
namespace Misc {

using std::ostringstream;

bool TracerOutput::g_make_output {true};
unsigned int TracerOutput::g_indent {0};
LogSeverity TracerOutput::g_severity {INFO};

bool TracerOutput::is_output_on() { return g_make_output; }

LogSeverity TracerOutput::get_severity() { return g_severity; }

void TracerOutput::set_output_on() { g_make_output = true; }

void TracerOutput::set_output_off() { g_make_output = false; }

void TracerOutput::increase_indent() { g_indent++; }

void TracerOutput::decrease_indent() { g_indent--; }

void TracerOutput::set_severity(const LogSeverity& severity) { g_severity = severity; }

void TracerOutput::log(string const& msg, LogSeverity severity)
{
        if (is_output_on()) {
                ostringstream os;
                for (unsigned int i = 0; i < g_indent; ++i) {
                        os << "     ";
                }
                os << msg;
                LOG(severity) << os.str();
        }
}

} // end of namespace
} // end of namespace
