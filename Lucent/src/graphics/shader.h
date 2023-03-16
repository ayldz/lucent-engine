#pragma once

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
	Shader();
	~Shader();

	void Bind() const;
	void Unbind() const;

private:
	const std::string& GetVertexShaderSource() const { return m_vertexshadersrc; }
	const std::string& GetVertexFragmentSource() const { return m_fragmentshadersrc; }
};