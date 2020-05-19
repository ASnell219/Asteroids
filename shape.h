#pragma once
#include "vector2D.h"
#include "transform.h"
#include "core.h"
#include "color.h"
#include "matrix33.h"

using namespace nce;
class Shape
{
public:
	Shape() : m_pointsWorld(nullptr), m_numPoints(0), m_color(Color::white) {};
	Shape(nce::Vector2D* points, size_t numPoints, Color color = Color::white);
	~Shape()
	{
		delete[] m_pointsWorld;
		delete[] m_pointsLocal;
	}

	void Draw(Core::Graphics& graphics);

	void Transform(nce::Vector2D position, float scale = 1.0f, float angle = 0.0f);
	void Transform(const nce::Transform& transform);
	void Transform(const nce::Matrix33& matrix);

	void SetColor(nce::Color color) { m_color = color; }
	nce::Color GetColor() const { return m_color; }

	bool Load(const std::string& filename);

private:
	nce::Vector2D* m_pointsLocal; // pointer to external points (local)
	nce::Vector2D* m_pointsWorld; // pointer to internal points (world)
	size_t m_numPoints;
	nce::Color m_color;
};


