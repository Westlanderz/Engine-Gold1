#ifndef PHYSICSSYSTEM_HPP
#define PHYSICSSYSTEM_HPP

#include "../core/System.hpp"

class PhysicsSystem : public System {
	public:
		std::shared_ptr<PhysicsSystem> Init();

		void Update(float dt);
};

#endif // PHYSICSSYSTEM_HPP
