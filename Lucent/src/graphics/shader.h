#pragma once

#include <glad/glad.h>
#include <string>

class Shader
{
private:
	unsigned int m_vertexshader;
	unsigned int m_fragmentshader;
	unsigned int m_shaderprogram;

	std::string m_vertexshadersrc;
	std::string m_fragmentshadersrc;

public:
	Shader() = default;
	~Shader();

	void Prepare();
	void Bind() const;
	void Unbind() const;

	inline unsigned int GetID() const { return m_shaderprogram; }

private:
	const std::string& GetVertexShaderSource();
	const std::string& GetFragmentShaderSource();
};