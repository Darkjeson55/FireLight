#ifndef SIMPLERENDERSYSTEM_H
#define SIMPLERENDERSYSTEM_H
//prototype

#include <vector>
#include "Renderable.h"
#include "Camera.h"
#include <algorithm>



/// <summary>
/// Actual Render System
/// Provide to render stuff on screen
/// </summary>
class SimpleRenderSystem
{
public:
	SimpleRenderSystem();

	



	void Add(Renderable *rend);

	void remove(Renderable *rend);



	void Render();

	void set_Camera(Camera *camera);

	~SimpleRenderSystem();
private:

	Camera* m_camera;
	std::vector<Renderable*> m_renderables;

};
#endif SIMPLERENDERSYSTEM_H