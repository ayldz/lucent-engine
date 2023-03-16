#include "sprite.h"

Sprite::Sprite()
{
	vertices = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};
}

Sprite::Sprite(const std::vector<float>&, const std::vector<float>&)
{
}

Sprite::~Sprite()
{
}
