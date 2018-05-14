#pragma once
/**
 * @file
 * Header for TracerOutput.
 * @author J.Broeckhove  CoMP/UA
 */

#include <string>

/// Macro for turning tracker output on.
#define COMP_MISC_TRACER_OUTPUT_ON UA_CoMP::Misc::g_tracer_log.set_output_on()

/// Macro for turning tracker output off.
#define COMP_MISC_TRACER_OUTPUT_OFF UA_CoMP::Misc::g_tracer_log.set_output_off()

/// Macro for inserting log message into tracker output at current severity level.
#define COMP_MISC_LOG_TRACER(MSG) UA_CoMP::Misc::g_tracer_log.log(MSG)

namespace UA_CoMP {
namespace Misc {

/**
 * Class used to channel output of the BlockTracer, FunctionTracer
 * and MemberTracer objects to the g3log.
 * Manages the following features for the Tracer object's output:
 * \li on or off status of producing output to the log
 * \li the indentation levels when blocks get nested
 */
class TracerOutput
{
public:
        /// No constructor.
        TracerOutput() = default;

        /// Indicate whether current making output.
        bool is_output_on();

        /// Start making output (ok even output already started).
        void set_output_on();

        /// Stop making output (ok even if output already stopped).
        void set_output_off();

        /// Increase the indentation level.
        void increase_indent();

        /// Decrease the indentation level.
        void decrease_indent();

        /// Insert the message in the google log at given severity level.
        void log(const std::string& msg);

private:
        bool m_make_output{true};
        unsigned int m_indent{0};
};

/// TracerOutput instance connected to g3log default logger.
extern TracerOutput g_tracer_log;

} // namespace Misc
} // namespace UA_CoMP
