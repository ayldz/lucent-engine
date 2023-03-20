#pragma once

#include "sprite.h"
#include "shader.h"
#include "texture.h"

#include "glad/glad.h"


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