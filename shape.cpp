#include "stdafx.h"
#include "shape.h"
#include "math.h"
#include <fstream>
#include "color.h"
#include "matrix22.h"
#include "matrix33.h"

Shape::Shape(nce::Vector2D * points, size_t numPoints, Color color)
{
	assert(numPoints % 2 == 0);
	m_numPoints = numPoints;
	m_pointsLocal = points;
	m_pointsWorld = new Vector2D[numPoints];

	m_color = color;
}

void Shape::Draw(Core::Graphics & graphics)
{
	graphics.SetColor(m_color);
	graphics.DrawLines(m_numPoints / 2, reinterpret_cast<float*>(m_pointsWorld));
}

void Shape::Transform(nce::Vector2D position, float scale, float angle)
{
	for (int i = 0; i < m_numPoints; i++)
	{
		Vector2D v = m_pointsLocal[i];
		v = v * scale;
		v = Vector2D::Rotate(v, angle * Math::DegreesToRadians);
		v = v + position;
		m_pointsWorld[i] = v;
	}
}

void Shape::Transform(const nce::Transform & transform)
{
	Matrix33 mx1;
	mx1.Scale(transform.scale);

	Matrix33 mx2;
	mx2.Rotate(transform.rotation * Math::DegreesToRadians);

	Matrix33 mx3;
	mx3.Translate(transform.position);

	Matrix33 mx = mx1 * mx2 * mx3;

	for (size_t i = 0; i < m_numPoints; i++)
	{
		Vector2D v = m_pointsLocal[i];

		v = v * mx;

		m_pointsWorld[i] = v;
	}
	
}

void Shape::Transform(const nce::Matrix33 & matrix)
{
	for (size_t i = 0; i < m_numPoints; i++)
	{
		Vector2D v = m_pointsLocal[i];
		v = v * matrix;
		m_pointsWorld[i] = v;
	}
}

bool Shape::Load(const std::string & filename)
{
	bool success = false;

	std::ifstream stream(filename);
	if (stream.is_open())
	{
		success = true;

		std::string line;
		getline(stream, line);
		m_numPoints = stoi(line);
		m_pointsLocal = new Vector2D[m_numPoints];
		m_pointsWorld = new Vector2D[m_numPoints];
		size_t i = 0;

		bool colorChanged = false;

		while (!stream.eof())
		{
			if (!colorChanged)
			{
				stream >> m_color;
				colorChanged = true;
			}

			Vector2D v; 
			stream >> v;

			if (!stream.eof())
			{
				m_pointsLocal[i] = v;
				i++;
			}
		}
		assert(i == m_numPoints);

		stream.close();
	}

	return success;
}
