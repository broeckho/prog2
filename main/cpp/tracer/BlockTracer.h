#pragma once
/**
 * @file
 * Header for the class BlockTracer.
 * @author J.Broeckhove  CoMP/UA
 */

#include "tracer/TracerOutput.h"
#include <string>

/// Macro for tracking block scope.
#define COMP_MISC_BLOCK_TRACER(MSG) UA_CoMP::Misc::BlockTracer macro_defined_block_tracer##__LINE__(MSG)

namespace UA_CoMP {
namespace Misc {

/**
 * Class whose constructor/destructor pair are used to mark entering
 * and leaving a code block.
 * You do this by defining an automatic variable of BlockTracer type
 * at the beginning of the block. The constructor triggers an appropriate
 * message.The destructor for the variable gets called when leaving the
 * block and triggers the appropriate message.
 * The messages are logged through the tarcer log.
 */
class BlockTracer
{
public:
        /// Constructor insert message in TrackerOutput about entering a block.
        explicit BlockTracer(const std::string& msg);

        /// No copy constructor.
        BlockTracer(const BlockTracer&) = delete;

        /// No assignment.
        BlockTracer& operator=(const BlockTracer&) = delete;

        /// Destructor inserts message in TracerOutput about leaving a block.
        ~BlockTracer();

private:
        const std::string m_msg;
};

} // namespace Misc
} // namespace UA_CoMP
