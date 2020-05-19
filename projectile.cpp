#include "stdafx.h"
#include "projectile.h"
#include "asteroid.h"
#include "scene.h"

std::istream & nce::operator>>(std::istream & stream, Projectile & projectile)
{
	stream >> *dynamic_cast<Actor*>(&projectile);

	std::string line;
	getline(stream, line);
	projectile.m_speed = stof(line);

	return stream;
}

void nce::Projectile::Initialize()
{
	m_lifetime = 3.0f;
}

void nce::Projectile::Update(float dt)
{
	std::vector<Asteroid*> asteroids = m_scene->GetObjects<Asteroid>();
	for (Asteroid* asteroid : asteroids)
	{
		if ((asteroid->GetTransform().position - m_transform.position).length() <= 40.0f)
		{
			m_scene->RemoveObject(asteroid);
			m_destroy = true;
		}
	}

	m_lifetime = m_lifetime - dt;
	if (m_lifetime <= 0.0f)
	{
		m_destroy = true;
	}

	m_transform.position += (m_direction * m_speed * dt);
}

void nce::Projectile::Fire(const Vector2D & position, const Vector2D & direction)
{

	m_transform.position = position;
	m_direction = direction;

}
