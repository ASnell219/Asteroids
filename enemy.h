#pragma once
#include "actor.h"

namespace nce
{
	class Enemy : public Actor
	{
	public:
		Enemy() {}
		virtual ~Enemy() {}

		void Initialize();
		void Update(float dt);

		friend std::istream& operator >> (std::istream& stream, Enemy& enemy);


	protected:
		Vector2D m_direction;
		float m_speed;
		float m_rotate;

	};

}
