#pragma once

// @question: Can we remove this include?
// Jonathan Blow & Casey Muratori
#include <SDL.h>
#include "Game.h"

class GameState
{
	friend class Game;
protected:
	Game* m_pGame;

public:
	GameState(Game* pGame);
	virtual ~GameState();

	virtual void Enter() = 0;
	virtual void Update(double DeltaSeconds) = 0;
	virtual void Draw(SDL_Renderer* pRenderer) = 0;
	virtual void HandleEvent(SDL_Event Event) = 0;
	virtual void Exit() = 0;
};

