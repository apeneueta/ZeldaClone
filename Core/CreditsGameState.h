#pragma once
#include "GameState.h"

#include "Button.h"

class CreditsGameState :
	public GameState
{
private:
	Button m_MenuButton;

	SDL_Texture* m_pAnimTestTexture;
	SDL_Surface* m_pFontSurface;
	SDL_Texture* m_pFontTexture;
public:
	CreditsGameState(Game* pGame);
	~CreditsGameState();

	// Inherited via GameState
	virtual void Enter() override;
	virtual void Update(double DeltaSeconds) override;
	virtual void Draw(SDL_Renderer * pRenderer) override;
	virtual void HandleEvent(SDL_Event Event) override;
	virtual void Exit() override;
};

