#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

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

	void Prepare(const char* vertPath, const char* fragPath);
	void Bind() const;
	void Unbind() const;

	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetFloat2(const std::string& name, const glm::vec2& value) const;
	void SetFloat3(const std::string& name, const glm::vec3& value) const;
	void SetFloat4(const std::string& name, const glm::vec4& value) const;
	void SetMat4(const std::string& name, const glm::mat4& matrix) const;

	inline unsigned int GetID() const { return m_shaderprogram; }
private:
	const std::string& GetVertexShaderSource();
	const std::string& GetFragmentShaderSource();
	std::string readShaderFile(const char* path);
};