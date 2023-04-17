#include "vertex_array.h"
#include <iostream>

// Vertex Buffer
VertexBuffer::VertexBuffer(const Mesh* mesh) {
	glGenBuffers(1, &this->m_id);
	glBindBuffer(GL_ARRAY_BUFFER, this->m_id);
	glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * sizeof(Vertex), &mesh->vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::Bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, this->m_id);
}

void VertexBuffer::Unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Index Buffer
IndexBuffer::IndexBuffer(const Mesh* mesh) {
	glGenBuffers(1, &this->m_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,  mesh->indices.size() * sizeof(VertexIndex), &mesh->indices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::Bind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_id);
}

void IndexBuffer::Unbind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Vertex Array
VertexArray::VertexArray(Mesh* mesh) : mesh(mesh), v_buffer(mesh), i_buffer(mesh) {
	std::cout << "VertexArray Contructor" << std::endl;
	glGenVertexArrays(1, &this->m_id);
	glBindVertexArray(this->m_id);

	v_buffer.Bind();
	i_buffer.Bind();

	// Vertex.Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
	glEnableVertexAttribArray(0);

	// Vertex.TexCoord
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoord));
	glEnableVertexAttribArray(2);

	// Vertex.Normal
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
	glEnableVertexAttribArray(1);

	// Vertex.Color
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
	glEnableVertexAttribArray(3);

	glBindVertexArray(0);
	v_buffer.Unbind();
	i_buffer.Unbind();
};

void VertexArray::Bind() const {
	glBindVertexArray(this->m_id);
}

void VertexArray::Unbind() const {
	glBindVertexArray(0);
}

unsigned int VertexArray::GetIndexCount() const {
	return mesh->indices.size();
}

unsigned int VertexArray::GetVertexCount() const {
	return mesh->vertices.size();
}