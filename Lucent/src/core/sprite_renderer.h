#pragma once

#include "../graphics/sprite.h"
#include "../graphics/shader.h"
#include "../graphics/texture.h"

#include "glad/glad.h"
#include "stb_image.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "camera.h"
#include "component.h"
#include "transform.h"

class SpriteRenderer : public Component
{
private: 
	unsigned int m_vbo{};
	unsigned int m_vao{};
	unsigned int m_ebo{};
	Shader shader{};

public:

	SpriteRenderer(const std::string& n)
		: Component(n)
	{
		
	}
	void Start() override { Prepare(); }
	void Update(float dt) override { Render(); }

	void SetName(const std::string& n);

	void Prepare();

	void Render();

	//TODO
	//void Clean();
};