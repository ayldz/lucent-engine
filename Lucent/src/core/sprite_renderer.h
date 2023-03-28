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

class SpriteRenderer
{
private: 
	unsigned int m_vbo{};
	unsigned int m_vao{};
	unsigned int m_ebo{};

	Shader shader{};

public:

	SpriteRenderer();

	void Prepare();

	void Render();

	void Clean();
};