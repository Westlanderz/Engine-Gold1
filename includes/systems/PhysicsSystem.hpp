#ifndef PHYSICSSYSTEM_HPP
#define PHYSICSSYSTEM_HPP

#include "../core/System.hpp"
#include "../../includes/core/Coordinator.hpp"
#include <memory>

class PhysicsSystem : public System {
	public:
		void Init();
		void Update(float dt);
};

#endif // PHYSICSSYSTEM_HPP
