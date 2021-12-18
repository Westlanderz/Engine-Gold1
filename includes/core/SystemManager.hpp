#ifndef SYSTEMMANAGER_HPP
#define SYSTEMMANAGER_HPP

#include "System.hpp"
#include "Types.hpp"
#include <unordered_map>

class SystemManager {
    private:
        std::unordered_map<const char*, Signature> signatures;
        std::unordered_map<const char*, std::shared_ptr<System>> systems;

    public:
        template<typename T>
        std::shared_ptr<T> registerSystem();

        template<typename T>
        void setSignature(Signature signature);
        
        void entityDestroyed(Entity entity);
        void entitySignatureChanged(Entity entity, Signature Signature);
};

#endif // SYSTEMMANAGER_HPP
