#include "../../includes/math/Vector2.hpp"
#include <math.h>

Vector2::Vector2() : x(0.0f), y(0.0f) {
}

Vector2::Vector2(float x_, float y_) : x(x_), y(y_) {
}

Vector2 Vector2::operator+(const Vector2& other) {
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) {
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(const Vector2& other) {
	return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::operator/(const Vector2& other) {
	return Vector2(x / other.x, y / other.y);
}

Vector2 Vector2::operator+(float other) {
	return Vector2(x + other, y + other);
}

Vector2 Vector2::operator-(float other) {
	return Vector2(x - other, y - other);
}

Vector2 Vector2::operator*(float other) {
	return Vector2(x * other, y * other);
}

Vector2 Vector2::operator/(float other) {
	return Vector2(x / other, y / other);
}

Vector2& Vector2::operator+=(const Vector2& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2& Vector2::operator*=(const Vector2& other) {
	x *= other.x;
	y *= other.y;
	return *this;
}

Vector2& Vector2::operator/=(const Vector2& other) {
	x /= other.x;
	y /= other.y;
	return *this;
}

Vector2& Vector2::operator+=(float other) {
	x += other;
	y += other;
	return *this;
}

Vector2& Vector2::operator-=(float other) {
	x -= other;
	y -= other;
	return *this;
}

Vector2& Vector2::operator*=(float other) {
	x *= other;
	y *= other;
	return *this;
}

Vector2& Vector2::operator/=(float other) {
	x /= other;
	y /= other;
	return *this;
}

bool Vector2::operator==(const Vector2& other) {
	return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2& other) {
	return x != other.x || y != other.y;
}

float Vector2::length() {
	return sqrt(x * x + y * y);
}

float Vector2::lengthSquared() {
	return x * x + y * y;
}

Vector2 Vector2::normalize() {
	float length = sqrt(x * x + y * y);
	return Vector2(x / length, y / length);
}

float Vector2::dot(const Vector2& other) {
	return x * other.x + y * other.y;
}

Vector2 Vector2::cross(const Vector2& other) {
	return Vector2(y * other.x - x * other.y, x * other.y - y * other.x);
}
