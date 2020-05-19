#pragma once
#include "transform.h"
#include <string>
#include <iostream>
#include "core.h"


namespace nce
{
	class Scene; 

	class Object
	{
	public:
		Object() : m_scene(nullptr), m_destroy(false) {}
		virtual ~Object() {}

		virtual void Update(float dt) = 0;
		virtual void LateUpdate(float dt) = 0;
		virtual void Draw(Core::Graphics& graphics) = 0;
		virtual void Initialize() = 0;

		const std::string& GetName() { return m_name; }
		Transform& GetTransform() { return m_transform; }
		void SetScene(Scene* scene) { m_scene = scene; }

		friend bool operator == (const Object& object, const std::string& name)
		{
			return (_strnicmp(object.m_name.c_str(), name.c_str(), name.size()) == 0);
		}

		friend std::istream& operator>> (std::istream& stream, Object& object)
		{
			std::getline(stream, object.m_name);
			stream >> object.m_transform;
			return stream;
		}

		friend Scene;

	protected:
		std::string m_name;
		Transform m_transform;
		bool m_destroy;
		Scene* m_scene;
	};
}
