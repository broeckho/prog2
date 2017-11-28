#pragma once
/**
 * @file
 * Header for the Exception class.
 * @author J. Broeckhove  CoMP/UA
 */

#include <exception>
#include <string>

namespace ODemo {

/// Simple Exception root class.
class Exception : public std::exception
{
public:
        /// Constructor initializes message for the exception.
        Exception(std::string m);

        /// Copy constructor.
        Exception(const Exception& e);

        /// Move Constructor.
        Exception(Exception&& e);

        /// Return message text.
        virtual const char* what() const noexcept;

        /// Get info.
        virtual std::string get_info() const;
private:
        std::string m_message;
};

class MotionException: public Exception
{
public:
        /// Constructor initializes message for the exception.
        MotionException(std::string m);

        /// Get info.
        std::string get_info() const override;
};

class LoadingException: public Exception
{
public:
        /// Constructor initializes message for the exception.
        LoadingException(std::string m);

        /// Get info.
        std::string get_info() const override;
};

class SailingException: public MotionException
{
public:
        /// Constructor initializes message for the exception.
        SailingException(std::string m);

        /// Get info.
        std::string get_info() const override;
};



} // end_of_namespace
