#include "shader.h"

Shader::~Shader()
{
	glDeleteProgram(m_shaderprogram);
}

void Shader::Prepare(const char* vertPath, const char* fragPath)
{
	m_vertexshadersrc = readShaderFile(vertPath);
	m_fragmentshadersrc = readShaderFile(fragPath);

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
	return m_vertexshadersrc;
}


const std::string& Shader::GetFragmentShaderSource()
{
	return m_fragmentshadersrc;
}

std::string Shader::readShaderFile(const char* path) {
	std::string content;
	std::ifstream file;
	try {
		file.open(path);
		std::stringstream contentStream;
		contentStream << file.rdbuf();
		file.close();
		content = contentStream.str();
		return content;
	}
	catch (std::ifstream::failure e) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		return "";
	}
}

// Uniform Setters
void Shader::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(m_shaderprogram, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(m_shaderprogram, name.c_str()), value);
}

void Shader::SetFloat2(const std::string& name, const glm::vec2& value) const
{
	glUniform2f(glGetUniformLocation(m_shaderprogram, name.c_str()), value.x, value.y);
}

void Shader::SetFloat3(const std::string& name, const glm::vec3& value) const
{
	glUniform3f(glGetUniformLocation(m_shaderprogram, name.c_str()), value.x, value.y, value.z);
}

void Shader::SetFloat4(const std::string& name, const glm::vec4& value) const
{
	glUniform4f(glGetUniformLocation(m_shaderprogram, name.c_str()), value.x, value.y, value.z, value.w);
}

void Shader::SetMat4(const std::string& name, const glm::mat4& matrix) const
{
	glUniformMatrix4fv(glGetUniformLocation(m_shaderprogram, name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
}

