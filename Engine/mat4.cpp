#include "mat4.h"

namespace math {
	namespace matrices {

		mat4::mat4()
		{
			for (size_t i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;
		}

		mat4::mat4(float diagonal)
		{
			for (size_t i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;
		
			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}

		mat4 mat4::identity() { return mat4(1.0f); }

		mat4& mat4::multiply(const mat4& other)
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{
						sum += elements[x + e * 4] * other.elements[e + y * 4];
					}
					elements[x + y * 4] = sum;
				}
			}

			return *this;
		}

		mat4 operator*(mat4 left, const mat4& right) { return left.multiply(right); }

		mat4 mat4::operator*=(const mat4& other) { return multiply(other); }

		mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far) 
		{
			mat4 result = mat4(1.0f);

			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);

			result.elements[0 + 3 * 4] = (left + right) / (left - right);
			result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		}

		mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
		{
			mat4 result(0.0f);

			float q = 1.0f / tan(toRadians(0.5f * fov));
			float a = q / aspectRatio;

			// 1 / (ar * tan(a/2))
			result.elements[0 + 0 * 4] = a;
			// 1 / tan(a/2)
			result.elements[1 + 1 * 4] = q;
			// (-nearZ - farZ) / (nearZ - farZ)
			result.elements[2 + 2 * 4] = (-near - far) / (near - far);
			// (2 * nearZ * farZ) / (nearZ - farZ)
			result.elements[2 + 3 * 4] = (2.0f * near * far) / (near - far);
			// -1
			result.elements[3 + 2 * 4] = -1.0f;

			return result;
		}

		mat4 mat4::translation(const vectors::vec3& translation) 
		{
			mat4 result(1.0f);

			result.elements[0 + 3 * 4] = translation.x;
			result.elements[1 + 3 * 4] = translation.y;
			result.elements[2 + 3 * 4] = translation.z;

			return result;
		}

		mat4 mat4::rotate(float angle, const vectors::vec3& axis)
		{
			mat4 result(1.0f);

			float r = toRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1.0f - c;

			result.elements[0 + 0 * 4] = axis.x * omc + c;
			result.elements[1 + 0 * 4] = axis.y * axis.x * omc + axis.z * s;
			result.elements[2 + 0 * 4] = axis.x * axis.z * omc - axis.y * s;

			result.elements[0 + 1 * 4] = axis.x * axis.y * omc - axis.z * s;
			result.elements[1 + 1 * 4] = axis.y * omc + c;
			result.elements[2 + 1 * 4] = axis.y * axis.z * omc + axis.x * s;

			result.elements[0 + 2 * 4] = axis.x * axis.z * omc + axis.y * s;
			result.elements[1 + 2 * 4] = axis.y * axis.z * omc - axis.x * s;
			result.elements[2 + 2 * 4] = axis.z * omc + c;

			return result;
		}

		mat4 mat4::scale(const vectors::vec3& scale)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;

			return result;
		}

	}
}