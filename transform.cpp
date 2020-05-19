#include "stdafx.h"
#include "transform.h"
#include "math.h"

namespace nce
{
	void Transform::Update()
	{
		Matrix33 mx1;
		mx1.Scale(scale);

		Matrix33 mx2;
		mx2.Rotate(rotation * Math::DegreesToRadians);

		Matrix33 mx3;
		mx3.Translate(position);

		matrix = mx1 * mx2 * mx3;
	}

	std::istream & operator>>(std::istream & stream, Transform& transform)
	{
		stream >> transform.position;

		std::string line;
		std::getline(stream, line);
		transform.rotation = stof(line);
		std::getline(stream, line);
		transform.scale = stof(line);

		return stream;
	}

}