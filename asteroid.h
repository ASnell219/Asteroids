#pragma once
#include "actor.h"

namespace nce
{
	class Asteroid : public Actor
	{
	public:
		Asteroid() {}
		virtual ~ Asteroid() {}

		void Initialize();
		void Update(float dt);

		friend std::istream& operator >> (std::istream& stream, Asteroid& asteroid);


	protected:
		Vector2D m_direction;
		float m_speed;
		float m_rotate;

	};

}
