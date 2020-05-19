#pragma once
#include "actor.h"

namespace nce
{
	class Projectile : public Actor
	{
	public:
		Projectile(){}
		virtual ~Projectile(){}

		void Initialize();
		void Update(float dt);

		void Fire(const Vector2D& position, const Vector2D& direction);

		friend std::istream& operator >> (std::istream& stream, Projectile& projectile);


	protected:
		Vector2D m_direction;
		float m_speed;
		float m_lifetime;
	};

}