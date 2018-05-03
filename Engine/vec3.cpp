#include "vec3.h"

namespace math {
	namespace vectors {

		vec3::vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		vec3::vec3(const float& x, const float&y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}


		vec3& vec3::add(const vec3& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;

			return *this;
		}

		vec3& vec3::subtract(const vec3& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;

			return *this;
		}

		vec3& vec3::multiply(const vec3& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;

			return *this;
		}

		vec3& vec3::divide(const vec3& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;

			return *this;
		}
		// Scales the vector by a float
		vec3& vec3::scale(const float& scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;

			return *this;
		}

		vec3& vec3::operator+=(const vec3& other) { return *this = *this + other; }
		vec3& vec3::operator-=(const vec3& other) { return *this = *this - other; }
		vec3& vec3::operator*=(const vec3& other) { return *this = *this * other; }
		vec3& vec3::operator/=(const vec3& other) { return *this = *this / other; }

		vec3& vec3::operator*=(const float& other) { return *this = *this * other; }

		vec3 operator+(vec3 left, const vec3& right) { return left.add(right); }
		vec3 operator-(vec3 left, const vec3& right) { return left.subtract(right); }
		vec3 operator*(vec3 left, const vec3& right) { return left.multiply(right); }
		vec3 operator/(vec3 left, const vec3& right) { return left.divide(right); }

		vec3 operator*(vec3 left, const float& right) { return left.scale(right); }

		bool vec3::operator==(const vec3& other) { return this->x == other.x && this->y == other.y; }
		bool vec3::operator!=(const vec3& other) { return !(*this == other); }

		std::ostream& operator << (std::ostream& stream, const vec3& vector)
		{
			stream << "vec3 (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return stream;
		}

	}
}