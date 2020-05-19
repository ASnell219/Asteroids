#pragma once
#include "vector2D.h"

namespace nce
{
	class Matrix22
	{
	public:
		float m[2][2]; //column / row

	public:
		Matrix22() {}
		~Matrix22() {}

		void SetIdentity()
		{
			m[0][0] = 1.0f; m[1][0] = 0.0f;
			m[0][1] = 0.0f; m[1][1] = 1.0f;
 		}

		void Scale(float s)
		{
			m[0][0] = s; m[1][0] = 0.0f;
			m[0][1] = 0.0f; m[1][1] = s;
		}

		void Scale(const Vector2D& s)
		{
			m[0][0] = s.x; m[1][0] = 0.0f;
			m[0][1] = 0.0f; m[1][1] = s.y;
		}

		void Rotate(float angle)
		{
			m[0][0] = cos(angle); m[1][0] = sin(angle);
			m[0][1] = -sin(angle); m[1][1] = cos(angle);
		}

		Matrix22 operator * (const Matrix22& mx)
		{
			Matrix22 result;

			result.m[0][0] = m[0][0] * mx.m[0][0] + m[1][0] * mx.m[0][1];
			result.m[0][1] = m[0][1] * mx.m[0][0] + m[1][1] * mx.m[0][1];
			result.m[1][0] = m[0][0] * mx.m[1][0] + m[1][0] * mx.m[1][1];
			result.m[1][1] = m[0][1] * mx.m[1][0] + m[1][1] * mx.m[1][1];

			return result;
		}

		friend Vector2D operator * (const Vector2D& v, const Matrix22& mx)
		{
			Vector2D result;

			result.x = v.x * mx.m[0][0] + v.y * mx.m[0][1];
			result.y = v.x * mx.m[1][0] + v.y * mx.m[1][1];

			return result;
		}
	};
}