#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Vector3.hpp"

struct Transform {
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
};

#endif // TRANSFORM_HPP