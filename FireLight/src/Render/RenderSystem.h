#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H
//------------------Includes------------------
#include <memory>
#include <vector>
//GLM stuffs
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//OpenGL
#include <GL/gl3w.h>

//Imgui

//Engine Stuff
#include "CameraSystem.h"
#include "../Utility/ResourceManager.h"
#include "../Utility/Resources/Shader.h"

#include "Components/MeshFilter.h"

//new system
#include "OpenGL/IndexBuffer.h"
#include "OpenGL/VertexArray.h"
#include "OpenGL/VertexBuffer.h"

//-------------------------------------------

struct MeshBuffer {
	glm::mat4 model;

	int index = 0;
	std::shared_ptr<Shader> shader;
	std::shared_ptr<FL::VertexArray>  m_vao;
	std::shared_ptr<FL::IndexBuffer>  m_ibo;
};

class RenderSystem
{
public:
	RenderSystem();

	static void Init();
	static void Debug();
	static void Render();

	static void AddMesh(GameObject* obj, std::shared_ptr<Shader> shader);
	static void AddMesh(MeshFilter* mesh, Transform* transform, std::shared_ptr<Shader> shader);
	//static void AddSprite(Sprite sp);

	~RenderSystem();

private:

	
	/*GLuint VBO, VAO;
	GLuint VBO2, EBO;

	std::shared_ptr<FL::VertexArray>  m_vao;
	std::shared_ptr<FL::VertexBuffer> m_vbo;
	std::shared_ptr<FL::VertexBuffer> m_vbo2;
	std::shared_ptr<FL::IndexBuffer>  m_ibo;

	glm::mat4 m_projection;*/

	static std::shared_ptr<FL::VertexArray> m_vao;
	static std::shared_ptr<FL::VertexBuffer> m_vbo_vertices;
	static std::shared_ptr<FL::VertexBuffer> m_vbo_color;
	static std::shared_ptr<FL::IndexBuffer> m_ibo;

	static std::vector<MeshBuffer> m_mesh_buffers;

};

#endif // ! RENDER_SYSTEM_H
