#ifndef TYPES_HPP
#define TYPES_HPP

#include <bitset>
#include <cstdint>

// Source: https://gist.github.com/Lee-R/3839813
constexpr std::uint32_t fnv1a_32(char const* s, std::size_t count)
{
	return count ? (fnv1a_32(s, count - 1) ^ s[count - 1]) * 16777619u : 2166136261u;
	// return ((count ? fnv1a_32(s, count - 1) : 2166136261u) ^ s[count]) * 16777619u; // NOLINT (hicpp-signed-bitwise)
}

constexpr std::uint32_t operator "" _hash(char const* s, std::size_t count)
{
	return fnv1a_32(s, count);
}


// ECS types
using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 10;
using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;

// Events
using EventId = std::uint32_t;
using ParamId = std::uint32_t;

#define METHOD_LISTENER(EventType, Listener) EventType, std::bind(&Listener, this, std::placeholders::_1)
#define FUNCTION_LISTENER(EventType, Listener) EventType, std::bind(&Listener, std::placeholders::_1)

// TODO: Make these easier to define and use (macro?)
// TODO: Add some kind of enforcement/automation that a SetParam type and a GetParam type match

namespace Events::Window {
const EventId QUIT = 1;
const EventId RESIZED = 2;
const EventId INPUT = 3;
}

namespace Events::Window::Input {
const ParamId INPUT = 4;
}

namespace Events::Window::Resized {
const ParamId WIDTH = 5;
const ParamId HEIGHT = 6;
}

// Input
enum class InputButtons
{
	W,
	A,
	S,
	D,
	Q,
	E
};


#endif // TYPES_HPP
