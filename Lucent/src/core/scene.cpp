#include "scene.h"

Scene::Scene(const Sprite& sprite, const SpriteRenderer& spriteRenderer) 
	: m_sprite{sprite}, m_spriteRenderer{spriteRenderer}
{
	
	m_spriteRenderer.Prepare();
}

void Scene::Update()
{
	m_spriteRenderer.Render();
}
