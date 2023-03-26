#pragma once

#include "sprite.h"
#include "shader.h"
#include "texture.h"

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
	Sprite m_sprite{};

	unsigned int m_vbo{};
	unsigned int m_vao{};
	unsigned int m_ebo{};

	Shader shader{};

public:

	SpriteRenderer(const Sprite&);

	void Prepare();

	void Render();

	void Clean();
};