#ifndef MATRIX4X4_HPP
#define MATRIX4X4_HPP

#include "Vector3.hpp"
#include "Vector4.hpp"

class Matrix4x4 {
	public:
		float m[4][4];

		Matrix4x4();
		Matrix4x4(float m00, float m01, float m02, float m03,
				  float m10, float m11, float m12, float m13,
				  float m20, float m21, float m22, float m23,
				  float m30, float m31, float m32, float m33);

		Matrix4x4 operator+(const Matrix4x4& other);
		Matrix4x4 operator-(const Matrix4x4& other);
		Matrix4x4 operator*(const Matrix4x4& other);
		Matrix4x4 operator/(const Matrix4x4& other);

		Vector4 operator*(const Vector4& other);

		Matrix4x4 operator+(float other);
		Matrix4x4 operator-(float other);
		Matrix4x4 operator*(float other);
		Matrix4x4 operator/(float other);

		Matrix4x4& operator+=(const Matrix4x4& other);
		Matrix4x4& operator-=(const Matrix4x4& other);
		Matrix4x4& operator*=(const Matrix4x4& other);
		Matrix4x4& operator/=(const Matrix4x4& other);

		Matrix4x4& operator+=(float other);
		Matrix4x4& operator-=(float other);
		Matrix4x4& operator*=(float other);
		Matrix4x4& operator/=(float other);

		bool operator==(const Matrix4x4& other);
		bool operator!=(const Matrix4x4& other);

		Matrix4x4 transpose();
		Matrix4x4 inverse();
		Matrix4x4 ortho(float left, float right, float bottom, float top, float near, float far);
		Matrix4x4 perspective(float fov, float aspect, float near, float far);
		Matrix4x4 lookAt(Vector3 eye, Vector3 center, Vector3 up);
		Matrix4x4 rotate(float angle, Vector3 axis);
		Matrix4x4 rotateX(float angle);
		Matrix4x4 rotateY(float angle);
		Matrix4x4 rotateZ(float angle);
		Matrix4x4 translate(float x, float y, float z);
		Matrix4x4 translate(Vector3 translation);
		Matrix4x4 scale(float x, float y, float z);
		Matrix4x4 scale(Vector3 scale);
		Matrix4x4 shear(float xy, float xz, float yx, float yz, float zx, float zy);
		Matrix4x4 shear(Vector3 shear);
		Matrix4x4 reflect(Vector3 normal);
		Matrix4x4 reflect(float x, float y, float z);
};

#endif // MATRIX4X4_HPP
