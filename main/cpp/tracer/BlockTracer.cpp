/**
 * @file
 * Implementation for the class BlockTracer.
 * @author J.Broeckhove  CoMP/UA
 */

#include "tracer/BlockTracer.h"

namespace UA_CoMP {
namespace Misc {

using std::string;

///
BlockTracer::BlockTracer(string const& msg, LogSeverity severity) : m_msg(msg), m_severity(severity)
{
        TracerOutput::log("---> code block: " + m_msg, m_severity);
        TracerOutput::increase_indent();
}

///
BlockTracer::~BlockTracer()
{
        TracerOutput::decrease_indent();
        TracerOutput::log("<---  code block: " + m_msg, m_severity);
}

} // end of namespace
} // end of namespace
