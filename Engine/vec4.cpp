#include "vec4.h"

namespace math {
	namespace vectors {

		vec4::vec4()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}

		vec4::vec4(const float& x, const float&y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}


		vec4& vec4::add(const vec4& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;

			return *this;
		}

		vec4& vec4::subtract(const vec4& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;

			return *this;
		}

		vec4& vec4::multiply(const vec4& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			this->w *= other.w;

			return *this;
		}

		vec4& vec4::divide(const vec4& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			this->w /= other.w;

			return *this;
		}
		// Scales the vector by a float
		vec4& vec4::scale(const float& scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			this->w *= scalar;

			return *this;
		}

		vec4& vec4::operator+=(const vec4& other) { return *this = *this + other; }
		vec4& vec4::operator-=(const vec4& other) { return *this = *this - other; }
		vec4& vec4::operator*=(const vec4& other) { return *this = *this * other; }
		vec4& vec4::operator/=(const vec4& other) { return *this = *this / other; }

		vec4& vec4::operator*=(const float& other) { return *this = *this * other; }

		vec4 operator+(vec4 left, const vec4& right) { return left.add(right); }
		vec4 operator-(vec4 left, const vec4& right) { return left.subtract(right); }
		vec4 operator*(vec4 left, const vec4& right) { return left.multiply(right); }
		vec4 operator/(vec4 left, const vec4& right) { return left.divide(right); }

		vec4 operator*(vec4 left, const float& right) { return left.scale(right); }

		bool vec4::operator==(const vec4& other) { return this->x == other.x && this->y == other.y; }
		bool vec4::operator!=(const vec4& other) { return !(*this == other); }

		std::ostream& operator << (std::ostream& stream, const vec4& vector)
		{
			return stream << "vec4 (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		}

	}
}