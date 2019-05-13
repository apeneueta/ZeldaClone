#include "EntityFactory.h"

EntityFactory::EntityFactory(SDL_Renderer* pRenderer)
{
	/*m_x = x;
	m_y = y;*/
	m_pRenderer = pRenderer;
}


EntityFactory::~EntityFactory()
{
}

Entity * EntityFactory::CreateEntity(EntityFactory::entityType type, int x, int y)
{
	switch (type)
	{
	case entityType::Spider: return new Spider(m_pRenderer, x, y);

	default: return nullptr;
	}
}
