#ifndef EVENT_HPP
#define EVENT_HPP

#include "Types.hpp"
#include <any>
#include <unordered_map>


class Event {
	public:
		Event() = delete;

		explicit Event(EventId type_): type(type_) {}

		template<typename T>
		void setParam(EventId id, T value) {
			data[id] = value;
		}

		template<typename T>
		T getParam(EventId id) {
			return std::any_cast<T>(data[id]);
		}

		EventId getType() const {
			return type;
		}

	private:
		EventId type{};
		std::unordered_map<EventId, std::any> data{};
};

#endif // EVENT_HPP
