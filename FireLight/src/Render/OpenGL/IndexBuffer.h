#pragma once

#include <GL/gl3w.h>
#include <vector>

namespace FL
{
	class IndexBuffer
	{
	public:

		IndexBuffer();
		~IndexBuffer();

		void Bind();
		void UnBind();

		template <class T>
		void AddData(GLsizeiptr size, const std::vector<T>& data)
		{
			Bind();
			glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, size, &data[0]);
		}

		void BuildBuffer(GLsizeiptr size, GLbitfield BufferUsage);
		void BuildBuffer(GLsizeiptr size, void* data ,GLbitfield BufferUsage);

	private:
		GLuint m_bufferID;
};
}
