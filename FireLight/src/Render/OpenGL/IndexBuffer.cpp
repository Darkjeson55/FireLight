#include "IndexBuffer.h"


namespace FL
{
	IndexBuffer::IndexBuffer()
	{
		glGenBuffers(1, &m_bufferID);
	}


	void IndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
	}

	void IndexBuffer::UnBind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void IndexBuffer::BuildBuffer(GLsizeiptr size, GLbitfield BufferUsage)
	{
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, NULL, BufferUsage);
	}


	void IndexBuffer::BuildBuffer(GLsizeiptr size, void *data, GLbitfield BufferUsage)
	{
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, BufferUsage);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &m_bufferID);
	}
}