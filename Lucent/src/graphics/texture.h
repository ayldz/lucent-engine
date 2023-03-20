#pragma once

#include <string>
#include <glad/glad.h>
#include "stb_image.h"

class Texture
{
private:
	unsigned int m_texture{};
	unsigned char* m_data;

public:
	Texture(std::string path);
	~Texture() = default;

	void Bind();
};

