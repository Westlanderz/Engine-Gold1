#include "../../includes/math/Vector4.hpp"
#include <math.h>


Vector4::Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {
}

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {
}

Vector4 Vector4::operator+(const Vector4& other) {
	return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vector4 Vector4::operator-(const Vector4& other) {
	return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

Vector4 Vector4::operator*(const Vector4& other) {
	return Vector4(x * other.x, y * other.y, z * other.z, w * other.w);
}

Vector4 Vector4::operator/(const Vector4& other) {
	return Vector4(x / other.x, y / other.y, z / other.z, w / other.w);
}

Vector4 Vector4::operator+(float other) {
	return Vector4(x + other, y + other, z + other, w + other);
}

Vector4 Vector4::operator-(float other) {
	return Vector4(x - other, y - other, z - other, w - other);
}

Vector4 Vector4::operator*(float other) {
	return Vector4(x * other, y * other, z * other, w * other);
}

Vector4 Vector4::operator/(float other) {
	return Vector4(x / other, y / other, z / other, w / other);
}

Vector4& Vector4::operator+=(const Vector4& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}


Vector4& Vector4::operator-=(const Vector4& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Vector4& Vector4::operator*=(const Vector4& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	w *= other.w;
	return *this;
}

Vector4& Vector4::operator/=(const Vector4& other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
	w /= other.w;
	return *this;
}

Vector4& Vector4::operator+=(float other) {
	x += other;
	y += other;
	z += other;
	w += other;
	return *this;
}

Vector4& Vector4::operator-=(float other) {
	x -= other;
	y -= other;
	z -= other;
	w -= other;
	return *this;
}

Vector4& Vector4::operator*=(float other) {
	x *= other;
	y *= other;
	z *= other;
	w *= other;
	return *this;
}

Vector4& Vector4::operator/=(float other) {
	x /= other;
	y /= other;
	z /= other;
	w /= other;
	return *this;
}

float Vector4::length() {
	return sqrt(x * x + y * y + z * z + w * w);
}

Vector4 Vector4::normalize() {
	float len = sqrt(x * x + y * y + z * z + w * w);
    return Vector4(x / len, y / len, z / len, w / len);
}

float Vector4::dot(const Vector4& other) {
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

Vector4 Vector4::cross(const Vector4& other) {
    return Vector4(y * other.z - z * other.y, 
        z * other.x - x * other.z, 
        x * other.y - y * other.x, 
        0.0f);
}
