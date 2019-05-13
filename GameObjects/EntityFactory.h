#pragma once
#include <SDL.h>
#include "World.h"
#include "Spider.h"


class EntityFactory
{
private:
	/*int m_x;
	int m_y;*/
	SDL_Renderer* m_pRenderer;
public:
	enum class entityType
	{
		Spider,
		Flower,
		Blob,
		Bat
	};
	EntityFactory(SDL_Renderer* pRenderer);
	~EntityFactory();

	class Entity* CreateEntity(entityType type, int x, int y);
};

