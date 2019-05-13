#include "Game.h"

#include <iostream>
#include <SDL_image.h>

#include "MenuGameState.h"
#include "PlayGameState.h"
#include "CreditsGameState.h"


bool Game::InitializeController()
{
	for (int JoystickIndex = 0; JoystickIndex < SDL_NumJoysticks();
	++JoystickIndex)
	{
		if (SDL_IsGameController(JoystickIndex))
		{
			m_pController = SDL_GameControllerOpen(JoystickIndex);
		}
	}

	char* Mapping = SDL_GameControllerMapping(m_pController);
	if (Mapping)
	{
		std::cout << Mapping << std::endl;
	}

	return (m_pController != nullptr);
}

void Game::TEST_CheckControllerInUpdate()
{
	// Read buttons without polling the event system:
	SDL_GameControllerButton JumpButton = SDL_CONTROLLER_BUTTON_A;
	Uint8 Pressure = SDL_GameControllerGetButton(m_pController, JumpButton);
	if (Pressure != 0)
	{
		std::cout << "Jump Pressure: " << Pressure << std::endl;
	}
}

Game::Game()
{
}


Game::~Game()
{
}

bool Game::Init()
{
	std::cout << "Hello, SDL!" << std::endl;

	// Init
	SDL_Init(SDL_INIT_EVERYTHING);
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != (IMG_INIT_PNG | IMG_INIT_JPG))
	{
		// Failed
		std::cout << "Failed to initialize SDL_image!" << std::endl;
	}

	// CreateWindow
	m_pWindow = SDL_CreateWindow("Practice", 50, 50, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	// CreateRenderer
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC |
		SDL_RendererFlags::SDL_RENDERER_ACCELERATED);

	if (TTF_Init() == -1)
	{
		std::cout << "Failed to initialize SDL_ttf!" << std::endl;
	}

	m_pMenuFont = TTF_OpenFont("Assets/Fonts/BodoniFLF-Roman.ttf", 50);

	//TTF_SetFontOutline(m_pTestFont, 5);
	// Testing fonts
	SDL_Color TextColor{ 0, 0, 255, 100 };
	SDL_Color TextColor2{ 255, 0, 255, 100 };
	m_pFontSurface = TTF_RenderText_Blended(m_pMenuFont,
		"Hello TTF!", TextColor);
	m_pFontTexture = SDL_CreateTextureFromSurface(m_pRenderer,
		m_pFontSurface);

	m_TestButton.Init(m_pRenderer, m_pMenuFont, "PLAY", 0, 0);

	//m_Mario.Init(m_pRenderer);
	m_Terra.Init(m_pRenderer);
	m_World.Init(m_pRenderer);

	m_IsPlaying = true;

	InitializeController();
	ChangeState(EGameState::Menu);

	return true;
}

void Game::HandleEvent(SDL_Event event)
{
	if (m_pCurrentState)
	{
		m_pCurrentState->HandleEvent(event);
	}
}

void Game::Update(double deltaSeconds)
{
	m_pCurrentState->Update(deltaSeconds);
}

void Game::Draw()
{
	m_pCurrentState->Draw(m_pRenderer);
}

void Game::Cleanup()
{
	SDL_DestroyTexture(m_pFontTexture);
	SDL_FreeSurface(m_pFontSurface);

	SDL_DestroyTexture(m_pAnimTestTexture);

	TTF_Quit();
	// Destroy in the *reverse* order that we made them
	SDL_DestroyRenderer(m_pRenderer);
	// DestroyWindow
	SDL_DestroyWindow(m_pWindow);
	// Clean up SDL_image
	IMG_Quit();
	// Quit
	SDL_Quit();
}

void Game::ChangeState(EGameState NewState)
{
	// The first time the state is changed, don't exit or deallocate memory!
	if (m_pCurrentState != nullptr)
	{
		m_pCurrentState->Exit();
		delete m_pCurrentState;
	}

	switch (NewState)
	{
	case EGameState::Menu:
		// keyword: this
		// A pointer to the current object (Game).  To the Game Instance that
		//	called this function.  Very useful for giving somebody a pointer to
		//	itself
		m_pCurrentState = new MenuGameState(this);  // self
		break;
	case EGameState::Play:
		m_pCurrentState = new PlayGameState(this);
		break;
	case EGameState::Credits:
		m_pCurrentState = new CreditsGameState(this);
		break;
	default:
		std::cout << "Error: State not handled!" << std::endl;
		break;
	}

	m_pCurrentState->Enter();
}
