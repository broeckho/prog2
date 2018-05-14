/**
 * @file
 * Implementation for class TrackerOutput.
 * @author J.Broeckhove  CoMP/UA
 */

#include "tracer/TracerOutput.h"
#include <g3log/g3log.hpp>

namespace UA_CoMP {
namespace Misc {

using namespace std;

TracerOutput g_tracer_log;

bool TracerOutput::is_output_on() { return m_make_output; }

void TracerOutput::set_output_on() { m_make_output = true; }

void TracerOutput::set_output_off() { m_make_output = false; }

void TracerOutput::increase_indent() { m_indent++; }

void TracerOutput::decrease_indent() { m_indent--; }

void TracerOutput::log(const string& msg)
{
        if (is_output_on()) {
                ostringstream os;
                for (unsigned int i = 0; i < m_indent; ++i) {
                        os << "     ";
                }
                os << msg;
                LOG(INFO) << os.str();
        }
}

} // namespace Misc
} // namespace UA_CoMP
