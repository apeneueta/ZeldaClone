#pragma once

#include <SDL_rect.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

class Button
{
private:
	SDL_Rect m_HitBox;
	SDL_Rect m_TextBox; // For Homework
	SDL_Surface* m_pTextSurface;
	SDL_Surface* m_pTextBackgroundSurface;
	SDL_Texture* m_pTextTexture;
	SDL_Texture* m_pHoveredBackground;
	SDL_Texture* m_pNormalBackground;
	SDL_Renderer* m_pRenderer;
	TTF_Font* m_pFont;

	std::string m_Text;
	bool m_IsMouseOver;
	bool m_ClickedThisFrame;

public:
	bool Init(SDL_Renderer* pRenderer, TTF_Font* pFont, std::string Text, int locationX, int locationY);
	void Cleanup();
	~Button();

	void Draw();
	void Click(SDL_Point Point);
	void CheckMouseOver(SDL_Point Point);
	bool IsPointInButton(SDL_Point Point);

	bool ClickedThisFrame() { return m_ClickedThisFrame; }
};

