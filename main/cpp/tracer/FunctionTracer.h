/**
 * @file
 * Header for class FunctionTracer.
 * @author J.Broeckhove  CoMP/UA
 */

#ifndef GOBELIJN_TRACER_FUNCTIONTRACER_H_
#define GOBELIJN_TRACER_FUNCTIONTRACER_H_

#include "tracer/TracerOutput.h"
#include <iosfwd>
#include <string>

/// Macro to take advantage of PRETTY_FUNCTION over plain FUNCTION with gcc.
#if defined(__GNUC__)
#define UA_COMP_MISC_FUNCTION_NAME __PRETTY_FUNCTION__
#else
#define UA_COMP_MISC_FUNCTION_NAME __FUNCTION__
#endif

/// Macro for tracking function scope with google logging at current severity
/// level.
#define COMP_MISC_FUNCTION_TRACER                                                                                      \
	UA_CoMP::Misc::FunctionTracer macro_defined_function_tracer##__LINE__(COMP_MISC_FUNCTION_NAME)

/// Macro for tracking function scope , with google logging at given severity
/// level
#define COMP_MISC_FUNCTION_TRACER_AT_SEVERITY(LOG_SEVERITY)                                                            \
	UA_CoMP::Misc::FunctionTracer macro_defined_function_tracer##__LINE__(COMP_MISC_FUNCTION_NAME, LOG_SEVERITY)

namespace UA_CoMP {
namespace Misc {

using std::string;
// using google::LogSeverity;

/**
 * Class whose constructor/destructor pair are used to mark entering
 * and leaving a function body block.
 * You do this by defining an automatic variable of CodeTracker type
 * at the beginning of the body. The constructor triggers an appropriate
 * message.The destructor for the variable gets called when leaving the
 * function body and triggers the appropriate message.
 * The messages are logged through the TrackerOutput.
 */
class FunctionTracer
{
public:
	/// Constructor inserts message in TrackerOutput about entering a function
	/// body.
	FunctionTracer(string const& function_name, LogSeverity severity = TracerOutput::get_severity());

	/// Destructor inserts message in TracketOutput about leaving funvtion body.
	~FunctionTracer();

private:
	FunctionTracer(FunctionTracer const&);
	FunctionTracer& operator=(FunctionTracer const&);
	std::string const m_function_name;
	LogSeverity const m_severity;
};

} // end of namespace Misc
} // end of namespace UA_CoMP

#endif // end-of-include-guard
