#include "sprite.h"

Sprite::Sprite()
{
	vertices = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left
	};

	triangles =
	{
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};
}

Sprite::Sprite(const std::vector<float>&, const std::vector<float>&)
{
}

Sprite::~Sprite()
{
}
