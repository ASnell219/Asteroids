#include "stdafx.h"
#include "actor.h"
#include "transform.h"
#include "shape.h"

namespace nce
{
	Actor::~Actor()
	{
		for (Shape* shape : m_shapes)
		{
			delete shape;
		}
	}

	void Actor::Initialize()
	{

	}

	void Actor::Update(float dt)
	{
	}

	void Actor::LateUpdate(float dt)
	{
		m_transform.Update();
		for (Shape* shape : m_shapes)
		{
			shape->Transform(m_transform.matrix);
		}
	}

	void Actor::Draw(Core::Graphics & graphics)
	{
		for (Shape* shape : m_shapes)
		{
			shape->Draw(graphics);
		}
	}

	std::istream & operator>>(std::istream & stream, Actor & actor)
	{
		stream >> *dynamic_cast<Object*>(&actor);

		std::string line;
		getline(stream, line);

		if (line == "{")
		{
			while (!getline(stream, line).eof())
			{
				if (line == "}") break;

				Shape* shape = new Shape();
				bool success = shape->Load(line);
				assert(success);

				actor.m_shapes.push_back(shape);
				
			}

		}

		return stream;

	}

}