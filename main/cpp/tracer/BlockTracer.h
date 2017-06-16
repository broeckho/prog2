/**
 * @file
 * Header for the class BlockTracer.
 * @author J.Broeckhove  CoMP/UA
 */

#ifndef GOBELIJN_TRACER_BLOCKTRACER_H_
#define GOBELIJN_TRACER_BLOCKTRACER_H_

#include "tracer/TracerOutput.h"
#include <iosfwd>
#include <string>

/// Macro for tracking block scope with google logging at current severity
/// level.
#define COMP_MISC_BLOCK_TRACER(MSG) UA_CoMP::Misc::BlockTracer macro_defined_block_tracer##__LINE__(MSG)

/// Macro for tracking block scope with google logging at given severity level.
#define COMP_MISC_BLOCK_TRACER_AT_SEVERITY(MSG, LOG_SEVERITY)                                                          \
	UA_CoMP::Misc::BlockTracer macro_defined_block_tracer##__LINE__(MSG, LOG_SEVERITY)

namespace UA_CoMP {
namespace Misc {

using std::string;
// using google::LogSeverity;

/**
 * Class whose constructor/destructor pair are used to mark entering
 * and leaving a code block.
 * You do this by defining an automatic variable of CodeTracker type
 * at the beginning of the block. The constructor triggers an appropriate
 * message.The destructor for the variable gets called when leaving the
 * block and triggers the appropriate message.
 * The messages are logged through the TrackerOutput.
 */
class BlockTracer
{
public:
	/// Constructor insert message in TrackerOutput about entering a block.
	BlockTracer(string const& msg, LogSeverity severity = TracerOutput::get_severity());

	/// Destructor inserts message in TrackerOutput about leaving a block.
	~BlockTracer();

private:
	BlockTracer(BlockTracer const&);
	BlockTracer& operator=(BlockTracer const&);
	std::string const m_msg;
	LogSeverity const m_severity;
};

} // end of namespace Misc
} // end of namespace UA_CoMP

#endif // end-of-include-guard
