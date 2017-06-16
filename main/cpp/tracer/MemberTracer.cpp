/**
 * @file
 * Implementation for the class MemberTracer.
 * @author J.Broeckhove  CoMP/UA
 */

#include "tracer/MemberTracer.h"
#include "tracer/TracerOutput.h"
#include <sstream>
#include <string>

namespace UA_CoMP {
namespace Misc {

///
MemberTracer::MemberTracer(string const& member_name, void const* object_this, LogSeverity severity)
    : m_member_name(member_name), m_object_this(object_this), m_severity(severity)
{
	std::ostringstream ss;
	ss << "---> member for object: " << m_object_this << " : " << m_member_name;
	TracerOutput::log(ss.str(), m_severity);
	TracerOutput::increase_indent();
}

///
MemberTracer::~MemberTracer()
{
	TracerOutput::decrease_indent();
	std::ostringstream ss;
	ss << "<--- member for object: " << m_object_this << " : " << m_member_name;
	TracerOutput::log(ss.str(), m_severity);
}

} // end of namespace Misc
} // end of namespace UA_CoMP
