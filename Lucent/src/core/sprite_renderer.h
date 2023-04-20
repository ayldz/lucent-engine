#pragma once

#include "../graphics/shader.h"
#include "../graphics/texture.h"

#include "glad/glad.h"
#include "stb_image.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "camera.h"
#include "component.h"
#include "transform.h"

#include "../utils/resources.h"
#include "../graphics/vertex_array.h"

class SpriteRenderer : public Component
{
public:
	static VertexArray* m_vao;

	Texture texture;
	Shader shader;

	SpriteRenderer(const std::string& n) : Component(n) {}

	void Start() override { Prepare(); }
	void Update(float dt) override { }

	void SetName(const std::string& n);

	void Prepare();

	void Render(Camera& camera) override;

	void SetTexture(Texture t) { texture = t; }
	void SetShader(Shader s) { shader = s; }

	//TODO
	//void Clean();
};