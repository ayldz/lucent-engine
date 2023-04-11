#pragma once

#include <string>
#include <glad/glad.h>
#include "stb_image.h"

class Texture
{
private:
	unsigned int m_texture{};

	unsigned int width, height;

	unsigned int internalFormat;
	unsigned int imageFormat;

	unsigned int wrapS;
	unsigned int wrapT;
	unsigned int filterMin;
	unsigned int filterMax;

public:
	Texture(std::string path);
	~Texture() = default;

	void Generate(unsigned int width, unsigned int height, unsigned char* data);
	void Bind();
};

