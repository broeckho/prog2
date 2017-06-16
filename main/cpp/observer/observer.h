#pragma once

#include <algorithm>
#include <memory>
#include <vector>

namespace observer {
/**
 * A base class for observers: objects that can be registered with
 * Observable instances to recieve event notifications.
 */
template <typename... TArgs>
class Observer
{
public:
	virtual ~Observer() {}

	/**
	 * Notifies this observer of an event.
	 */
	virtual void Notify(TArgs... args) = 0;
};

/**
 * An observable value: a type of object that can push notifications
 * to a collection of observers. The collection of observers is mutable.
 */
template <typename... TArgs>
class Observable
{
public:
	/**
	 * Registers the given observer with this observable's collection
	 * of observers.
	 */
	void Register(std::shared_ptr<Observer<TArgs...>> obs) { m_observerCollection.push_back(obs); }

	/**
	 * Removes the given observer from this observable's collection
	 * of observers.
	 */
	void Unregister(std::shared_ptr<Observer<TArgs...>> obs)
	{
		m_observerCollection.erase(std::remove(m_observerCollection.begin(), m_observerCollection.end(), obs),
					   m_observerCollection.end());
	}

	/**
	 * Notifies all registered observers of an event.
	 */
	void NotifyObservers(TArgs... args)
	{
		for (const auto& obs : m_observerCollection)
			obs->Notify(args...);
	}

private:
	// Stores the collection of observers to notify when an event happens.
	std::vector<std::shared_ptr<Observer<TArgs...>>> m_observerCollection;
};
}
