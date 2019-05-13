#include "Button.h"

// [TODO]: Delete me!
#include <iostream>

bool Button::Init(SDL_Renderer* pRenderer, TTF_Font* pFont,
	std::string Text, int locationX, int locationY)
{
	m_pRenderer = pRenderer;
	m_pFont = pFont;
	m_Text = Text;
	m_pTextSurface = TTF_RenderText_Blended(pFont, Text.c_str(),
		SDL_Color{ 255, 255, 255, 255 });
	m_pTextTexture = SDL_CreateTextureFromSurface(pRenderer,
		m_pTextSurface);

	// Calculate the hit box?
	m_HitBox = { locationX, locationY, m_pTextSurface->w, m_pTextSurface->h };

	SDL_Surface* TempSurface = SDL_CreateRGBSurface(0, m_HitBox.w,
		m_HitBox.h, 32, 0, 0, 0, 0);
	SDL_FillRect(TempSurface, nullptr,
		SDL_MapRGB(TempSurface->format, 30, 30, 30));
	m_pNormalBackground = SDL_CreateTextureFromSurface(m_pRenderer,
		TempSurface);

	SDL_FillRect(TempSurface, nullptr, SDL_MapRGB(
		TempSurface->format, 30, 190, 30));
	m_pHoveredBackground = SDL_CreateTextureFromSurface(
		m_pRenderer, TempSurface);

	SDL_FreeSurface(TempSurface);

	return true;
}

void Button::Cleanup()
{
	//@Note: make sure to free the surface
	SDL_DestroyTexture(m_pHoveredBackground);
	SDL_DestroyTexture(m_pNormalBackground);
	SDL_DestroyTexture(m_pTextTexture);
	SDL_FreeSurface(m_pTextSurface);
	//SDL_FreeSurface(m_pTextBackgroundSurface);
}

Button::~Button()
{
	//Cleanup();
}

void Button::Draw()
{
	SDL_Rect Src = { 0, 0, m_HitBox.w, m_HitBox.h };

	if (m_IsMouseOver)
	{
		SDL_RenderCopy(m_pRenderer, m_pHoveredBackground,
			&Src, &m_HitBox);
	}
	else
	{
		SDL_RenderCopy(m_pRenderer, m_pNormalBackground,
			&Src, &m_HitBox);
	}

	SDL_RenderDrawRect(m_pRenderer, &m_HitBox);

	SDL_RenderCopy(m_pRenderer, m_pTextTexture, &Src, &m_HitBox);

	// At the end of the draw, we know that we can set ClickedThisFrame to false
	m_ClickedThisFrame = false;
}

void Button::Click(SDL_Point Point)
{
	// Poll Event
	// Handle Events
	// Update
	// Draw

	// Point in Rect Test!
	// [TODO]: This could live somewhere else
	if (IsPointInButton(Point))
	{
		// [TEST]!
		std::cout << "Clicked!" << std::endl;
		m_ClickedThisFrame = true;
	}
}

void Button::CheckMouseOver(SDL_Point Point)
{
	m_IsMouseOver = IsPointInButton(Point);
}

bool Button::IsPointInButton(SDL_Point Point)
{
	return (Point.x > m_HitBox.x &&
		Point.x < m_HitBox.x + m_HitBox.w &&
		Point.y > m_HitBox.y &&
		Point.y < m_HitBox.y + m_HitBox.h);
}
