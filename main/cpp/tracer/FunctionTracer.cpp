/**
 * @file
 * Implementation for the class FunctionTracer.
 * @author J.Broeckhove  CoMP/UA
 */

#include <string>
//#include <glog/logging.h>
#include "tracer/FunctionTracer.h"
#include "tracer/TracerOutput.h"

namespace UA_CoMP {
namespace Misc {

using std::ostringstream;

///
FunctionTracer::FunctionTracer(string const& function_name, LogSeverity severity)
    : m_function_name(function_name), m_severity(severity)
{
	TracerOutput::log("---> function body: " + m_function_name, m_severity);
	TracerOutput::increase_indent();
}

///
FunctionTracer::~FunctionTracer()
{
	TracerOutput::decrease_indent();
	TracerOutput::log("<--- function body: " + m_function_name, m_severity);
}

} // end of namespace Misc
} // end of namespace UA_CoMP