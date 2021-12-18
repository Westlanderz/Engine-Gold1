#ifndef VECTOR3_HPP
#define VECTOR3_HPP

class Vector3 {
	public:
		float x, y, z;

		Vector3();
		Vector3(float x, float y, float z);

		Vector3 operator+(const Vector3& other);
		Vector3 operator-(const Vector3& other);
		Vector3 operator*(const Vector3& other);
		Vector3 operator/(const Vector3& other);

		Vector3 operator+(float other);
		Vector3 operator-(float other);
		Vector3 operator*(float other);
		Vector3 operator/(float other);

		Vector3& operator+=(const Vector3& other);
		Vector3& operator-=(const Vector3& other);
		Vector3& operator*=(const Vector3& other);
		Vector3& operator/=(const Vector3& other);

		Vector3& operator+=(float other);
		Vector3& operator-=(float other);
		Vector3& operator*=(float other);
		Vector3& operator/=(float other);

		bool operator==(const Vector3& other);
		bool operator!=(const Vector3& other);

		float length();
		float lengthSquared();
		Vector3 normalize();
		float dot(const Vector3& other);
		Vector3 cross(const Vector3& other);
};

#endif // VECTOR3_HPP
