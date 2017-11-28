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
        explicit Exception(std::string m);

        /// Copy constructor.
        Exception(const Exception& e);

        /// Move Constructor.
        Exception(Exception&& e) noexcept;

        /// Return message text.
        const char* what() const noexcept override;

        /// Get info.
        virtual void info() const;
private:
        std::string m_message;
};

class MotionException: public Exception
{
public:
        /// Constructor initializes message for the exception.
        explicit MotionException(std::string m);

        /// Get info.
        void info() const override;
};

class LoadingException: public Exception
{
public:
        /// Constructor initializes message for the exception.
        explicit LoadingException(std::string m);

        /// Get info.
        void info() const override;
};

class SailingException: public MotionException
{
public:
        /// Constructor initializes message for the exception.
        explicit SailingException(std::string m);

        /// Get info.
        void info() const override;
};



} // end_of_namespace
