#pragma once
/**
 * @file
 * Header for the class MemberTracer.
 * @author J.Broeckhove  CoMP/UA
 */

#include "tracer/TracerOutput.h"
#include <iosfwd>
#include <string>

/// Macro to take advantage of PRETTY_FUNCTION over plain FUNCTION with gcc.
#if defined(__GNUC__)
#define COMP_MISC_FUNCTION_NAME __PRETTY_FUNCTION__
#else
#define COMP_MISC_FUNCTION_NAME __FUNCTION__
#endif

/// Macro for tracking member scope.
/// level.
#define COMP_MISC_MEMBER_TRACER                                                                                        \
        UA_CoMP::Misc::MemberTracer macro_defined_member_tracer##__LINE__(COMP_MISC_FUNCTION_NAME, this)

namespace UA_CoMP {
namespace Misc {

using std::string;
// using google::LogSeverity;

/**
 * Class whose constructor/destructor pair are used to mark entering
 * and leaving a member (function) body block.
 * You do this by defining an automatic variable of CodeTracker type
 * at the beginning of the member body. The constructor triggers an
 * appropriate message.The destructor for the variable gets called
 * when leaving the member function body and triggers the appropriate
 * message. The messages are logged through the TrackerOutput.
 */
class MemberTracer
{
public:
        /// Constructor inserts message in TrackerOutput about entering member body.
        MemberTracer(string const& member_name, void const* object_this,
                     LogSeverity severity = TracerOutput::get_severity());

        /// Destructor inserts message in TrackerOutput about leaving member body.
        ~MemberTracer();

private:
        MemberTracer(MemberTracer const&);
        MemberTracer& operator=(MemberTracer const&);
        std::string const m_member_name;
        void const* const m_object_this;
        LogSeverity const m_severity;
};

} // end of namespace
} // end of namespace

