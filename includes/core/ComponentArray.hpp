#ifndef COMPONENTARRAY_HPP
#define COMPONENTARRAY_HPP

#include "Types.hpp"
#include <array>
#include <unordered_map>

class IComponentArray {
    public:
        virtual ~IComponentArray() = default;
        virtual void entityDestroyed(Entity entity) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
    private: 
        std::array<T, MAX_ENTITIES> components;
        std::unordered_map<Entity, size_t> entityToIndex;
        std::unordered_map<size_t, Entity> indexToEntity;
        size_t size;

    public:
        void insertData(Entity entity, T component);
        void removeData(Entity entity);
        T& getData(Entity entity);
        void entityDestroyed(Entity entity) override;
};

#endif // COMPONENTARRAY_HPP
