#pragma once
#include <GL/gl3w.h>
#include <vector>

namespace FL
{
	enum class DataType
	{
		None = 0, Float, Vec2, Vec3, Vec4, Mat3, Mat4, Int
	};

	static uint32_t GetShaderDataTypeSze(DataType type)
	{
		switch (type)
		{
			case FL::DataType::Float: return 4;
			case FL::DataType::Vec2: return 4 * 2;
			case FL::DataType::Vec3: return 4 * 3;
			case FL::DataType::Vec4: return 4 * 4;
			case FL::DataType::Mat3: return 4 * 3 * 3;
			case FL::DataType::Mat4: return 4 * 4 * 4;
			case FL::DataType::Int: return 4;
		}

		return 0;
	}


	struct BufferElement
	{
		BufferElement(DataType type) : 
			Type(type), Size(GetShaderDataTypeSze(type))
		{

		}

		uint32_t GetTypeSyze() const
		{
			switch (Type)
			{
				case FL::DataType::Float:	return 1;
				case FL::DataType::Vec2:	return 2;
				case FL::DataType::Vec3:	return 3;
				case FL::DataType::Vec4:	return 4;
				case FL::DataType::Mat3:	return 3*3;
				case FL::DataType::Mat4:	return 4*4;
				case FL::DataType::Int:		return 1;
			}

			return 0;
		}

		DataType Type;
		uint32_t Offset;
		uint32_t Size;
	};



	class BufferLayout
	{
	public:
		BufferLayout() {}
		BufferLayout(const std::initializer_list<BufferElement>& elements)
		: m_BufferElements(elements)
		{
			CalculateOffsetsAndStride();
		}

		inline const std::vector<BufferElement>& GetElements() const { return m_BufferElements; }

		 inline const uint32_t GetStride() const { return m_Stride; }

		~BufferLayout() {}
	private:
		void CalculateOffsetsAndStride()
		{
			uint32_t offset = 0;
			m_Stride = 0;
			for (auto& element : m_BufferElements)
			{
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}


		std::vector<BufferElement> m_BufferElements;
		uint32_t m_Stride;

	};


	class VertexBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();

		void Bind();
		void UnBind();

		void BuilBuffer(GLsizeiptr size, GLbitfield BufferUsage);
		void BuilBuffer(GLsizeiptr size,void *data, GLbitfield BufferUsage);

		void SetBufferLayout(BufferLayout layout) { m_layout = layout; }

		template <class T>
		void AddData(GLsizeiptr size, const std::vector<T>& data)
		{
			Bind();
			glBufferSubData(GL_ARRAY_BUFFER, 0, size, &data[0]);
		}

		inline const BufferLayout& GetBufferLayout() const { return m_layout; }

	private:
		GLuint m_bufferID;
		BufferLayout m_layout;

	};

}