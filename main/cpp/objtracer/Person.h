#pragma once
/**
 * @file
 * Header for the class Person.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include <string>

namespace ODemo {

/**
 * A fairly simple class for Person.
 * Person does not model the concept Assignable (cfr. Austern,
 * Generic Programming and the STL, Chapter 6).
 */
class Person
{
public:
        /// Constructor initializes the name of the person.
        explicit Person(std::string name);

        /// Disallow copy-construction of people:
        Person(const Person&) = delete;

        /// Disallow move-construction of people:
        Person(Person&&) = delete;

        /// Disallow copy-assignmentof people:
        Person& operator=(const Person&) = delete;

        /// Disallow move-assignment of people:
        Person& operator=(Person&&) = delete;

        /// Destructor.
        virtual ~Person();

        /// Return the persons name.
        std::string get_name() const;

private:
        std::string m_name;
};

} // namespace ODemo
