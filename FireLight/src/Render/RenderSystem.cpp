#include "RenderSystem.h"


std::vector<MeshBuffer> RenderSystem::m_mesh_buffers;

std::shared_ptr<FL::VertexArray>  RenderSystem::m_vao;
std::shared_ptr<FL::VertexBuffer> RenderSystem::m_vbo_vertices;
std::shared_ptr<FL::VertexBuffer> RenderSystem::m_vbo_color;
std::shared_ptr<FL::IndexBuffer>  RenderSystem::m_ibo;

RenderSystem::RenderSystem()
{
	/*MessageBus::RegisterSystem("REGISTER_MESH", this);
	MessageBus::RegisterSystem("DEREGISTER_MESH", this);*/
}


void RenderSystem::Init()
{
	//ResourceManager::LoadShader("Resources/ShaderTest.glsl", "ShaderTest");

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);
}

void RenderSystem::AddMesh(GameObject* obj, std::shared_ptr<Shader> shader)
{
	MeshBuffer buffer;

	MeshFilter* mesh = obj->GetComponent<MeshFilter>();
	Transform* transform = obj->GetComponent<Transform>();

	buffer.shader = shader;
	buffer.index = mesh->GetIndex();
	buffer.m_vao = mesh->GetVAO();
	buffer.m_ibo = mesh->GetIBO();
	buffer.model = transform->GetMatrix();
	m_mesh_buffers.push_back(buffer);
}

void RenderSystem::AddMesh(MeshFilter* mesh, Transform* transform, std::shared_ptr<Shader> shader)
{
	MeshBuffer buffer;

	buffer.shader = shader;
	buffer.index = mesh->GetIndex();
	buffer.m_vao = mesh->GetVAO();
	buffer.m_ibo = mesh->GetIBO();
	buffer.model = transform->GetMatrix();
	m_mesh_buffers.push_back(buffer);
} 

void RenderSystem::Debug()
{

}

void  RenderSystem::Render()
{

	for (int i = 0; i < m_mesh_buffers.size(); i++)
	{
		auto shader = m_mesh_buffers[i].shader;
		shader->SetMatrix4("projection", CameraSystem::GetCurrentCamera());
		shader->SetMatrix4("model", m_mesh_buffers[i].model);

		shader->Use();
		m_mesh_buffers[i].m_vao->Bind();
		m_mesh_buffers[i].m_ibo->Bind();
		//m_mesh_buffers[i].m_vao->Bind();
		//std::cout << "Render mesh Buffers INDEX: " << m_mesh_buffers[i].index << std::endl;
		glDrawElements(GL_TRIANGLES, m_mesh_buffers[i].index, GL_UNSIGNED_INT, 0);

		m_mesh_buffers[i].m_vao->UnBind();
	}

	m_mesh_buffers.clear();
}

RenderSystem::~RenderSystem()
{

}