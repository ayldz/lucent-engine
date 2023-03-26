#pragma once

#include <vector>

#include "shader.h"
#include "texture.h"

class Sprite
{
private:
	std::vector<float> vertices;
	std::vector<int> triangles;

public:
	Sprite();
	Sprite(const std::vector<float>&, const std::vector<float>&);
	virtual ~Sprite();

	//void Render() const;

	inline const std::vector<float>& GetVertices() const { return vertices; };
	inline const std::vector<int>& GetTriangles() const { return triangles; };

};