#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 {
	public:
		float x, y;

		Vector2();
		Vector2(float x, float y);

		Vector2 operator+(const Vector2& other);
		Vector2 operator-(const Vector2& other);
		Vector2 operator*(const Vector2& other);
		Vector2 operator/(const Vector2& other);

		Vector2 operator+(float other);
		Vector2 operator-(float other);
		Vector2 operator*(float other);
		Vector2 operator/(float other);

		Vector2& operator+=(const Vector2& other);
		Vector2& operator-=(const Vector2& other);
		Vector2& operator*=(const Vector2& other);
		Vector2& operator/=(const Vector2& other);

		Vector2& operator+=(float other);
		Vector2& operator-=(float other);
		Vector2& operator*=(float other);
		Vector2& operator/=(float other);

		bool operator==(const Vector2& other);
		bool operator!=(const Vector2& other);

		float length();
		float lengthSquared();
		Vector2 normalize();
		float dot(const Vector2& other);
		Vector2 cross(const Vector2& other);
};

#endif // VECTOR2_HPP
