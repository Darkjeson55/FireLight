#include "Scene.h"
#include <iostream>


Scene::Scene()
{
	isInizialized = false;
	//m_camera = new Camera(glm::vec3(0.0f, 0.0f, -3.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.f, 0.f, projType::ORTHO);
}


void Scene::init_scene()
{

	Init();
	init_objects();
	//m_render_system.set_Camera(m_camera);
	init_render();

	isInizialized = true;
	std::cout << m_graph_objects.size() << std::endl;
}
void Scene::update_scene(double dt)
{
	//m_camera->update();
	//CameraUpdate(m_camera);
	Update(dt);
}

void Scene::render()
{
	m_render_system.Render();
}

void Scene::init_objects()
{
	for (int i = 0; i < m_graph_objects.size(); i++)
	{
		m_graph_objects[i]->init_this();
	}
}

void Scene::init_render()
{
	for (int i = 0; i < m_graph_objects.size(); i++)
	{
		check_renderable_node(m_graph_objects[i]);
	}
	//m_render_system.set_Camera(m_camera);
}

void Scene::check_renderable_node(SceneNode* node)
{
	if (static_cast<const Renderable*>(node) == nullptr)
	{
		for (int i = 0; i < node->get_children_size(); i++)
		{
			check_renderable_node(node->getChildren(i));
		}
	}
	else
	{
		m_render_system.Add((Renderable*)node);
	}
}

void Scene::close_scene()
{
	Close();
}

void Scene::add_object(SceneNode *node)
{
	m_graph_objects.push_back(node);
	if (isInizialized)
	{
		node->init_this();
	}
}

void Scene::remove_object(SceneNode *node)
{

}

SceneNode* Scene::get_object(string name)
{
	return nullptr; //m_root->getChildren(name);
}


Scene::~Scene()
{
}