#pragma once

#include "glad/glad.h"

namespace Lucent {
	class UniformBuffer {
	private:
		unsigned int m_id;
	public:
		UniformBuffer(unsigned int size, unsigned int bindingPoint);
		~UniformBuffer();

		void SetData(const void* data, unsigned int offset, unsigned int size);
	};
}