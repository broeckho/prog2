// This example illustates the observer pattern. The 'main' function
// creates an Observable, and registers a few trivial observer instances.

#include "observer.h"

#include <iostream>
#include <string>

using namespace observer;

/**
 * An observer implementation that prints messages to the command-line.
 */
class PrintingObserver final : public Observer<const std::string&>
{
public:
	/// Notifies this observer of an event.
	virtual void Notify(const std::string& message) override final
	{
		// Simply print the message.
		std::cout << message << std::endl;
	}

	virtual ~PrintingObserver() {}
};

/**
 * An observer implementation that prints messages to the command-line,
 * but prefixes them first.
 */
class PrefixPrintingObserver final : public Observer<const std::string&>
{
public:
	PrefixPrintingObserver(const std::string& prefix) : m_prefix(prefix) {}

	/// Notifies this observer of an event.
	virtual void Notify(const std::string& message) override final
	{
		// Print the prefix first, then print the message.
		std::cout << m_prefix << message << std::endl;
	}

	virtual ~PrefixPrintingObserver() {}

private:
	std::string m_prefix;
};

int main()
{
	// Create an Observable instance to publish events.
	Observable<const std::string&> publisher;
	auto obs1 = std::make_shared<PrintingObserver>();
	auto obs2 = std::make_shared<PrefixPrintingObserver>("Oh, hi! Here's some news for ya: ");
	auto obs3 = std::make_shared<PrefixPrintingObserver>("I have news for you, mortal: ");
	publisher.Register(obs1);
	publisher.Register(obs2);
	publisher.Register(obs3);

	publisher.NotifyObservers("all of the observers have been registered.");

	publisher.Unregister(obs1);
	publisher.Unregister(obs3);

	publisher.NotifyObservers("unregistered all but one of the observers.");
}
