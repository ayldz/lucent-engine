#include "resources.h"

#include <iostream>
#include <sstream>
#include <fstream>

#include "stb_image.h"

std::map<std::string, Texture> Resources::m_textures;
std::map<std::string, Shader> Resources::m_shaders;

Shader Resources::LoadShader(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath, std::string name)
{
	m_shaders[name] = LoadShaderFromFile(vertexShaderPath, fragmentShaderPath, geometryShaderPath);
	return m_shaders[name];
}

Shader Resources::GetShader(std::string name)
{
	return m_shaders[name];
}

Texture Resources::LoadTexture(const char* filePath, bool alpha, std::string name)
{
	m_textures[name] = LoadTextureFromFile(filePath, alpha);
	return m_textures[name];
}

Texture Resources::GetTexture(std::string name)
{
	return m_textures[name];
}

Shader Resources::LoadShaderFromFile(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath = nullptr)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    try
    {
        // open files
        std::ifstream vertexShaderFile(vertexShaderPath);
        std::ifstream fragmentShaderFile(fragmentShaderPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();
        // close file handlers
        vertexShaderFile.close();
        fragmentShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
        // if geometry shader path is present, also load a geometry shader
        if (geometryShaderPath != nullptr)
        {
            std::ifstream geometryShaderFile(geometryShaderPath);
            std::stringstream gShaderStream;
            gShaderStream << geometryShaderFile.rdbuf();
            geometryShaderFile.close();
            geometryCode = gShaderStream.str();
        }
    }
    catch (std::exception e)
    {
        std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    const char* gShaderCode = geometryCode.c_str();
    // 2. now create shader object from source code
    Shader shader;
    shader.Compile(vShaderCode, fShaderCode, geometryShaderPath != nullptr ? gShaderCode : nullptr);
    return shader;
}

Texture Resources::LoadTextureFromFile(const char* filePath, bool alpha)
{
    // create texture object
    Texture texture;
    if (alpha) //TODO alpha kontorlü yap.
    {
        texture.internalFormat = GL_RGBA;
        texture.imageFormat = GL_RGBA;
    }

    // load image
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filePath, &width, &height, &nrChannels, 0);

    // now generate texture
    texture.Generate(width, height, data);
    // and finally free image data
    stbi_image_free(data);
    return texture;
}

void Resources::Clear()
{
    for (auto iter : m_shaders)
        iter.second.Clear();
	//for (auto iter : m_textures);
	//glDeleteTextures(1, &iter.second.ID);
}