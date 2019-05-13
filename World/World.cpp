#include "World.h"
#include "GameStd.h"
#include "Tile.h"
#include "EntityFactory.h"
#include "AnimatedCharacter.h"
#include <iostream>

World::World(AnimatedCharacter* player)
{
	m_pPlayer = player;
}


World::~World()
{
}


void World::Init(SDL_Renderer * renderer)
{
	int m_world[kWorldWidth][kWorldHeight] = {
		{61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61},
		{61,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,61							  },
		{61,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,4,5,2,2,2,2,2,2,2,2,2,2,61							  },
		{61,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,33,34,35,2,2,2,2,2,2,2,2,2,2,61						  },
		{61,2,2,2,2,60,61,62,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,61						  },
		{61,2,2,2,2,90,91,92,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,31,2,2,2,2,2,61						  },
		{61,2,31,2,2,2,2,2,2,2,31,2,2,31,2,2,2,2,2,2,120,121,122,2,2,2,2,2,2,61					  },
		{61,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,150,151,152,31,2,2,31,2,2,61					  },
		{61,2,2,2,2,2,2,2,2,2,31,2,2,31,2,2,2,2,2,2,180,181,182,2,2,2,2,2,2,61					  },
		{61,2,2,60,61,62,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,61						  },
		{61,2,2,90,91,92,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,61						  },
		{61,2,2,2,2,2,2,120,121,122,2,2,2,2,2,2,31,2,2,2,2,2,2,2,2,2,2,2,2,61					  },
		{61,2,2,2,2,2,2,150,151,152,2,2,2,2,2,2,2,120,121,122,2,2,2,31,2,2,31,2,2,61			  },
		{61,2,2,2,2,2,2,180,181,182,2,2,31,2,2,2,2,150,151,152,2,2,2,2,2,2,2,2,2,61				  },
		{61,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,180,181,182,2,2,2,2,2,2,2,2,2,61					  },
		{61,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,31,2,2,31,2,2,61						  },
		{61,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,61							  },
		{61,2,2,2,31,2,2,2,2,31,2,2,2,2,2,2,2,31,2,2,2,2,2,2,2,2,2,2,2,61						  },
		{61,2,2,2,2,2,2,2,2,2,2,2,120,121,122,2,2,2,2,2,2,2,120,121,122,2,2,2,2,61				  },
		{61,2,2,2,2,2,31,2,31,2,2,2,150,151,152,2,2,2,31,2,2,2,150,151,152,2,2,2,2,61			  },
		{61,2,2,2,2,2,2,2,2,2,2,2,180,181,182,2,2,2,2,2,2,2,180,181,182,2,2,2,2,61				  },
		{61,2,2,2,31,2,2,2,2,31,2,2,2,2,2,2,2,2,31,2,2,2,2,2,2,2,2,2,2,61						  },
		{61,2,2,2,2,2,2,2,2,2,2,2,31,2,2,2,2,2,2,2,31,2,2,2,2,2,2,2,2,61						  },
		{61,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,61							  },
		{61,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,31,2,2,2,31,2,2,2,61						  },
		{61,2,2,2,2,2,2,2,2,31,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,61							  },
		{61,2,2,31,2,2,2,2,2,2,2,2,31,2,2,2,31,2,2,2,2,2,2,2,31,2,2,2,2,61						  },
		{61,2,2,2,2,2,31,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,61							  },
		{61,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,61							  },
		{61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61,61}
		};

	m_currentX = m_currentY = 0;
	m_pSurface = SDL_LoadBMP("Assets/Test_Mario.bmp");
	//m_pTexture = SDL_CreateTextureFromSurface(renderer, m_pSurface);

	m_pTexture = IMG_LoadTexture(renderer, "Assets/Tiles.png");

	m_SourceRect = SDL_Rect{ 0, 0, 32, 32 }; // Draw the whole texture
	//m_SourceRect = SDL_Rect{ 0, 0, 52, 76 }; // Draw the whole texture
	//m_DestRect = SDL_Rect{ (int)m_currentX, (int)m_currentY, WINDOW_WIDTH, WINDOW_HEIGHT };

	// generate all the tiles
	for (int x = 0; x < kWorldHeight; ++x)
	{
		for (int y = 0; y < kWorldWidth; ++y)
		{
			m_SourceRect.x = (m_world[y][x] % kWorldWidth) * 32;
			m_SourceRect.y = (m_world[y][x] / kWorldHeight) * 32;
			
			// calculate the index
			int index = GetIndexFromGridPoint(x, y);
			m_pTiles[index] = new Tile(m_pTexture, m_SourceRect, x, y);
		}
	}
	EntityFactory entityFactory(renderer);


	m_Spider = (Spider*)entityFactory.CreateEntity(EntityFactory::entityType::Spider, 30, 30);

	//m_Enemies.push_back(m_Spider);
}

void World::Draw(SDL_Renderer* renderer)
{
	//SDL_RenderCopy(renderer, m_pTexture, &m_SourceRect, &m_DestRect);

	// render the world
	for (int i = 0; i < kWorldSize; ++i)
	{
		if (m_pTiles[i])
		{
			m_pTiles[i]->Draw(renderer);
		}
	}

	m_Spider->Draw(renderer);
}

void World::Update(float deltaTime)
{
	if (m_pPlayer->IsOverlapping(m_Spider->GetCollider()))
	{
		std::cout << "Overlapping!" << std::endl;
	}

	int movement = (int)(100 * deltaTime);

	// Checks that the bounds of the world map will stay within the screen area
	if (!m_pPlayer->GetMovePlayer())
	{	
		if (m_right)
		{
			if (m_pTiles[899]->GetX() >= WINDOW_WIDTH - 32)
			{
				MoveWorld(deltaTime, -movement, 0);
			}
			else
			{
				m_pPlayer->SetMovePlayer(true);
			}
		}

		if (m_left)
		{
			if (m_pTiles[0]->GetX() <= 0)
			{
				MoveWorld(deltaTime, movement, 0);
			}
			else
			{
				m_pPlayer->SetMovePlayer(true);
			}
		}

		if (m_up)
		{
			if (m_pTiles[0]->GetY() <= 0)
			{
				MoveWorld(deltaTime, 0, movement);
			}
			else
			{
				m_pPlayer->SetMovePlayer(true);
			}
		}

		if (m_down)
		{
			if (m_pTiles[899]->GetY() >= WINDOW_HEIGHT - 32)
			{
				MoveWorld(deltaTime, 0, -movement);
			}
			else
			{
				m_pPlayer->SetMovePlayer(true);
			}
		}
	}

	m_Spider->Update(deltaTime);
}

void World::MoveWorld(float deltaTime, int moveX, int moveY)
{
	for (int i = 0; i < kWorldSize; ++i)
	{
		if (m_pTiles[i])
		{
			m_pTiles[i]->SetRect(moveX, moveY);
			
		}
	}

	m_Spider->SetRect(moveX, moveY);
}