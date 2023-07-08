#include "shader.h"
namespace Lucent {
    void Shader::Compile(const char* vertPath, const char* fragPath, const char* geoPath)
    {
        unsigned int sVertex, sFragment;
        // vertex Shader
        sVertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(sVertex, 1, &vertPath, NULL);
        glCompileShader(sVertex);
        checkCompileErrors(sVertex, "VERTEX");
        // fragment Shader
        sFragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(sFragment, 1, &fragPath, NULL);
        glCompileShader(sFragment);
        checkCompileErrors(sFragment, "FRAGMENT");

        this->m_shaderprogram = glCreateProgram();
        glAttachShader(this->m_shaderprogram, sVertex);
        glAttachShader(this->m_shaderprogram, sFragment);

        glLinkProgram(this->m_shaderprogram);
        checkCompileErrors(this->m_shaderprogram, "PROGRAM");

        this->SetUniformBindingPoint("Camera", 0);

        glDeleteShader(sVertex);
        glDeleteShader(sFragment);
    }

    void Shader::Bind() const
    {
        glUseProgram(m_shaderprogram);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
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

    void Shader::SetUniformBindingPoint(const std::string& name, const unsigned int bindingPoint) const {
        glUniformBlockBinding(m_shaderprogram, glGetUniformBlockIndex(m_shaderprogram, name.c_str()), bindingPoint);
    }

    void Shader::checkCompileErrors(unsigned int object, std::string type)
    {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(object, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(object, 1024, NULL, infoLog);
                std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
                    << infoLog << "\n -- --------------------------------------------------- -- "
                    << std::endl;
            }
        }
        else
        {
            glGetProgramiv(object, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(object, 1024, NULL, infoLog);
                std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
                    << infoLog << "\n -- --------------------------------------------------- -- "
                    << std::endl;
            }
        }
    }

}