#pragma once
#include "GameState.h"

#include "Collider.h"
#include "Box.h"
#include "World.h"


class PlayGameState :
	public GameState
{
private:
	Character m_Mario;
	AnimatedCharacter m_Terra;
	World* m_World;

	SDL_Texture* m_pAnimTestTexture;
	SDL_GameController* m_pController;

	//Testing
	Collider TestA;
	Collider TestB;

public:
	PlayGameState(Game* pGame);
	~PlayGameState();

	// Inherited via GameState
	virtual void Enter() override;
	virtual void Update(double DeltaSeconds) override;
	virtual void Draw(SDL_Renderer* pRenderer) override;
	virtual void HandleEvent(SDL_Event Event) override;
	virtual void Exit() override;
};

