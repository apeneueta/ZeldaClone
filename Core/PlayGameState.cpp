#include "PlayGameState.h"

#include <iostream>


PlayGameState::PlayGameState(Game* pGame)
	: GameState(pGame)
{
	
}


PlayGameState::~PlayGameState()
{
}

void PlayGameState::Enter()
{
	m_Terra.Init(m_pGame->GetRenderer());
	m_World = new World(&m_Terra);
	m_World->Init(m_pGame->GetRenderer());

	Box* BoxA = new Box(100, 100, 20, 20);
	TestA.SetShape(BoxA);

	Box* BoxB = new Box(170, 125, 40, 40);
	TestB.SetShape(BoxB);
}

void PlayGameState::Update(double DeltaSeconds)
{
	if (m_Terra.IsOverlapping(&TestA))
	{
		std::cout << "Overlapping!" << std::endl;
	}
	if (m_Terra.IsOverlapping(&TestB))
	{
		std::cout << "Overlapping!" << std::endl;
	}

	m_Terra.Update(DeltaSeconds);
	m_World->Update(DeltaSeconds);
}

void PlayGameState::Draw(SDL_Renderer* pRenderer)
{
	SDL_SetRenderDrawColor(pRenderer, 75, 50, 50, 255);
	SDL_RenderClear(pRenderer);

	m_World->Draw(pRenderer);
	m_Terra.Draw(pRenderer);

	TestA.DrawDebug(pRenderer);
	TestB.DrawDebug(pRenderer);


	SDL_RenderPresent(pRenderer);
}

void PlayGameState::HandleEvent(SDL_Event event)
{
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_UP)
			{
				m_Terra.ChangeAnimation(EPlayerAnimation::Up);
				m_Terra.SetMoveUp(true);
				m_Terra.SetCurrentDirection(EDirection::Up);
				m_World->SetUp(true);
			}
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				m_Terra.ChangeAnimation(EPlayerAnimation::Down);
				m_Terra.SetMoveDown(true);
				m_Terra.SetCurrentDirection(EDirection::Down);
				m_World->SetDown(true);
			}
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				m_Terra.ChangeAnimation(EPlayerAnimation::Left);
				m_Terra.SetMoveLeft(true);
				m_Terra.SetCurrentDirection(EDirection::Left);
				m_World->SetLeft(true);
			}
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				m_Terra.ChangeAnimation(EPlayerAnimation::Right);
				m_Terra.SetMoveRight(true);
				m_Terra.SetCurrentDirection(EDirection::Right);
				m_World->SetRight(true);
			}
			if (event.key.keysym.sym == SDLK_a)
			{
				m_Terra.ChangeAnimation(EPlayerAnimation::LAttack);
			}
			if (event.key.keysym.sym == SDLK_s)
			{
				m_Terra.ChangeAnimation(EPlayerAnimation::DAttack);
			}
			if (event.key.keysym.sym == SDLK_d)
			{
				m_Terra.ChangeAnimation(EPlayerAnimation::RAttack);
			}
			if (event.key.keysym.sym == SDLK_w)
			{
				m_Terra.ChangeAnimation(EPlayerAnimation::UAttack);
			}
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				m_Terra.Attack();
			}
			if (event.key.keysym.sym == SDLK_m)
			{
				m_pGame->ChangeState(EGameState::Menu);
			}
	}
		if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_UP)
			{
				m_Terra.SetMoveUp(false);
				m_World->SetUp(false);
			}
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				m_Terra.SetMoveDown(false);
				m_World->SetDown(false);
			}
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				m_Terra.SetMoveLeft(false);
				m_World->SetLeft(false);
			}
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				m_Terra.SetMoveRight(false);
				m_World->SetRight(false);
			}
		}		
}

void PlayGameState::Exit()
{
	SDL_DestroyTexture(m_pAnimTestTexture);
}
