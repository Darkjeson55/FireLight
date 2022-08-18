#include "App.h"
#include <chrono>

FL::App::App()
{
}

void FL::App::Start() 
{

	m_NewWindow = std::make_unique<Window>(m_Width, m_Height, m_Title.c_str());

	glfwInit();

	m_NewWindow->Init();

	if (gl3wInit())
	{
		std::cout << "OpenGL failde to inizialize" << std::endl;
	}

	m_NewWindow->InitIMGUI();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);

	glfwSwapInterval(0);

	MainLoop();
}

void FL::App::FixedUpdate()
{
	SceneManager::UpdateCurrentScene();
	Time::Reset();
	FL::Input::clearKeys();
	FL::Input::clearMouseMuttons();
}

void FL::App::Update()
{
	//TODO:: need implement Update Function to Scene and in the SceneManager
}

void FL::App::UpdateFrameRate()
{
	m_CurrentTime = glfwGetTime();

	m_FrameRate++;

	if (m_CurrentTime - m_OldTime > 1.0)
	{
		m_CurrentFPS = m_FrameRate;
		m_FrameRate = 0;
		m_OldTime = m_CurrentTime;
	}
}

void FL::App::MainLoop()
{
	Init();

	Time::Start();

	m_FrameRate = 0;
	m_OldTime = glfwGetTime();

	while (!m_NewWindow->isClosed())
	{
		Time::Calculate();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		while(Time::GetLag() >= MS_PER_UPDATE)
		{
			FixedUpdate();
		}

		if (m_DEBUG_MODE)
		{
			SceneManager::DebugCurrentScene();
			FL::Log::Draw();
		}

		//TODO:: Need more complex implemetation for debug and monitoring of performance
		//ImGui::Text("FPS: %d", m_CurrentFPS);

		Render();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}

		UpdateFrameRate();

		m_NewWindow->UpdateInput();
		m_NewWindow->Update();
	}
	ShutDown();
}

void FL::App::Render()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	
	SceneManager::DrawCurrentScene();
}

void FL::App::ShutDown()
{
	SceneManager::CloseCurrentScene();
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}


void FL::App::SetWindowDimension(int width, int height)
{
	m_Width = width;
	m_Height = height;
}

void FL::App::SetWindowName(std::string name)
{
	m_Title = name;
}


FL::App::~App()
{

}
