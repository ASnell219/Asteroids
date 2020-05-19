#pragma once
#include "vector2D.h"
#include "matrix33.h"

namespace nce 
{
	class Transform
	{
	public:
		nce::Vector2D position;
		float scale;
		float rotation;

		Matrix33 matrix;

	public:
		Transform() {}
		Transform(nce::Vector2D position, float scale, float rotation) : position(position), scale(scale), rotation(rotation) 
		{
		}

		void Update();

		friend std::istream& operator >> (std::istream& stream, Transform& transform);
	};

	
}
