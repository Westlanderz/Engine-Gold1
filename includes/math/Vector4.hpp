#ifndef VECTOR4_HPP
#define VECTOR4_HPP

class Vector4 {
	public:
		float x, y, z, w;

		Vector4();
		Vector4(float x, float y, float z, float w);

		Vector4 operator+(const Vector4& other);
		Vector4 operator-(const Vector4& other);
		Vector4 operator*(const Vector4& other);
		Vector4 operator/(const Vector4& other);

		Vector4 operator+(float other);
		Vector4 operator-(float other);
		Vector4 operator*(float other);
		Vector4 operator/(float other);

		Vector4& operator+=(const Vector4& other);
		Vector4& operator-=(const Vector4& other);
		Vector4& operator*=(const Vector4& other);
		Vector4& operator/=(const Vector4& other);

		Vector4& operator+=(float other);
		Vector4& operator-=(float other);
		Vector4& operator*=(float other);
		Vector4& operator/=(float other);

		bool operator==(const Vector4& other);
		bool operator!=(const Vector4& other);

		float length();
		float lengthSquared();
		Vector4 normalize();
		float dot(const Vector4& other);
		Vector4 cross(const Vector4& other);
};

#endif // VECTOR4_HPP
