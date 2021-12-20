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
};

#endif // MATRIX4X4_HPP
