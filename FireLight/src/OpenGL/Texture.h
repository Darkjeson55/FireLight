#pragma once

#include <gl/glew.h>

#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "../../thirdParty/stb_image.h"


struct Texture
{
	static Texture LoadTextureFromFile(const std::string& path)
	{
		Texture temp;
		int widht, height, nrChannels;
		unsigned char* data = stbi_load(path.c_str(), &widht, &height, &nrChannels, 0);

		glGenTextures(1, &temp.ID);

		glBindTexture(GL_TEXTURE_2D, temp.ID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widht, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);

		return temp;
	}

	void Bind()
	{
		glBindTexture(GL_TEXTURE_2D, ID);
	}


	unsigned int ID;
};