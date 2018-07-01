#include "Sprite.h"



Sprite::Sprite(Texture texture, Shader shader)
{
	m_offsetX = 0;
	m_offsetY = 0;

	m_row = 1;
	m_collum = 1;

	m_texutre = texture;
	m_shader = shader;

}

void Sprite::init()
{

	float vertices[]
	{
		//Position			//UV
		0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		1.0f, -1.0f, 0.0f,  1.0f, 0.0f,

		0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		0.0f, -1.0f, 0.0f,  0.0f, 0.0f,
		1.0f, -1.0f, 0.0f,  1.0f, 0.0f
	};



	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	m_vbo.Gen(vertices, sizeof(vertices), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	m_vbo.Unbind();
	glBindVertexArray(0);

}


void Sprite::setOffset(float x, float y)
{
	m_offsetX = x;
	m_offsetY = y;

}

void Sprite::setRows(float row, float collum)
{
	m_row = row;
	m_collum = collum;
}


void Sprite::Draw(Camera2D *camera)
{
	model = glm::scale(glm::translate(glm::mat4(1.0f), this->get_world_position()), this->get_world_scale());
	model = glm::rotate(model, this->get_local_rotation(), glm::vec3(0, 0, 1));

	m_shader.SetMatrix4("model", model, false);
	m_shader.SetMatrix4("projection", camera->getMatrix(), false);

	m_shader.SetVector2f("row", glm::vec2(m_row, m_collum), false);
	m_shader.SetVector2f("offset", glm::vec2(m_offsetX, m_offsetY), false);



	m_texutre.Bind();
	m_shader.Use();


	glBindVertexArray(VAO);



	//glDrawElements(GL_TRIANGLES,100 * 100 * 6, GL_UNSIGNED_INT, 0);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}


Sprite::~Sprite()
{
}
