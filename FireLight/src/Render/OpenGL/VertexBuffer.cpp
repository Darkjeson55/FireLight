#include "VertexBuffer.h"
#include <iostream>


namespace FL {

	VertexBuffer::VertexBuffer()
	{
		glGenBuffers(1, &m_bufferID);
	}

	void VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER,m_bufferID);
	}

	void VertexBuffer::BuilBuffer(GLsizeiptr size, GLbitfield BufferUsage)
	{
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, NULL, BufferUsage);
	}

	void VertexBuffer::BuilBuffer(GLsizeiptr size, void *data, GLbitfield BufferUsage)
	{
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, data, BufferUsage);
	}

	void VertexBuffer::UnBind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_bufferID);
	}

}