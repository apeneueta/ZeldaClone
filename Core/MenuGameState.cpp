#include "MenuGameState.h"

#include <iostream>

#include "Game.h"

// Call the parent constructor that requires a Game*
MenuGameState::MenuGameState(Game* pGame)
	: GameState(pGame)
{

}


MenuGameState::~MenuGameState()
{
}

void MenuGameState::Enter()
{
	std::cout << "Entering Menu State..." << std::endl;

	m_PlayButton.Init(m_pGame->GetRenderer(), m_pGame->GetFont(), "Begin!", 250, 300);
	m_CreditsButton.Init(m_pGame->GetRenderer(), m_pGame->GetFont(), "Credits!", 400, 300);
}

void MenuGameState::Update(double DeltaSeconds)
{
	if (m_PlayButton.ClickedThisFrame())
	{
		m_pGame->ChangeState(EGameState::Play);
	}
	else if (m_CreditsButton.ClickedThisFrame())
	{
		m_pGame->ChangeState(EGameState::Credits);
	}
}

void MenuGameState::Exit()
{
	m_CreditsButton.Cleanup();
	m_PlayButton.Cleanup();
	std::cout << "Exiting Menu State..." << std::endl;
}

void MenuGameState::Draw(SDL_Renderer* pRenderer)
{
	SDL_SetRenderDrawColor(pRenderer, 0, 50, 75, 255);
	SDL_RenderClear(pRenderer);

	m_PlayButton.Draw();
	m_CreditsButton.Draw();

	SDL_RenderPresent(pRenderer);
}

void MenuGameState::HandleEvent(SDL_Event Event)
{
	if (Event.type == SDL_MOUSEMOTION)
	{
		SDL_Point MousePoint{ Event.motion.x, Event.motion.y };
		m_CreditsButton.CheckMouseOver(MousePoint);
		m_PlayButton.CheckMouseOver(MousePoint);
	}
	if (Event.type == SDL_MOUSEBUTTONDOWN)
	{
		SDL_Point MousePoint{ Event.motion.x, Event.motion.y };
		m_CreditsButton.Click(MousePoint);
		m_PlayButton.Click(MousePoint);
	}
}
