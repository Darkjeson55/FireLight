#ifndef FIRELIGHT_H
#define FIRELIGHT_H

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include "thirdParty/imgui/imgui_impl_glfw.h"
#include "thirdParty/imgui/imgui_impl_opengl3.h"
#include <string>
#include <iostream>
#include "src/OpenGL/Shader.h"

void InitWindow(const int& width, const int& height, std::string name);
bool SetUpFrame();
void UpdateWindow();
void CloseWindow();


#endif