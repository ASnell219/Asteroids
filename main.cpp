// Vector2D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vector2D.h"
#include "core.h"
#include "math.h"
#include "transform.h"
#include "shape.h"
#include "color.h"
#include "actor.h"
#include "asteroid.h"
#include "player.h"
#include "scene.h"

using namespace Core;
using namespace nce;

Scene scene;

bool Update(float dt)
{
	bool quit = false;
	
	if (Input::IsPressed(Input::KEY_ESCAPE))
	{
		quit = true;
	}

	scene.Update(dt);

	return quit;
}

void Draw(Graphics& graphics)
{
	std::string sceneInfo = "scene: " + std::to_string(scene.Size());
	graphics.SetColor(Color::white);
	graphics.DrawString(10, 10, sceneInfo.c_str());
	scene.Draw(graphics);
	
}

int main()
{
	Player* player = new Player;

	std::fstream stream("resources\\ship.act");
	stream >> *player;
	player->Initialize();
	player->SetScene(&scene);
	stream.close();

	scene.AddObject(player);


	for (size_t i = 0; i < 5; i++)
	{
		Asteroid* asteroid = new Asteroid;
		stream.open("resources\\asteroid.act");
		stream >> *asteroid;
		stream.close();

		asteroid->Initialize();
		asteroid->SetScene(&scene);
		scene.AddObject(asteroid);
	}

	char name[32];
	strcpy_s(name, "Program");
	Core::Init(name, 800, 600);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();
	Core::Shutdown();

    return 0;
}