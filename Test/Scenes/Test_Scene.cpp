#include "Test_Scene.h"
#include <math.h>
#include <iostream>
#include <random>

void Test_Scene::Init()
{
	ResourceManager::LoadShader("Resources/test.glsl", "voxel");
	ResourceManager::LoadShader("Resources/defaultTest.glsl", "shader");
	
	Assimp::Importer importer;
	std::string path = "Resources/Models/Sponza/sponza.obj";
	LoadModel(path);

	/*for (int i = 0; i < 1; i++)
	{
		for (int x = 0; x < meshes[0].indices.size(); x++)
		{
			std::cout << "indieces: " << meshes[0].indices[x] << std::endl;
		}
	}*/

	
	for (int i = 0; i < meshes.size(); i++)
	{
		auto box = CreateGameOject();
		box->AddComponent(std::make_shared<Transform>(glm::vec3(0, 0, -10), glm::vec3(0, 0, 0), glm::vec3(0.1f, 0.1f, 0.1f)));
		box->AddComponent(std::make_shared<MeshFilter>(meshes[i]));
	}
	//box->GetComponent<MeshFilter>()->SetMesh(mesh);

	auto camera = CreateGameOject();
	camera->AddComponent(std::make_shared<Transform>(glm::vec3(0, 0, -10), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	camera->AddComponent(std::make_shared<Camera>(Camera_Type::PERSPECTIVE, 60.0f, 0.01f, 10000.0f));
	camera->AddComponent(std::make_shared <CameraMoviment>());

	glEnable(GL_MULTISAMPLE);
}


void Test_Scene::Update()
{	

	if (FL::Input::IsKeyDown(FL::KEYCODE::KEY_V))
	{
		
	}
}

void Test_Scene::LoadModel(std::string path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);


	aiNode* node = scene->mRootNode;
	ProcessNode(node, scene);
}

void Test_Scene::ProcessNode(aiNode* node, const aiScene* scene)
{
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		ProcessMesh(mesh, scene);
	}
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		ProcessNode(node->mChildren[i], scene);
	}
}

void Test_Scene::ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
	Mesh nodeMesh;

	//std::cout << "Vertices: " << mesh->mNumVertices << std::endl;

	for(unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		glm::vec3 vertexPos;
		glm::vec3 vertexNormal;

		vertexPos.x = mesh->mVertices[i].x;
		vertexPos.y = mesh->mVertices[i].y;
		vertexPos.z = mesh->mVertices[i].z;

		vertexNormal.x = mesh->mNormals[i].x;
		vertexNormal.y = mesh->mNormals[i].y;
		vertexNormal.z = mesh->mNormals[i].z;

		nodeMesh.vertices.push_back(vertexPos);

		nodeMesh.normals.push_back(vertexNormal);
		
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		if (mesh->mFaces->mNumIndices == 3)
		{
			nodeMesh.indices.push_back(mesh->mFaces[i].mIndices[0]);
			nodeMesh.indices.push_back(mesh->mFaces[i].mIndices[1]);
			nodeMesh.indices.push_back(mesh->mFaces[i].mIndices[2]);
		}

		/*aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			nodeMesh.indices.push_back(face.mIndices[j]);*/
	}


	meshes.push_back(nodeMesh);
}

void Test_Scene::Close()
{

}

void Test_Scene::Debug()
{
}
