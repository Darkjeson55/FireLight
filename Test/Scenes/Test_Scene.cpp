#include "Test_Scene.h"
#include <math.h>
#include <iostream>

void Test_Scene::Init()
{
	ResourceManager::LoadShader("Resources/test.glsl", "voxel");
	ResourceManager::LoadShader("Resources/defaultTest.glsl", "shader");


	//auto box = CreateGameOject();
	//box->AddComponent(std::make_shared<Transform>(glm::vec3(0,1,0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	//box->AddComponent(std::make_shared<Box>());

	//auto box2 = CreateGameOject();
	//box2->AddComponent(std::make_shared<Transform>(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(5, 1, 5)));
	//box2->AddComponent(std::make_shared<Box>());

	auto box = CreateGameOject();
	box->AddComponent(std::make_shared<Transform>(glm::vec3(0, 1, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	box->AddComponent(std::make_shared<Chunk>());

	auto camera = CreateGameOject();
	camera->AddComponent(std::make_shared<Transform>(glm::vec3(0, 0, -10), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	camera->AddComponent(std::make_shared<Camera>(Camera_Type::PERSPECTIVE, 60.0f, 0.01f, 10000.0f));
	camera->AddComponent(std::make_shared <TestComponent>());

	//GetResourceManager()->LoadShader("Resources/test.txt", "shader");

	/*Resource::LoadShader("Resources/Shaders/Terrain_shader.vert", "Resources/Shaders/Terrain_shader.frag", NULL, "terrain_shader");
	Resource::LoadShader("Resources/Shaders/3D_default.vert", "Resources/Shaders/3D_default.frag", NULL, "box");
	Resource::LoadTexture("Resources/Texture/Boxes.png", true, "TestBox");


	box->AddComponent(std::make_shared<Transform>(glm::vec3(0, 0, -10), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	box->AddComponent(std::make_shared<Box>());

	auto camera = CreateGameOject();
	camera->AddComponent(std::make_shared<Transform>(glm::vec3(0, 0, -10), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	camera->AddComponent(std::make_shared<Camera>(Camera_Type::PERSPECTIVE, 60.0f, 0.01f, 10000.0f));
	camera->AddComponent(std::make_shared <TestComponent>());*/

	//ResourceManager rsc;
	//rsc.LoadInternalShader("Resources/test.txt", "shader");

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	//glEnable(GL_MULTISAMPLE);

}

void Test_Scene::Update()
{	



	/*if (FL::Window::isKeyDown(KEYCODE::KEY_A))
	{
		auto obj = CreateGameOject();
		obj->AddComponent(std::make_shared<Transform>(glm::vec2(RandomNumber::Range(-50, 50), RandomNumber::Range(-50, 50)), 0.0f, glm::vec2(1, 1)));
		obj->AddComponent(std::make_shared<Sprite>());
		obj->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
		obj->GetComponent<Sprite>()->m_row = glm::vec2(18, 13);
		obj->GetComponent<Sprite>()->m_offset = glm::vec2(0, 0);
		obj->GetComponent<Sprite>()->ZLayer = 1;
	}*/
}

void Test_Scene::Close()
{

}

void Test_Scene::Debug()
{
	ImGui::ShowDemoWindow();
}
