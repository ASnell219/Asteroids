#pragma once
#include <cassert>
#include "math.h"

namespace nce
{
	class Vector2D
	{
	public:
		Vector2D(float x = 0.0f, float y = 0.0f)
		{
			this->x = x;
			this->y = y;
		}
		Vector2D& operator = (const Vector2D & v)
		{
			this->x = v.x;
			this->y = v.y;

			return *this;
		}

		float& operator [] (size_t index)
		{
			assert(index < 2 || index > -1);
			if (index == 0)
				return x;

			if (index == 1)
				return y;
		}

		const float& operator [] (size_t index) const
		{
			assert(index < 2 || index > -1);
			if (index == 0)
				return x;

			if (index == 1)
				return y;
		}

		bool operator == (const Vector2D & v) const { return ((x == v.x) && (y == v.y)); }
		bool operator != (const Vector2D & v) const { return ((x != v.x) || (y != v.y)); }
		bool operator <  (const Vector2D & v) const { return (x < v.x) || ((x == v.x) && (y < v.y)); }
		bool operator >  (const Vector2D & v) const { return (x > v.x) || ((x == v.x) && (y > v.y)); }

		Vector2D& operator += (const Vector2D & v) { x += v.x; y += v.y; return *this; }
		Vector2D& operator -= (const Vector2D & v) { x -= v.x; y -= v.y; return *this; }
		Vector2D& operator *= (const Vector2D & v) { x *= v.x; y *= v.y; return *this; }
		Vector2D& operator /= (const Vector2D & v) { x /= v.x; y /= v.y; return *this; }

		const Vector2D operator + (const Vector2D & v) const { Vector2D r(*this); return r += v; }
		const Vector2D operator - (const Vector2D & v) const { Vector2D r(*this); return r -= v; }
		const Vector2D operator * (const Vector2D & v) const { Vector2D r(*this); return r *= v; }
		const Vector2D operator / (const Vector2D & v) const { Vector2D r(*this); return r /= v; }

		Vector2D & operator += (float s) { x += s; y += s; return *this; }
		Vector2D & operator -= (float s) { x -= s; y -= s; return *this; }
		Vector2D & operator *= (float s) { x *= s; y *= s; return *this; }
		Vector2D & operator /= (float s) { x /= s; y /= s; return *this; }

		const Vector2D operator + (float s) const { Vector2D r(*this); return r += s; }
		const Vector2D operator - (float s) const { Vector2D r(*this); return r -= s; }
		const Vector2D operator * (float s) const { Vector2D r(*this); return r *= s; }
		const Vector2D operator / (float s) const { Vector2D r(*this); return r /= s; }

		Vector2D operator - (void) { return Vector2D(-x, -y); }

		static const Vector2D zero;
		static const Vector2D one;
		static const Vector2D up;
		static const Vector2D down;
		static const Vector2D left;
		static const Vector2D right;

		float lengthSquared() const
		{
			return ((x * x) + (y * y));
		}

		float length() const
		{
			return sqrt(lengthSquared());
		}

		inline static Vector2D Rotate(const Vector2D& v1, float angle)
		{
			Vector2D v;
			v.x = v1.x * cos(angle) - v1.y * sin(angle);
			v.y = v1.y * cos(angle) + v1.x * sin(angle);

			return v;
		}

		const Vector2D & normalize()
		{
			float len = length();
			if (len < FLT_EPSILON)
			{
				x = 0;
				y = 0;
				return *this;
			}
			else
			{
				*this / len;
				return *this;
			}
			
		}

		Vector2D normalized() const
		{
			Vector2D newVect;
			newVect.x = x / length();
			newVect.y = y / length();
			return newVect;
		}

		friend std::ostream & operator << (std::ostream & os, const Vector2D & v)
		{
			return os << "{" << v.x << ", " << v.y << "}";
		}
		friend std::istream & operator >> (std::istream & is, Vector2D & v);


		inline static float lengthSquared(const Vector2D & v1, const Vector2D & v2)
		{
			return (((v1.x - v2.x) * (v1.x - v2.x)) + ((v1.y - v2.y) * (v1.y - v2.y)));
		}

		inline  static float length(const Vector2D & v1, const Vector2D & v2)
		{
			return sqrt(lengthSquared(v1, v2));
		}

		inline static float Dot(const Vector2D & v1, const Vector2D & v2) { return (v1.x * v2.x) + (v1.y * v2.y); }

		inline static const Vector2D Min(const Vector2D & v1, const Vector2D & v2)
		{
			return Vector2D(v1.x < v2.x ? v1.x : v2.x, v1.y < v2.y ? v1.y : v2.y);
		}
		inline static const Vector2D Max(const Vector2D & v1, const Vector2D & v2)
		{
			return Vector2D(v1.x > v2.x ? v1.x : v2.x, v1.y > v2.y ? v1.y : v2.y);
		}

		inline static float GetAngle(const Vector2D&  v)
		{
			return atan2(v.y, v.x);
		}

		inline static Vector2D GetRandomUnitCircle()
		{
			return Rotate(Vector2D::up, Math::GetRandomRange(0.0f, Math::TwoPI));

		}

		float x, y;
	};
	
}

//seeing & generally means returning *this;