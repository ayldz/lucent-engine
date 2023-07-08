#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
namespace Lucent {
	class Shader
	{
	private:
		unsigned int m_shaderprogram;

	public:
		Shader() = default;
		~Shader() = default;

		void Compile(const char* vertPath, const char* fragPath, const char* geoPath);
		void Bind() const;
		void Unbind() const;

		void SetInt(const std::string& name, int value) const;
		void SetFloat(const std::string& name, float value) const;
		void SetFloat2(const std::string& name, const glm::vec2& value) const;
		void SetFloat3(const std::string& name, const glm::vec3& value) const;
		void SetFloat4(const std::string& name, const glm::vec4& value) const;
		void SetMat4(const std::string& name, const glm::mat4& matrix) const;
		void SetUniformBindingPoint(const std::string& name, const unsigned int bindingPoint) const;

		inline unsigned int GetID() const { return m_shaderprogram; }
		inline void Clear() { glDeleteProgram(m_shaderprogram); }
	private:
		void checkCompileErrors(unsigned int object, std::string type);
	};
}