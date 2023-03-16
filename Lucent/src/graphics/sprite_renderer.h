#pragma once

#include "sprite.h"

#include "glad/glad.h"

class SpriteRenderer 
{
private: 
	Sprite m_sprite{};

	unsigned int vbo;
	unsigned int vao;
	unsigned int ebo;

public:

	SpriteRenderer(const Sprite&);

	void Prepare();

	void Render();

	void Clean();
};