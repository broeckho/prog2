/**
 * @file
 * Implementation for the class MemberTracer.
 * @author J.Broeckhove  CoMP/UA
 */

#include "tracer/MemberTracer.h"
#include <sstream>

namespace UA_CoMP {
namespace Misc {

using namespace std;

MemberTracer::MemberTracer(const string& member_name, const void* object_this)
    : m_member_name(member_name), m_object_this(object_this)
{
        std::ostringstream ss;
        ss << "---> member for object: " << m_object_this << " : " << m_member_name;
        g_tracer_log.log(ss.str());
        g_tracer_log.increase_indent();
}

MemberTracer::~MemberTracer()
{
        g_tracer_log.decrease_indent();
        std::ostringstream ss;
        ss << "<--- member for object: " << m_object_this << " : " << m_member_name;
        g_tracer_log.log(ss.str());
}

} // end of namespace Misc
} // end of namespace UA_CoMP
