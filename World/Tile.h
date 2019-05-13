#pragma once
#include <SDL.h>
#include <SDL_image.h>


class Tile
{
public:
	static const int kTileWidth = 32;
	static const int kTileHeight = 32;

private:
	SDL_Rect m_tileRect;
	SDL_Rect m_src;
	SDL_Texture* m_texture;
public:
	Tile(SDL_Texture* texture, SDL_Rect src, int gridX, int gridY);
	~Tile();

	void Draw(SDL_Renderer* pRenderer);
	int GetX(){ return m_tileRect.x; }
	int GetY() { return m_tileRect.y; }
	void SetRect(int x, int y);
};

