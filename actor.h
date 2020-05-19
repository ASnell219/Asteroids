#pragma once
#include "object.h"
#include "shape.h"
#include <vector>

namespace nce
{
	class Actor : public Object
	{
	public:
		Actor() {}
		virtual ~Actor();

		virtual void Update(float dt);
		virtual void LateUpdate(float dt);
		virtual void Draw(Core::Graphics& graphics);
		virtual void Initialize();

		friend std::istream& operator >> (std::istream& stream, Actor& actor);

	protected:
		std::vector<Shape*> m_shapes;

	};

}
