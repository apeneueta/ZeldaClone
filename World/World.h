#pragma once
#include <SDL.h>
#include "Entity.h"
#include "Spider.h"

class Tile;
class AnimatedCharacter;

class World
{
private:
	SDL_Renderer* m_pRenderer;
	SDL_Surface* m_pSurface;
	SDL_Texture* m_pTexture;

	SDL_Rect m_SourceRect;
	SDL_Rect m_DestRect;

	AnimatedCharacter* m_pPlayer;

	float m_currentX;
	float m_currentY;

	std::vector<Entity> m_Enemies;
	Spider* m_Spider;

	bool m_right;
	bool m_left;
	bool m_up;
	bool m_down;

protected:
	// width & height, in tiles
	static constexpr int kWorldWidth = 30;
	static constexpr int kWorldHeight = 30;
	static constexpr int kWorldSize = kWorldWidth * kWorldHeight;

	//int m_world[kWorldWidth][kWorldHeight];
	// tile grid
	Tile* m_pTiles[kWorldSize];
public:
	World() {};
	World(AnimatedCharacter* player);
	~World();

	void Init(SDL_Renderer* renderer);
	void Draw(SDL_Renderer* renderer);
	void Update(float deltaTime);


	void SetRight(bool set) { m_right = set; };
	void SetLeft(bool set) { m_left = set; };
	void SetUp(bool set) { m_up = set; };
	void SetDown(bool set) { m_down = set; };

protected:
	int GetIndexFromGridPoint(int x, int y) const { return (y * kWorldWidth) + x; };

private:
	void MoveWorld(float deltaTime, int moveX, int moveY);
};

