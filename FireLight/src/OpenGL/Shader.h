#pragma once

#include <gl/glew.h>
#include <string>
#include <fstream>
#include <sstream>

//I'm not sure!?
//TODO::Need to implement better Debug and error log system. This is fine for now
#include <iostream>
//*****************


struct Shader
{
	static Shader LoadFromFile(std::string vertexPath, std::string fragmenetPath);
	
	void Use();
	void SetBool(const std::string& name, bool value);
	void SetInt(const std::string& name, int value);
	void SetFloat(const std::string& name, float value);

	unsigned int ID;
};