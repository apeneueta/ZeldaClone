#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include "GameStd.h"
#include "Character.h"
#include "AnimatedCharacter.h"
#include "Button.h"
#include "GameState.h"
#include "World.h"

class Game
{
	friend class GameState;

private:
	SDL_Renderer* m_pRenderer;
	SDL_Window* m_pWindow;

	GameState* m_pCurrentState;

	Character m_Mario;
	AnimatedCharacter m_Terra;
	World m_World;
	bool m_IsPlaying;

	// [Hack]: Hard-Coded values!
	int m_FrameWidth = 52;
	int m_FrameHeight = 76;
	int m_FrameX = 0;
	int m_FrameY = 152;
	double m_FrameDuration = 0.15;
	double m_TimeSpentInFrame;

	SDL_Texture* m_pAnimTestTexture;
	TTF_Font* m_pMenuFont;
	SDL_Surface* m_pFontSurface;
	SDL_Texture* m_pFontTexture;
	SDL_GameController* m_pController;

	Button m_TestButton;

private:
	bool InitializeController();
	void TEST_CheckControllerInUpdate();

public:
	Game();
	~Game();

	// Returns false if anything went wrong
	bool Init();
	void HandleEvent(SDL_Event event);
	void Update(double deltaSeconds);
	void Draw();
	void Cleanup();

	void ChangeState(EGameState NewState);

	// Accessors
	bool GetIsPlaying() { return m_IsPlaying; }
	SDL_Renderer* GetRenderer() { return m_pRenderer; }
	TTF_Font* GetFont() { return m_pMenuFont; }

	// Inline function (1 line of code)
	void Quit() { m_IsPlaying = false; }
};

