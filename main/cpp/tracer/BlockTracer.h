#pragma once
/**
 * @file
 * Header for the class BlockTracer.
 * @author J.Broeckhove  CoMP/UA
 */

#include "tracer/TracerOutput.h"
#include <iosfwd>
#include <string>

/// Macro for tracking block scope.
#define COMP_MISC_BLOCK_TRACER(MSG) UA_CoMP::Misc::BlockTracer macro_defined_block_tracer##__LINE__(MSG)

namespace UA_CoMP {
namespace Misc {

using std::string;

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
        explicit BlockTracer(string const& msg, LogSeverity severity = TracerOutput::get_severity());

        /// Destructor inserts message in TrackerOutput about leaving a block.
        ~BlockTracer();

private:
        BlockTracer(BlockTracer const&);
        BlockTracer& operator=(BlockTracer const&);
        std::string const m_msg;
        LogSeverity const m_severity;
};

} // end of namespace
} // end of namespace

