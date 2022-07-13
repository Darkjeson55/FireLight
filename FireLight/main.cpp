#include "FireLight.h"

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "src/OpenGL/Texture.h"

unsigned int VBO, VAO;

struct GameObject
{
    unsigned int VBO, VAO;
    glm::mat4 model = glm::mat4(1.0f);
};

struct Camera {
    glm::vec3 position;
    glm::vec3 rot;
    glm::mat4 view;
    glm::mat4 projection;
};

Camera camera;

bool firstMouse = true;
bool showMouse = false;
float cameraSpeed = 0.1f;
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 direction;



float yaw = -90.0f;
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;

void InitCamera()
{
    camera.projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    camera.view = glm::mat4(1.0f);
    camera.position = glm::vec3(0, 0, 0);
    camera.rot = glm::vec3(0, 0, 0);
}


void UpdateFPSCameraLogic()
{
    direction.x = cos(glm::radians(yaw));
    direction.z = sin(glm::radians(yaw));


    float xpos = static_cast<float>(Input::GetMousePos().x);
    float ypos = static_cast<float>(Input::GetMousePos().y);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; // change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;


    if (!showMouse)
    {
        glm::vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        cameraFront = glm::normalize(front);


        if(Input::IsKeyPress(Input::KEY_W))
            cameraPos += cameraSpeed * cameraFront;
        if (Input::IsKeyPress(Input::KEY_S))
            cameraPos -= cameraSpeed * cameraFront;
        if (Input::IsKeyPress(Input::KEY_A))
            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        if (Input::IsKeyPress(Input::KEY_D))
            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

        if (Input::IsKeyPress(Input::KEY_E))
            camera.view = glm::rotate(camera.view, 0.01f, glm::vec3(0, 1, 0));
        if (Input::IsKeyPress(Input::KEY_Q))
            camera.view = glm::rotate(camera.view, -0.01f ,glm::vec3(0, 1, 0));
    }

    if (Input::IsKeyDown(Input::KEY_ESCAPE))
    {
        if (showMouse)
        {
            ShowMouseCursor(false);
            showMouse = false;
        }
        else
        {
            ShowMouseCursor(true);
            showMouse = true;
        }
    }

    camera.view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

int main()
{
    std::vector<GameObject> objects;

    //glm::mat4 view = glm::mat4(1.0f);
    //glm::mat4 cameraMatrix = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    //glm::mat4 transform = glm::mat4(1.0f);
    //view = glm::translate(view, glm::vec3(0, 0, -10.0f));
    //transform = glm::rotate(transform, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    InitWindow(800, 600, "FireLight Alpha");
    Texture texture = Texture::LoadTextureFromFile("Resources/container.jpg");
    Shader shader = Shader::LoadFromFile("Resources/first.vert", "Resources/first.frag");

    for (int i = 0; i < 9; i++)
    {
        GameObject obj;
        obj.model = glm::translate(obj.model, glm::vec3(i % 3 * 2.0,0, floor(i / 3) * 2.0));
        glGenVertexArrays(1, &obj.VAO);
        glGenBuffers(1, &obj.VBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(obj.VAO);

        glBindBuffer(GL_ARRAY_BUFFER, obj.VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // texture coord attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        glBindVertexArray(0);

        objects.push_back(obj);
    }

    InitCamera();

    glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	while (SetUpFrame())
	{
        UpdateFPSCameraLogic();

        for (int i = 0; i < 9; i++)
        {
            texture.Bind();
            shader.Use();
            shader.SetMat4("projection", camera.projection);
            shader.SetMat4("view", camera.view);
            shader.SetMat4("model", objects[i].model);

            glBindVertexArray(objects[i].VAO);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
      
		UpdateWindow();
	}

	CloseWindow();

	return 0;
}