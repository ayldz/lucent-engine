#pragma once

#include <map>
#include <string>

#include <glad/glad.h>

#include "../graphics/texture.h"
#include "../graphics/shader.h"

class Resources 
{
private:
	static std::map<std::string, Texture> m_textures;
	static std::map<std::string, Shader> m_shaders;

public:
	static Shader LoadShader(const char *vertexShaderPath, const char *fragmentShaderPath, const char *geometryShaderPath, std::string name);
	static Shader GetShader(std::string name);

	static Texture LoadTexture(const char *filePath, bool alpha, std::string name);
	static Texture GetTexture(std::string name);

	static void Clear();

private:
	Resources() = default;

	static Shader LoadShaderFromFile(const char *vertexShaderPath, const char *fragmentShaderPath, const char *geometryShaderPath = nullptr);
	static Texture LoadTextureFromFile(const char* filePath, bool alpha);
};