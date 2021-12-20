#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

struct Rigidbody {
    float mass;
    float drag;
    float angularDrag;
    bool useGravity;
    bool isKinematic;
    bool freezeRotation;
};

#endif // RIGIDBODY_HPP
