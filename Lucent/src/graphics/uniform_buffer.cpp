#include "uniform_buffer.h"
namespace Lucent {
	UniformBuffer::UniformBuffer(unsigned int size, unsigned int bindingPoint) {
		glGenBuffers(1, &m_id);
		glBindBuffer(GL_UNIFORM_BUFFER, m_id);
		glBufferData(GL_UNIFORM_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, bindingPoint, m_id);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}

	UniformBuffer::~UniformBuffer() {
		glDeleteBuffers(1, &m_id);
	}

	void UniformBuffer::SetData(const void* data, unsigned int offset, unsigned int size) {
		glBindBuffer(GL_UNIFORM_BUFFER, m_id);
		glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);

	}
}