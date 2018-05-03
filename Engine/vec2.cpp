#include "vec2.h"

namespace math {
	namespace vectors {

		vec2::vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}

		vec2::vec2(const float& x, const float&y)
		{
			this->x = x;
			this->y = y;
		}


		vec2& vec2::add(const vec2& other)
		{
			this->x += other.x;
			this->y += other.y;

			return *this;
		}

		vec2& vec2::subtract(const vec2& other)
		{
			this->x -= other.x;
			this->y -= other.y;

			return *this;
		}

		vec2& vec2::multiply(const vec2& other)
		{
			this->x *= other.x;
			this->y *= other.y;

			return *this;
		}
		
		vec2& vec2::divide(const vec2& other)
		{
			this->x /= other.x;
			this->y /= other.y;

			return *this;
		}
		// Scales the vector by a float
		vec2& vec2::scale(const float& scalar)
		{
			this->x *= scalar;
			this->y *= scalar;

			return *this;
		}

		vec2& vec2::operator+=(const vec2& other) { return *this = *this + other; }
		vec2& vec2::operator-=(const vec2& other) { return *this = *this - other; }
		vec2& vec2::operator*=(const vec2& other) { return *this = *this * other; }
		vec2& vec2::operator/=(const vec2& other) { return *this = *this / other; }

		vec2& vec2::operator*=(const float& other) { return *this = *this * other; }

		vec2 operator+(vec2 left, const vec2& right) { return left.add(right); }
		vec2 operator-(vec2 left, const vec2& right) { return left.subtract(right); }
		vec2 operator*(vec2 left, const vec2& right) { return left.multiply(right); }
		vec2 operator/(vec2 left, const vec2& right) { return left.divide(right); }
		
		vec2 operator*(vec2 left, const float& right) { return left.scale(right); }

		bool vec2::operator==(const vec2& other) { return this->x == other.x && this->y == other.y; }
		bool vec2::operator!=(const vec2& other) { return !(*this ==  other); }

		std::ostream& operator << (std::ostream& stream, const vec2& vector) 
		{
			stream << "vec2 (" << vector.x << ", " << vector.y << ")";
			return stream;
		}

	}
}