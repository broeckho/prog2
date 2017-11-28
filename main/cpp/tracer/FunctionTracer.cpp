/**
 * @file
 * Implementation for the class FunctionTracer.
 * @author J.Broeckhove  CoMP/UA
 */

#include "tracer/FunctionTracer.h"

namespace UA_CoMP {
namespace Misc {

using namespace std;

FunctionTracer::FunctionTracer(const string& function_name)
    : m_function_name(function_name)
{
        g_tracer_log.log("---> function body: " + m_function_name);
        g_tracer_log.increase_indent();
}

FunctionTracer::~FunctionTracer()
{
        g_tracer_log.decrease_indent();
        g_tracer_log.log("<--- function body: " + m_function_name);
}

} // end of namespace
} // end of namespace
