#pragma once
#include <cassert>
#include "vector2D.h"

namespace nce
{
	class Vector3D
	{
	public:
		float x, y, z;

		Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Vector3D& operator = (const Vector3D & v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;

			return *this;
		}

		float& operator [] (size_t index)
		{
			assert(index < 3 || index > -1);
			if (index == 0)
				return x;

			if (index == 1)
				return y;

			if (index == 3)
				return z;
		}

		const float& operator [] (size_t index) const
		{
			assert(index < 3 || index > -1);
			if (index == 0)
				return x;

			if (index == 1)
				return y;

			if (index == 2)
				return z;
		}

		bool operator == (const Vector3D & v) const { return ((x == v.x) && (y == v.y) && (y == v.z)); }
		bool operator != (const Vector3D & v) const { return ((x != v.x) || (y != v.y) || (y != v.y)); }
		//bool operator <  (const Vector3D & v) const { return (x < v.x) || ((x == v.x) && (y < v.y)); }
		//bool operator >  (const Vector3D & v) const { return (x > v.x) || ((x == v.x) && (y > v.y)); }

		Vector3D& operator += (const Vector3D & v) { x += v.x; y += v.y; z += v.z; return *this; }
		Vector3D& operator -= (const Vector3D & v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
		Vector3D& operator *= (const Vector3D & v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
		Vector3D& operator /= (const Vector3D & v) { x /= v.x; y /= v.y; z /= v.z; return *this; }

		const Vector3D operator + (const Vector3D & v) const { Vector3D r(*this); return r += v; }
		const Vector3D operator - (const Vector3D & v) const { Vector3D r(*this); return r -= v; }
		const Vector3D operator * (const Vector3D & v) const { Vector3D r(*this); return r *= v; }
		const Vector3D operator / (const Vector3D & v) const { Vector3D r(*this); return r /= v; }

		Vector3D & operator += (float s) { x += s; y += s; z += s; return *this; }
		Vector3D & operator -= (float s) { x -= s; y -= s; z -= s; return *this; }
		Vector3D & operator *= (float s) { x *= s; y *= s; z *= s; return *this; }
		Vector3D & operator /= (float s) { x /= s; y /= s; z /= s; return *this; }

		const Vector3D operator + (float s) const { Vector3D r(*this); return r += s; }
		const Vector3D operator - (float s) const { Vector3D r(*this); return r -= s; }
		const Vector3D operator * (float s) const { Vector3D r(*this); return r *= s; }
		const Vector3D operator / (float s) const { Vector3D r(*this); return r /= s; }

		Vector3D operator - (void) { return Vector3D(-x, -y, -z); }

		operator Vector2D() const
		{
			return (Vector2D(x, y));
		}

		static const Vector3D zero;
		static const Vector3D one;
		static const Vector3D up;
		static const Vector3D down;
		static const Vector3D left;
		static const Vector3D right;

		float lengthSquared() const
		{
			return ((x * x) + (y * y) + (z * z));
		}

		float length() const
		{
			return sqrt(lengthSquared());
		}

		const Vector3D & normalize()
		{
			float len = length();
			if (len < FLT_EPSILON)
			{
				x = 0;
				y = 0;
				z = 0;
				return *this;
			}
			else
			{
				*this / len;
				return *this;
			}
			
		}

		Vector3D normalized() const
		{
			Vector3D newVect;
			newVect.x = x / length();
			newVect.y = y / length();
			newVect.z = z / length();
			return newVect;
		}

		friend std::ostream & operator << (std::ostream & os, const Vector3D & v)
		{
			return os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
		}
		//friend std::istream & operator >> (std::istream & is, Vector3D & v);


		inline static float lengthSquared(const Vector3D & v1, const Vector3D & v2)
		{
			return (((v1.x - v2.x) * (v1.x - v2.x)) + ((v1.y - v2.y) * (v1.y - v2.y)) + ((v1.z - v2.z) * (v1.z - v2.z)));
		}

		inline  static float length(const Vector3D & v1, const Vector3D & v2)
		{
			return sqrt(lengthSquared(v1, v2));
		}

		inline static float Dot(const Vector3D & v1, const Vector3D & v2) { return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z); }

		inline static const Vector3D Min(const Vector3D & v1, const Vector3D & v2)
		{
			return Vector3D(v1.x < v2.x ? v1.x : v2.x, v1.y < v2.y ? v1.y : v2.y, v1.z < v2.z ? v1.z : v2.z);
		}
		inline static const Vector3D Max(const Vector3D & v1, const Vector3D & v2)
		{
			return Vector3D(v1.x > v2.x ? v1.x : v2.x, v1.y > v2.y ? v1.y : v2.y, v1.z > v2.z ? v1.z : v2.z);
		}
	};
	
}

//seeing & generally means returning *this;