#include "Tile.h"


Tile::Tile(SDL_Texture* texture, SDL_Rect src, int gridX, int gridY)
{
	m_texture = texture;
	m_src = src;
	m_tileRect.x = gridX * kTileWidth;  // convert to pixel x
	m_tileRect.y = gridY * kTileHeight;  // convert to pixel y
	m_tileRect.w = kTileWidth - 1;
	m_tileRect.h = kTileHeight - 1;
}

Tile::~Tile()
{
}

void Tile::Draw(SDL_Renderer* pRenderer)
{
	SDL_RenderCopy(pRenderer, m_texture, &m_src, &m_tileRect);
}

void Tile::SetRect(int x, int y)
{
	m_tileRect.x += x;
	m_tileRect.y += y;
}
