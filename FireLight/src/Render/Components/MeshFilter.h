#pragma once
#include <memory>
#include <limits>

#include "../../Core/Component.h"

//Math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../../Utility/Resources/Shader.h"

//OpenGL
#include "../OpenGL/VertexArray.h"
#include "../OpenGL/VertexBuffer.h"
#include "../OpenGL/IndexBuffer.h"


struct Mesh
{
	std::vector<glm::vec3>	vertices;
	std::vector<glm::vec2>	uv;
	std::vector<glm::vec3>	normals;
	std::vector<int>		indices;
};


class MeshFilter : public Component
{
public:
	MeshFilter();
	MeshFilter(Mesh mesh);
	void Init();
	void Update();
	void Debug();

	void CalculateBuffer();
	
	void UpdateBuffers();

	//Set Mesh
	void SetMesh(Mesh mesh);
	void SetShader(std::shared_ptr<Shader> shader);

	void SetVertices(std::vector<glm::vec3> vertices);
	void SetIndices(std::vector<int> indices);
	void SetUv(std::vector<glm::vec2> uv);
	void SetNormals(std::vector<glm::vec3> normals);

	int GetIndex() { return m_mesh.indices.size(); }
	std::shared_ptr<FL::VertexArray> GetVAO() { return m_vao; }
	std::shared_ptr<FL::IndexBuffer> GetIBO() { return m_ibo; }

	int a = 15;
	
	~MeshFilter();
private:
	
	Mesh m_mesh;
	int MAX_VERTICES = 65000;
	int m_max_index = MAX_VERTICES * 6;
	int currentIndex;

	std::shared_ptr<Shader> m_shader;

	std::shared_ptr<FL::VertexArray> m_vao;
	std::shared_ptr<FL::VertexBuffer> m_vbo_vertices;
	std::shared_ptr<FL::VertexBuffer> m_vbo_uv;
	std::shared_ptr<FL::VertexBuffer> m_vbo_normals;
	std::shared_ptr<FL::IndexBuffer> m_ibo;
};