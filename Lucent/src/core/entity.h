#pragma once

#include <vector>
#include <string>

#include "component.h"
#include "camera.h"

class Component;

class Entity 
{
private:
	bool active{};
	int id{};

	std::vector <std::reference_wrapper<Component>> m_components;

public:
	std::string name;

	Entity()
	{

	}

	void AddExistingComponent(Component& c);

	template<typename T>
	T& AddComponent(std::string name = " ");


	template <typename T>
	void RemoveComponent();

	template <typename T>
	T& GetComponent();

	template <typename T>
	bool HasComponent();

	void PrintAllComponents();

	void Start();
	void Update(float);
	void Render(Camera& camera);

	inline bool IsActive() const { return active; };
};

template<typename T>
inline void Entity::RemoveComponent()
{
	for (size_t i = 0; i < m_components.size(); i++)
	{
		if (typeid(T) == typeid(m_components[i].get()))
		{
			m_components.erase(m_components.begin() + i);
		}
	}
}

template<typename T>
inline bool Entity::HasComponent()
{
	for (size_t i = 0; i < m_components.size(); i++)
	{
		if (typeid(T) == typeid(m_components[i].get()))
		{
			return true;
		}
	}
	return false;
}

template<typename T>
inline T& Entity::GetComponent()
{
	for (size_t i = 0; i < m_components.size(); i++)
	{
		if (typeid(T) == typeid(m_components[i].get()))
		{
			return dynamic_cast<T&>(m_components[i].get());
		}
	}
}

template<typename T>
T& Entity::AddComponent(std::string name) {
	T* component = new T(name);
	this->AddExistingComponent(*component);
	return *component;
}