#include "shader.h"

Shader::~Shader()
{
	glDeleteProgram(m_shaderprogram);
}

void Shader::Prepare()
{
	m_vertexshader = glCreateShader(GL_VERTEX_SHADER);
	const char* vs = GetVertexShaderSource().c_str();
	glShaderSource(m_vertexshader, 1, &vs , nullptr);
	glCompileShader(m_vertexshader);

	m_fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fs = GetFragmentShaderSource().c_str();
	glShaderSource(m_fragmentshader,1, &fs, nullptr);
	glCompileShader(m_fragmentshader);

	m_shaderprogram = glCreateProgram();
	glAttachShader(m_shaderprogram, m_vertexshader);
	glAttachShader(m_shaderprogram, m_fragmentshader);
	glLinkProgram(m_shaderprogram);

	glDeleteShader(m_vertexshader);
	glDeleteShader(m_fragmentshader);
}

void Shader::Bind() const
{
	glUseProgram(m_shaderprogram);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}

const std::string& Shader::GetVertexShaderSource()
{
	m_vertexshadersrc = ""
		"#version 300 es\n"
		"layout(location = 0) in vec3 aPos;\n"

		"void main()\n"
		"{\n"
		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\n";

	return m_vertexshadersrc;
}


const std::string& Shader::GetFragmentShaderSource()
{
	m_fragmentshadersrc = ""
		"#version 300 es\n"
		"out vec4 FragColor;\n"

		"void main()\n"
		"{\n"
		"FragColor = vec4(1.0f, 0.2f, 8.0f, 1.0f);\n"
		"}\n";

	return m_fragmentshadersrc;
}
