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

struct Time
{

};

struct Input 
{
	/* Printable keys */
	static const unsigned int KEY_SPACE = GLFW_KEY_SPACE;
	static const unsigned int KEY_APOSTROPHE = GLFW_KEY_APOSTROPHE;
	static const unsigned int KEY_COMMA = GLFW_KEY_COMMA;
	static const unsigned int KEY_MINUS = GLFW_KEY_MINUS;
	static const unsigned int KEY_PERIOD = GLFW_KEY_PERIOD;
	static const unsigned int KEY_SLASH = GLFW_KEY_SLASH;
	static const unsigned int KEY_0 = GLFW_KEY_0;
	static const unsigned int KEY_1 = GLFW_KEY_1;
	static const unsigned int KEY_2 = GLFW_KEY_2;
	static const unsigned int KEY_3 = GLFW_KEY_3;
	static const unsigned int KEY_4 = GLFW_KEY_4;
	static const unsigned int KEY_5 = GLFW_KEY_5;
	static const unsigned int KEY_6 = GLFW_KEY_6;
	static const unsigned int KEY_7 = GLFW_KEY_7;
	static const unsigned int KEY_8 = GLFW_KEY_8;
	static const unsigned int KEY_9 = GLFW_KEY_9;
	static const unsigned int KEY_SEMICOLON = GLFW_KEY_SEMICOLON;
	static const unsigned int KEY_EQUAL = GLFW_KEY_EQUAL;
	static const unsigned int KEY_A = GLFW_KEY_A;
	static const unsigned int KEY_B = GLFW_KEY_B;
	static const unsigned int KEY_C = GLFW_KEY_C;
	static const unsigned int KEY_D = GLFW_KEY_D;
	static const unsigned int KEY_E = GLFW_KEY_E;
	static const unsigned int KEY_F = GLFW_KEY_F;
	static const unsigned int KEY_G = GLFW_KEY_G;
	static const unsigned int KEY_H = GLFW_KEY_H;
	static const unsigned int KEY_I = GLFW_KEY_I;
	static const unsigned int KEY_J = GLFW_KEY_J;
	static const unsigned int KEY_K = GLFW_KEY_K;
	static const unsigned int KEY_L = GLFW_KEY_L;
	static const unsigned int KEY_M = GLFW_KEY_M;
	static const unsigned int KEY_N = GLFW_KEY_N;
	static const unsigned int KEY_O = GLFW_KEY_O;
	static const unsigned int KEY_P = GLFW_KEY_P;
	static const unsigned int KEY_Q = GLFW_KEY_Q;
	static const unsigned int KEY_R = GLFW_KEY_R;
	static const unsigned int KEY_S = GLFW_KEY_S;
	static const unsigned int KEY_T = GLFW_KEY_T;
	static const unsigned int KEY_U = GLFW_KEY_U;
	static const unsigned int KEY_V = GLFW_KEY_V;
	static const unsigned int KEY_W = GLFW_KEY_W;
	static const unsigned int KEY_X = GLFW_KEY_X;
	static const unsigned int KEY_Y = GLFW_KEY_Y;
	static const unsigned int KEY_Z = GLFW_KEY_Z;
	static const unsigned int KEY_LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET;
	static const unsigned int KEY_BACKSLASH = GLFW_KEY_BACKSLASH;
	static const unsigned int KEY_RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET;
	static const unsigned int KEY_GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT;
	static const unsigned int KEY_WORLD_1 = GLFW_KEY_WORLD_1;
	static const unsigned int KEY_WORLD_2 = GLFW_KEY_WORLD_2;

	/* Function keys */
	static const unsigned int KEY_ESCAPE = GLFW_KEY_ESCAPE;
	static const unsigned int KEY_ENTER = GLFW_KEY_ENTER;
	static const unsigned int KEY_TAB = GLFW_KEY_TAB;
	static const unsigned int KEY_BACKSPACE = GLFW_KEY_BACKSPACE;
	static const unsigned int KEY_INSERT = GLFW_KEY_INSERT;
	static const unsigned int KEY_DELETE = GLFW_KEY_DELETE;
	static const unsigned int KEY_RIGHT = GLFW_KEY_RIGHT;
	static const unsigned int KEY_LEFT = GLFW_KEY_LEFT;
	static const unsigned int KEY_DOWN = GLFW_KEY_DOWN;
	static const unsigned int KEY_UP = GLFW_KEY_UP;
	static const unsigned int KEY_PAGE_UP = GLFW_KEY_PAGE_UP;
	static const unsigned int KEY_PAGE_DOWN = GLFW_KEY_PAGE_DOWN;
	static const unsigned int KEY_HOME = GLFW_KEY_HOME;
	static const unsigned int KEY_END = GLFW_KEY_END;
	static const unsigned int KEY_CAPS_LOCK = GLFW_KEY_CAPS_LOCK;
	static const unsigned int KEY_SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK;
	static const unsigned int KEY_NUM_LOCK = GLFW_KEY_NUM_LOCK;
	static const unsigned int KEY_PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN;
	static const unsigned int KEY_PAUSE = GLFW_KEY_PAUSE;
	static const unsigned int KEY_F1 = GLFW_KEY_F1;
	static const unsigned int KEY_F2 = GLFW_KEY_F2;
	static const unsigned int KEY_F3 = GLFW_KEY_F3;
	static const unsigned int KEY_F4 = GLFW_KEY_F4;
	static const unsigned int KEY_F5 = GLFW_KEY_F5;
	static const unsigned int KEY_F6 = GLFW_KEY_F6;
	static const unsigned int KEY_F7 = GLFW_KEY_F7;
	static const unsigned int KEY_F8 = GLFW_KEY_F8;
	static const unsigned int KEY_F9 = GLFW_KEY_F9;
	static const unsigned int KEY_F10 = GLFW_KEY_F10;
	static const unsigned int KEY_F11 = GLFW_KEY_F11;
	static const unsigned int KEY_F12 = GLFW_KEY_F12;
	static const unsigned int KEY_F13 = GLFW_KEY_F13;
	static const unsigned int KEY_F14 = GLFW_KEY_F14;
	static const unsigned int KEY_F15 = GLFW_KEY_F15;
	static const unsigned int KEY_F16 = GLFW_KEY_F16;
	static const unsigned int KEY_F17 = GLFW_KEY_F17;
	static const unsigned int KEY_F18 = GLFW_KEY_F18;
	static const unsigned int KEY_F19 = GLFW_KEY_F19;
	static const unsigned int KEY_F20 = GLFW_KEY_F20;
	static const unsigned int KEY_F21 = GLFW_KEY_F21;
	static const unsigned int KEY_F22 = GLFW_KEY_F22;
	static const unsigned int KEY_F23 = GLFW_KEY_F23;
	static const unsigned int KEY_F24 = GLFW_KEY_F24;
	static const unsigned int KEY_F25 = GLFW_KEY_F25;
	static const unsigned int KEY_KP_0 = GLFW_KEY_KP_0;
	static const unsigned int KEY_KP_1 = GLFW_KEY_KP_1;
	static const unsigned int KEY_KP_2 = GLFW_KEY_KP_2;
	static const unsigned int KEY_KP_3 = GLFW_KEY_KP_3;
	static const unsigned int KEY_KP_4 = GLFW_KEY_KP_4;
	static const unsigned int KEY_KP_5 = GLFW_KEY_KP_5;
	static const unsigned int KEY_KP_6 = GLFW_KEY_KP_6;
	static const unsigned int KEY_KP_7 = GLFW_KEY_KP_7;
	static const unsigned int KEY_KP_8 = GLFW_KEY_KP_8;
	static const unsigned int KEY_KP_9 = GLFW_KEY_KP_9;
	static const unsigned int KEY_KP_DECIMAL = GLFW_KEY_KP_DECIMAL;
	static const unsigned int KEY_KP_DIVIDE = GLFW_KEY_KP_DIVIDE;
	static const unsigned int KEY_KP_MULTIPLY = GLFW_KEY_KP_MULTIPLY;
	static const unsigned int KEY_KP_SUBTRACT = GLFW_KEY_KP_SUBTRACT;
	static const unsigned int KEY_KP_ADD = GLFW_KEY_KP_ADD;
	static const unsigned int KEY_KP_ENTER = GLFW_KEY_KP_ENTER;
	static const unsigned int KEY_KP_EQUAL = GLFW_KEY_KP_EQUAL;
	static const unsigned int KEY_LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT;
	static const unsigned int KEY_LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL;
	static const unsigned int KEY_LEFT_ALT = GLFW_KEY_LEFT_ALT;
	static const unsigned int KEY_LEFT_SUPER = GLFW_KEY_LEFT_SUPER;
	static const unsigned int KEY_RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT;
	static const unsigned int KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL;
	static const unsigned int KEY_RIGHT_ALT = GLFW_KEY_RIGHT_ALT;
	static const unsigned int KEY_RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER;
	static const unsigned int KEY_MENU = GLFW_KEY_MENU;

	//MOUSE
	static const unsigned int MOUSE_BUTTON_1 = GLFW_MOUSE_BUTTON_1;
	static const unsigned int MOUSE_BUTTON_2 = GLFW_MOUSE_BUTTON_2;
	static const unsigned int MOUSE_BUTTON_3 = GLFW_MOUSE_BUTTON_3;
	static const unsigned int MOUSE_BUTTON_4 = GLFW_MOUSE_BUTTON_4;
	static const unsigned int MOUSE_BUTTON_5 = GLFW_MOUSE_BUTTON_5;
	static const unsigned int MOUSE_BUTTON_6 = GLFW_MOUSE_BUTTON_6;
	static const unsigned int MOUSE_BUTTON_7 = GLFW_MOUSE_BUTTON_7;
	static const unsigned int MOUSE_BUTTON_8 = GLFW_MOUSE_BUTTON_8;
	static const unsigned int MOUSE_BUTTON_LAST = GLFW_MOUSE_BUTTON_LAST;
	static const unsigned int MOUSE_BUTTON_LEFT = GLFW_MOUSE_BUTTON_LEFT;
	static const unsigned int MOUSE_BUTTON_RIGHT = GLFW_MOUSE_BUTTON_RIGHT;
	static const unsigned int MOUSE_BUTTON_MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE;

	//jOYSTICK
	static const unsigned int KEY_JOYSTICK_1 = GLFW_JOYSTICK_1;
	static const unsigned int KEY_JOYSTICK_2 = GLFW_JOYSTICK_2;
	static const unsigned int KEY_JOYSTICK_3 = GLFW_JOYSTICK_3;
	static const unsigned int KEY_JOYSTICK_4 = GLFW_JOYSTICK_4;
	static const unsigned int KEY_JOYSTICK_5 = GLFW_JOYSTICK_5;
	static const unsigned int KEY_JOYSTICK_6 = GLFW_JOYSTICK_6;
	static const unsigned int KEY_JOYSTICK_7 = GLFW_JOYSTICK_7;
	static const unsigned int KEY_JOYSTICK_8 = GLFW_JOYSTICK_8;
	static const unsigned int KEY_JOYSTICK_9 = GLFW_JOYSTICK_9;
	static const unsigned int KEY_JOYSTICK_10 = GLFW_JOYSTICK_10;
	static const unsigned int KEY_JOYSTICK_11 = GLFW_JOYSTICK_11;
	static const unsigned int KEY_JOYSTICK_12 = GLFW_JOYSTICK_12;
	static const unsigned int KEY_JOYSTICK_13 = GLFW_JOYSTICK_13;
	static const unsigned int KEY_JOYSTICK_14 = GLFW_JOYSTICK_14;
	static const unsigned int KEY_JOYSTICK_15 = GLFW_JOYSTICK_15;
	static const unsigned int KEY_JOYSTICK_16 = GLFW_JOYSTICK_16;
	static const unsigned int KEY_JOYSTICK_LAST = GLFW_JOYSTICK_LAST;


	//NOTE:: this is bad implementation for the input system but it is ok for now

	static int m_keys[1024];
	static int m_press_keys[1024];

	static int m_mouse_button[32];
	static int m_press_mouse_button[32];

	static void Init()
	{
		for (int i = 0; i < (sizeof(m_keys) / sizeof(*m_keys)); i++)
		{
			m_keys[i] = -1;
		}

		for (int i = 0; i < (sizeof(m_press_keys) / sizeof(*m_press_keys)); i++)
		{
			m_press_keys[i] = -1;
		}

		for (int i = 0; i < (sizeof(m_press_mouse_button) / sizeof(*m_press_mouse_button)); i++)
		{
			m_press_mouse_button[i] = -1;
		}

		for (int i = 0; i < (sizeof(m_mouse_button) / sizeof(*m_mouse_button)); i++)
		{
			m_mouse_button[i] = -1;
		}
	}

	static bool IsKeyUp(int keycode);
	static bool IsKeyDown(int keycode);
	static bool IsKeyPress(int keycode);

	static bool IsMouseButtonDown(int keycode);
	static bool IsMouseButtonUp(int keycode);

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
};


#endif