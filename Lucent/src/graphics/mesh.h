#pragma once

#include <vector>
#include <glm/glm.hpp>

namespace Lucent {
	typedef unsigned int VertexIndex;

	struct Vertex {
		glm::vec3 Position;
		glm::vec2 TexCoord = glm::vec2(0.0f);
		glm::vec3 Normal = glm::vec3(0.0f);
		glm::vec4 Color = glm::vec4(0.0f);

		Vertex(glm::vec3 p, glm::vec2 t, glm::vec3 n, glm::vec4 c)
		{
			Position = p; TexCoord = t; Normal = n;  Color = c;
		}

		Vertex(glm::vec3 p, glm::vec2 t)
		{
			Position = p; TexCoord = t;
		}

		Vertex(float x, float y, float z)
		{
			Position = glm::vec3(x, y, z);
		}
	};

	struct Mesh {
		std::vector<Vertex> vertices;
		std::vector<VertexIndex> indices;

		static Mesh QuadMesh;
	};
}