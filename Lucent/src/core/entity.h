#pragma once

#include <vector>
#include <string>

#include "component.h"


class Entity 
{
private:
	bool active{};
	int id{};
	std::string m_name;

	std::vector<const Component&> m_components;

public:
	Entity(std::string);
	
	
	template<typename T>
	const T& GetComponent(const T&);

	template<typename T>
	void RemoveComponent(T);

	template<typename T>
	void AddComponent(const T&);

	std::vector<const Component&> GetAllComponents();

	void Start();
	void Update(float);

	inline bool IsActive() const { return active; };
};


