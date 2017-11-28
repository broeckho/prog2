/**
 * @file
 * Implementation for the class BlockTracer.
 * @author J.Broeckhove  CoMP/UA
 */

#include "tracer/BlockTracer.h"

namespace UA_CoMP {
namespace Misc {

using namespace std;

BlockTracer::BlockTracer(const string& msg): m_msg(msg)
{
        g_tracer_log.log("---> code block: " + m_msg);
        g_tracer_log.increase_indent();
}

BlockTracer::~BlockTracer()
{
        g_tracer_log.decrease_indent();
        g_tracer_log.log("<---  code block: " + m_msg);
}

} // end of namespace
} // end of namespace
