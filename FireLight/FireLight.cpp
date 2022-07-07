#include "FireLight.h"

GLFWwindow* window;

int Input::m_keys[1024];
int Input::m_press_keys[1024];
int Input::m_mouse_button[32];
int Input::m_press_mouse_button[32];

void InitWindow(const int& width, const int& height, std::string name)
{
	if (!glfwInit())
		return;

	window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

	if (window == NULL)
		return;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    Input::Init();

    glfwSetKeyCallback(window, Input::key_callback);
    glfwSetMouseButtonCallback(window, Input::mouse_button_callback);

    GLenum err = glewInit();

    if (err != GLEW_OK)
    {
        std::cout << "Error with OpenGL!" << std::endl;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

bool SetUpFrame()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
	return !glfwWindowShouldClose(window);
}

void UpdateWindow()
{
    Input::Init();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void CloseWindow()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
}


//INPUT SYSTEM

bool Input::IsKeyUp(int keycode)
{
    bool currentState = false;
    if (m_keys[keycode] == GLFW_RELEASE)
    {
        currentState = true;
    }
    return currentState;
}

bool Input::IsKeyDown(int keycode)
{
    bool currentState = false;
    if (m_keys[keycode] == GLFW_PRESS)
    {
        currentState = true;
    }
    return currentState;
}

bool Input::IsKeyPress(int keycode)
{
	return m_press_keys[keycode] == GLFW_REPEAT || m_press_keys[keycode] == GLFW_PRESS;
}

bool Input::IsMouseButtonDown(int keycode)
{
	bool currentState = false;
	if (m_mouse_button[keycode] == GLFW_PRESS)
	{
		currentState = true;
	}
	return currentState;
}

bool Input::IsMouseButtonUp(int keycode)
{
	bool currentState = false;
	if (m_mouse_button[keycode] == GLFW_RELEASE)
	{
		currentState = true;
	}
	return currentState;
}

void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	m_keys[key] = action;
	m_press_keys[key] = action;
}

void Input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	m_mouse_button[button] = action;
	m_press_mouse_button[button] = action;
}

