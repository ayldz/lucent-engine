#pragma once

#include "mesh.h"
#include "glad/glad.h"

class VertexBuffer {
private:
	unsigned int m_id;
public:
	VertexBuffer(const Mesh* mesh);

	void Bind() const;
	void Unbind() const;
};

class IndexBuffer {
private:
	unsigned int m_id;
public:
	IndexBuffer(const Mesh* mesh);

	void Bind() const;
	void Unbind() const;
};

class VertexArray {
private:
	unsigned int m_id;
	Mesh* mesh;
	VertexBuffer v_buffer;
	IndexBuffer  i_buffer;

public:
	VertexArray(Mesh* mesh);

	void Bind() const;
	void Unbind() const;

	unsigned int GetIndexCount() const;
	unsigned int GetVertexCount() const;
};