#pragma once

#include <glad/glad.h>

class Texture
{
public:
	unsigned int m_texture;

	unsigned int width, height;

	unsigned int internalFormat;
	unsigned int imageFormat;

	unsigned int wrapS;
	unsigned int wrapT;
	unsigned int filterMin;
	unsigned int filterMax;

	Texture();
	~Texture() = default;

	void Generate(unsigned int width, unsigned int height, unsigned char* data);
	void Bind() const;
};

