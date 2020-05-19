#include "stdafx.h"
#include "scene.h"

namespace nce
{
	void Scene::Update(float dt)
	{
		for (Object* object : m_objects)
		{
			object->Update(dt);
		}

		std::list<Object*>::iterator iter = m_objects.begin();
		while (iter != m_objects.end())
		{
			if ((*iter)->m_destroy)
			{
				iter = RemoveObject(*iter);
			}
			else
			{
				iter++;
			}
		}

		for (Object* object : m_objects)
		{
			object->LateUpdate(dt);
		}
	}

	void Scene::Draw(Core::Graphics & graphics)
	{
		for (Object* object : m_objects)
		{
			object->Draw(graphics);
		}
	}

	void Scene::AddObject(Object * object)
	{
		m_objects.push_back(object);
	}

	std::list<Object*>::iterator Scene::RemoveObject(Object * object)
	{
		//m_objects.remove(object);
		std::list<Object*>::iterator iter = std::find(m_objects.begin(), m_objects.end(), object);

		if (iter != m_objects.end())
		{
			delete *iter;
			m_objects.erase(iter);
		}

		return iter;

	}
	Object * Scene::GetObject(const std::string & name)
	{
		Object* result = nullptr;

		for (Object* object : m_objects)
		{
			if(*object == name)
			{
				result = object;
				break;
			}
		}

		return result;
	}
}
