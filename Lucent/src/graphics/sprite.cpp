#include "sprite.h"

Sprite::Sprite()
{
	vertices = {
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f 
	};

	triangles =
	{
		0, 1, 3,  
		1, 2, 3   
	};
}

Sprite::Sprite(const std::vector<float>&, const std::vector<float>&)
{
}

Sprite::~Sprite()
{
}
