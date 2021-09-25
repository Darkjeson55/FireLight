#include "MeshFilter.h"
#include "../RenderSystem.h"

MeshFilter::MeshFilter()
{
	m_vao = std::make_shared<FL::VertexArray>();
	m_vbo_vertices = std::make_shared<FL::VertexBuffer>();
	m_vbo_uv = std::make_shared<FL::VertexBuffer>();
	m_vbo_normals = std::make_shared<FL::VertexBuffer>();
	m_ibo = std::make_shared<FL::IndexBuffer>();
	m_shader = ResourceManager::LoadShader("Resources/defaultTest.glsl", "ShaderTest");

	CalculateBuffer();
}

MeshFilter::MeshFilter(Mesh mesh)
{
	m_mesh = mesh;
	m_vao = std::make_shared<FL::VertexArray>();
	m_vbo_vertices = std::make_shared<FL::VertexBuffer>();
	m_vbo_uv = std::make_shared<FL::VertexBuffer>();
	m_vbo_normals = std::make_shared<FL::VertexBuffer>();
	m_ibo = std::make_shared<FL::IndexBuffer>();
	m_shader = ResourceManager::LoadShader("Resources/defaultTest.glsl", "ShaderTest");

	MAX_VERTICES = mesh.vertices.size();
	m_max_index = mesh.indices.size();
	CalculateBuffer();
}

void MeshFilter::CalculateBuffer()
{
	FL::BufferLayout layout({
		{FL::DataType::Vec3}
	});

	//GLsizeiptr vertices_size = sizeof(std::vector<glm::vec3>) + (sizeof(glm::vec3) * MAX_VERTICES);
	//GLsizeiptr index_size = sizeof(std::vector<int>) + (sizeof(int) * m_max_index);

	GLsizeiptr vertices_size = m_mesh.vertices.size() * sizeof(glm::vec3);
	GLsizeiptr index_size = m_mesh.indices.size() * sizeof(int);

	m_vbo_vertices->BuilBuffer(vertices_size, nullptr, GL_DYNAMIC_DRAW);
	m_vbo_normals->BuilBuffer(vertices_size, nullptr, GL_DYNAMIC_DRAW);
	m_ibo->BuildBuffer(index_size, nullptr, GL_DYNAMIC_DRAW);


	m_vbo_vertices->SetBufferLayout(layout);
	m_vbo_normals->SetBufferLayout(layout);

	m_vao->AddVertexBuffer(m_vbo_vertices);
	m_vao->AddVertexBuffer(m_vbo_normals);
	m_vao->AddIndexBuffer(m_ibo);

	m_vao->Init();

}

void MeshFilter::UpdateBuffers()
{
	if (m_mesh.vertices.size() == 0)
		return;

	if (currentIndex == m_mesh.indices.size())
		return;

	//GLsizeiptr vertices_size = sizeof(std::vector<glm::vec3>) + (sizeof(glm::vec3) * m_mesh.vertices.size());
	//GLsizeiptr index_size = sizeof(std::vector<int>) + (sizeof(int) * m_mesh.indices.size());

	GLsizeiptr vertices_size = m_mesh.vertices.size() * sizeof(glm::vec3);
	GLsizeiptr index_size = m_mesh.indices.size() * sizeof(int);

	m_vbo_vertices->AddData(vertices_size, m_mesh.vertices);
	m_vbo_normals->AddData(vertices_size, m_mesh.normals);
	m_ibo->AddData(index_size, m_mesh.indices);

	currentIndex = m_mesh.indices.size();
}

void MeshFilter::Init()
{
	//CalculateBuffer();
	//m_shader = ResourceManager::LoadShader("Resources/ShaderTest.glsl", "ShaderTest");
}

void MeshFilter::Update()
{
	UpdateBuffers();
	//RenderSystem::AddMesh(GetOwner(), m_shader);
	RenderSystem::AddMesh(this, GetOwner()->GetComponent<Transform>(), m_shader);

}

void MeshFilter::Debug() 
{
	
}

void MeshFilter::SetMesh(Mesh mesh)
{
	m_mesh = mesh;
	//CalculateBuffer();
}

void MeshFilter::SetShader(std::shared_ptr<Shader> shader)
{
	m_shader = shader;
}

void MeshFilter::SetVertices(std::vector<glm::vec3> vertices)
{
	m_mesh.vertices = vertices;
}
	
void MeshFilter::SetIndices(std::vector<int> indices)
{
	m_mesh.indices = indices;
}

void MeshFilter::SetUv(std::vector<glm::vec2> uv)
{
	m_mesh.uv = uv;
}

void MeshFilter::SetNormals(std::vector<glm::vec3> normals)
{
	m_mesh.normals = normals;
}

MeshFilter::~MeshFilter()
{

}

