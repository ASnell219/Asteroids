#include "stdafx.h"
#include "player.h"
#include "transform.h"
#include "core.h"
#include "graphics.h"
#include "scene.h"
#include "asteroid.h"
#include "projectile.h"

using namespace nce;



void nce::Player::Initialize()
{
	m_fireRate = 0.75f;
	m_fireTimer = 0.0f;
}

void nce::Player::Update(float dt)
{
	m_shapes[0]->SetColor(Color::white);

	std::vector<Asteroid*> asteroids = m_scene->GetObjects<Asteroid>();
	for (Asteroid* asteroid : asteroids)
	{
		if ((asteroid->GetTransform().position - m_transform.position).length() <= 40.0f)
		{
			m_shapes[0]->SetColor(Color::red);
		}
	}

	m_fireTimer = m_fireTimer - dt;
	if (m_fireTimer <= 0)
	{
		if (Core::Input::IsPressed(Core::Input::BUTTON_LEFT) || Core::Input::IsPressed(VK_SPACE))
		{
			m_fireTimer = m_fireRate;
			Projectile* projectile = new Projectile;

			std::fstream stream("resources\\photon.act");
			assert(stream.good());
			stream >> *projectile;
			stream.close();
			projectile->Initialize();
			projectile->SetScene(m_scene);
			Vector2D direction = Vector2D::Rotate(Vector2D::up, m_transform.rotation * Math::DegreesToRadians);
			projectile->Fire(m_transform.position, direction);

			m_scene->AddObject(projectile);
		}
	}

	if (Core::Input::IsPressed(Core::Input::KEY_LEFT) || Core::Input::IsPressed('A'))
	{
		m_transform.rotation = m_transform.rotation - m_rotate * dt;
	}

	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT) || Core::Input::IsPressed('D'))
	{
		m_transform.rotation = m_transform.rotation + m_rotate * dt;
	}

	Vector2D force = Vector2D::zero;
	if (Core::Input::IsPressed(Core::Input::KEY_UP) || Core::Input::IsPressed('W'))
	{
		Vector2D direction = Vector2D::Rotate(Vector2D::up, m_transform.rotation * Math::DegreesToRadians);
		m_transform.position = m_transform.position + (direction * m_speed) * dt;
		force = (direction * m_speed);
	}

	if (Core::Input::IsPressed(Core::Input::KEY_DOWN) || Core::Input::IsPressed('S'))
	{
		Vector2D direction = Vector2D::Rotate(Vector2D::down, m_transform.rotation * Math::DegreesToRadians);
		m_transform.position = m_transform.position + (direction * m_speed) * dt;
		force = (direction * m_speed);
	}

	m_velocity += force * dt;
	m_transform.position += m_velocity * dt;
	m_velocity *= 0.99f;

	if (m_transform.position.x > 825) m_transform.position.x = 0;
	if (m_transform.position.y > 625) m_transform.position.y = 0;
	if (m_transform.position.x < 0) m_transform.position.x = 800;
	if (m_transform.position.y < 0) m_transform.position.y = 600;
}

std::istream & nce::operator>>(std::istream & stream, Player& player)
{
	stream >> *dynamic_cast<Actor*>(&player);

	stream >> player.m_velocity;
	std::string line;
	getline(stream, line);
	player.m_speed = stof(line);
	getline(stream, line);
	player.m_rotate = stof(line);

	return stream;
}
