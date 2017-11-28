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

/**
 * Class whose constructor/destructor pair are used to mark entering
 * and leaving a member (function) body block.
 * You do this by defining an automatic variable of MemberTracer
 * at the beginning of the member body. The constructor triggers an
 * appropriate message.The destructor for the variable gets called
 * when leaving the member function body and triggers the appropriate
 * message. The messages are logged to the tracer_log.
 */
class MemberTracer
{
public:
        /// Constructor inserts message in TracerOutput about entering member body.
        MemberTracer(const std::string& member_name, const void* object_this);

        /// No copy constructor.
        MemberTracer(const MemberTracer&) =delete;

        /// No assignment.
        MemberTracer& operator=(const MemberTracer&) =delete;

        /// Destructor inserts message in TracerOutput about leaving member body.
        ~MemberTracer();

private:
        const std::string       m_member_name;
        const void* const       m_object_this;
};

} // end of namespace
} // end of namespace

