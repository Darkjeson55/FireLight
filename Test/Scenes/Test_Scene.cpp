#include "Test_Scene.h"
#include <math.h>
#include <GLFW\glfw3.h>
#include <iostream>
using namespace std;


Test_Scene::Test_Scene()
{

}




void Test_Scene::Init()
{
	auto player = CreateGameOject();
	player.lock()->AddComponent(std::make_shared<Sprite>());




}

void Test_Scene::Update()
{

}

void Test_Scene::Close()
{

}

void Test_Scene::Debug()
{

}


Test_Scene::~Test_Scene()
{

}
