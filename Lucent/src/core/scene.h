#pragma once

#include <vector>

#include "../graphics/sprite.h"
#include "sprite_renderer.h"

#include "entity.h"

class Scene 
{
private:
	SpriteRenderer* m_renderer;

public:
	Scene();
	~Scene();
	void Update(double dt) const;
};