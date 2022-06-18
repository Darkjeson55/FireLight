#ifndef FIRELIGHT_H
#define FIRELIGHT_H

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <string>
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"


void InitWindow(const int& width, const int& height, std::string name);
bool WindowShouldClose();
void UpdateWindow();
void CloseWindow();




#endif