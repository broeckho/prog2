/**
 * @file
 * Implementation for the Engine class used to demo object aggregation features.
 * @author J. Broeckhove  CoMP/UA
 */

#include "objtracer/Exception.h"
#include "tracer/tracer.h"

namespace ODemo {

using namespace std;

Exception::Exception(std::string m) : m_message(std::move(m)) { COMP_MISC_MEMBER_TRACER; }

Exception::Exception(const Exception& e) : m_message(e.m_message) { COMP_MISC_MEMBER_TRACER; }

Exception::Exception(Exception&& e) noexcept : m_message(std::move(e.m_message)) { COMP_MISC_MEMBER_TRACER; }

const char* Exception::what() const noexcept
{
        COMP_MISC_MEMBER_TRACER;
        return m_message.c_str();
}

void Exception::info() const { COMP_MISC_MEMBER_TRACER; }

MotionException::MotionException(std::string m) : Exception(std::move(m)) { COMP_MISC_MEMBER_TRACER; }

void MotionException::info() const { COMP_MISC_MEMBER_TRACER; }

LoadingException::LoadingException(std::string m) : Exception(std::move(m)) { COMP_MISC_MEMBER_TRACER; }

void LoadingException::info() const { COMP_MISC_MEMBER_TRACER; }

SailingException::SailingException(std::string m) : MotionException(std::move(m)) { COMP_MISC_MEMBER_TRACER; }

void SailingException::info() const { COMP_MISC_MEMBER_TRACER; }

} // namespace ODemo
