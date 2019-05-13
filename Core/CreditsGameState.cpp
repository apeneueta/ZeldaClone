#include "CreditsGameState.h"
#include <iostream>

#include "Game.h"


CreditsGameState::CreditsGameState(Game* pGame)
	: GameState(pGame)
{
}


CreditsGameState::~CreditsGameState()
{
}

void CreditsGameState::Enter()
{
	m_MenuButton.Init(m_pGame->GetRenderer(), m_pGame->GetFont(), "Menu!", 300, 300);
	SDL_Color TextColor{ 0, 0, 255, 100 };
	SDL_Color TextColor2{ 255, 0, 255, 100 };
	m_pFontSurface = TTF_RenderText_Blended(m_pGame->GetFont(),
		"Credits!", TextColor);
	m_pFontTexture = SDL_CreateTextureFromSurface(m_pGame->GetRenderer(),
		m_pFontSurface);
}

void CreditsGameState::Update(double DeltaSeconds)
{
	if (m_MenuButton.ClickedThisFrame())
	{
		m_pGame->ChangeState(EGameState::Menu);
	}
}

void CreditsGameState::Draw(SDL_Renderer * pRenderer)
{
	SDL_SetRenderDrawColor(pRenderer, 0, 50, 50, 255);
	SDL_RenderClear(pRenderer);

	SDL_Rect Src = { 0, 0, m_pFontSurface->w, m_pFontSurface->h };
	SDL_Rect Dest = { 300, 50, Src.w, Src.h };
	SDL_RenderCopy(m_pGame->GetRenderer(), m_pFontTexture, &Src, &Dest);

	m_MenuButton.Draw();

	SDL_RenderPresent(pRenderer);

}

void CreditsGameState::HandleEvent(SDL_Event Event)
{
	if (Event.type == SDL_MOUSEMOTION)
	{
		SDL_Point MousePoint{ Event.motion.x, Event.motion.y };
		m_MenuButton.CheckMouseOver(MousePoint);
	}
	if (Event.type == SDL_MOUSEBUTTONDOWN)
	{
		SDL_Point MousePoint{ Event.motion.x, Event.motion.y };
		m_MenuButton.Click(MousePoint);
	}
}

void CreditsGameState::Exit()
{
	SDL_DestroyTexture(m_pFontTexture);
	SDL_FreeSurface(m_pFontSurface);
	m_MenuButton.Cleanup();
}
