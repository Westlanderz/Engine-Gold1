#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Event.hpp"
#include "Types.hpp"
#include <functional>
#include <list>
#include <unordered_map>


class EventManager {
	public:
		void addListener(EventId eventId, std::function<void(Event&)> const& listener) {
			listeners[eventId].push_back(listener);
		}

		void sendEvent(Event& event) {
			uint32_t type = event.getType();

			for(auto const& listener : listeners[type]) {
				listener(event);
			}
		}

		void sendEvent(EventId eventId) {
			Event event(eventId);

			for(auto const& listener : listeners[eventId]) {
				listener(event);
			}
		}

	private:
		std::unordered_map<EventId, std::list<std::function<void(Event&)>>> listeners;
};

#endif // EVENTMANAGER_HPP
