#include "../../includes/math/Vector3.hpp"
#include <math.h>

Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {
}


Vector3::Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {
}

Vector3 Vector3::operator+(const Vector3& other) {
	return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) {
	return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(const Vector3& other) {
	return Vector3(x * other.x, y * other.y, z * other.z);
}

Vector3 Vector3::operator/(const Vector3& other) {
	return Vector3(x / other.x, y / other.y, z / other.z);
}

Vector3 Vector3::operator+(float other) {
	return Vector3(x + other, y + other, z + other);
}

Vector3 Vector3::operator-(float other) {
	return Vector3(x - other, y - other, z - other);
}

Vector3 Vector3::operator*(float other) {
	return Vector3(x * other, y * other, z * other);
}

Vector3 Vector3::operator/(float other) {
	return Vector3(x / other, y / other, z / other);
}

Vector3& Vector3::operator+=(Vector3 const& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3& Vector3::operator-=(Vector3 const& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3& Vector3::operator*=(Vector3 const& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	return *this;
}


Vector3& Vector3::operator/=(Vector3 const& other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
	return *this;
}

Vector3& Vector3::operator+=(float other) {
	x += other;
	y += other;
	z += other;
	return *this;
}

Vector3& Vector3::operator-=(float other) {
	x -= other;
	y -= other;
	z -= other;
	return *this;
}

Vector3& Vector3::operator*=(float other) {
	x *= other;
	y *= other;
	z *= other;
	return *this;
}

Vector3& Vector3::operator/=(float other) {
	x /= other;
	y /= other;
	z /= other;
	return *this;
}

float Vector3::dot(const Vector3& other) {
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3& other) {
	return Vector3(y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x);
}

float Vector3::length() {
	return sqrt(x * x + y * y + z * z);
}

float Vector3::lengthSquared() {
	return x * x + y * y + z * z;
}

Vector3 Vector3::normalize() {
	float length = sqrt(x * x + y * y + z * z);
	return Vector3(x / length, y / length, z / length);
}
