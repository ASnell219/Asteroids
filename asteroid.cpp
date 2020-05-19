#include "stdafx.h"
#include "asteroid.h"
#include "scene.h"

namespace nce
{
	std::istream & nce::operator>>(std::istream & stream, Asteroid& asteroid)
	{
		stream >> *dynamic_cast<Actor*>(&asteroid);

		stream >> asteroid.m_direction;
		std::string line;
		getline(stream, line);
		asteroid.m_speed = stof(line);
		getline(stream, line);
		asteroid.m_rotate = stof(line);

		return stream;
	}

	void Asteroid::Initialize()
	{
		m_transform.position.x = Math::GetRandomRange(0.0f, 800.0f);
		m_transform.position.y = Math::GetRandomRange(0.0f, 600.0f);

		m_direction = Vector2D::GetRandomUnitCircle();

		m_rotate = Math::GetRandomRange(-80.0f, 80.0f);
		m_speed = Math::GetRandomRange(20.0f, 70.0f);
	}

		void nce::Asteroid::Update(float dt)
	{
			/*Object* ship = m_scene->GetObject("Ship");
			assert(ship != nullptr);
			Vector2D direction = ship->GetTransform().position - m_transform.position;
			m_direction = direction.normalized();*/

			m_transform.position += (m_direction * m_speed) * dt;
			m_transform.rotation += m_rotate * dt;

			if (m_transform.position.x > 825) m_transform.position.x = 0;
			if (m_transform.position.y > 625) m_transform.position.y = 0;
			if (m_transform.position.x < 0) m_transform.position.x = 800;
			if (m_transform.position.y < 0) m_transform.position.y = 600;
	}
}
