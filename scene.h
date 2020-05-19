#pragma once
#include <list>
#include "object.h"
#include "core.h"
#include <vector>

#undef GetObject

namespace nce
{
	class Scene
	{
	public:
		Scene() {}
		~Scene() {}

		void Update(float dt);
		void Draw(Core::Graphics& graphics);

		void AddObject(Object* object);
		std::list<Object*>::iterator RemoveObject(Object * object);

		Object* GetObject(const std::string& name);

		template <typename T>
		std::vector<T*> GetObjects()
		{
			std::vector<T*> objects;
			for (Object* object : m_objects)
			{
				T* objectType = dynamic_cast<T*>(object);
				if (objectType)
				{
					objects.push_back(objectType);
				}
			}

			return objects;
		}

		size_t Size() { return m_objects.size(); }

	private:
		std::list<Object*> m_objects;
	};


}