#pragma once
#include "GameState.h"

#include "Button.h"

class MenuGameState :
	public GameState
{
private:
	Button m_PlayButton;
	Button m_CreditsButton;
public:
	MenuGameState(Game* pGame);
	~MenuGameState();

	// Inherited via GameState
	virtual void Enter() override;
	virtual void Update(double DeltaSeconds) override;
	virtual void Exit() override;
	virtual void Draw(SDL_Renderer* pRenderer) override;
	virtual void HandleEvent(SDL_Event Event) override;
};

