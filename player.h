#pragma once
#include "actor.h"

namespace nce
{
	class Player : public Actor
	{
	public:
		Player() {}
		virtual ~Player() {}

		void Initialize();
		void Update(float dt);

		friend std::istream& operator >> (std::istream& stream, Player& player);


	protected:
		Vector2D m_velocity;
		float m_speed;
		float m_rotate;
		float m_fireRate;
		float m_fireTimer;

	};

}