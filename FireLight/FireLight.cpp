#include "FireLight.h"

GLFWwindow* window;

void InitWindow(const int& width, const int& height, std::string name)
{
	if (!glfwInit())
		return;

	window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

	if (window == NULL)
		return;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

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


