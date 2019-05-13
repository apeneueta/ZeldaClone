#include "Character.h"

#include <SDL_image.h>
#include <iostream>

#include "GameStd.h"

Character::Character()
{
	m_pTexture = IMG_LoadTexture(m_pRenderer, "Assets/TestAnim.png");

	m_size = 100;
	m_x =(WINDOW_WIDTH / 2) - 16; // 52 is the character width
	m_y =(WINDOW_HEIGHT / 2) - 24; // 76 is the character height
	m_angle = 0;
	//m_facingRight = true;

	m_movingUp = false;
	m_movingDown = false;
	m_movingLeft = false;
	m_movingRight = false;
	m_moveSpeed = 100.0f;
	m_SourceRect = SDL_Rect{ 205, 43, 16, 22 }; // Draw the whole texture
	m_DestRect = SDL_Rect{ (int)m_x, (int)m_y, 32, 32 };
	m_Center = SDL_Point{ (m_DestRect.w / 2),(m_DestRect.h / 2) };
}


Character::~Character()
{
	SDL_DestroyTexture(m_pTexture);
	SDL_FreeSurface(m_pSurface);
}

void Character::Init(SDL_Renderer* renderer)
{
	//std::cout << "Character Init" << std::endl;
	m_pSurface = SDL_LoadBMP("Assets/Test_Mario.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(renderer, m_pSurface);


	////m_Terra.Init(renderer);
	//m_pTexture = IMG_LoadTexture(renderer, "Assets/TestAnim.png");
	/*m_size = 100;
	m_x = m_y = 0;
	m_angle = 0;
	m_facingRight = true;*/
	//m_movingUp = false;
	//m_movingDown = false;
	//m_movingLeft = false;
	//m_movingRight = false;
	//m_moveSpeed = 100.0f;


	////[Hack] SourceRect
	m_SourceRect = SDL_Rect{ 0, 0, m_pSurface->w, m_pSurface->h }; // Draw the whole texture
	//m_SourceRect = SDL_Rect{ 0, 0, 52, 76 }; // Draw the whole texture
	m_DestRect = SDL_Rect{ (int)m_x, (int)m_y, 100, 100 };
	m_Center = SDL_Point{ (m_DestRect.w / 2),(m_DestRect.h / 2) };

	//m_Center = SDL_Point{ m_DestRect.x + (m_DestRect.w / 2), (int)(m_y + (m_size / 2.0f)) };
}

void Character::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, m_pTexture, &m_SourceRect, &m_DestRect, m_angle, &m_Center, SDL_FLIP_NONE);	
}

void Character::Update(float deltaTime)
{
	MovementCalc(deltaTime);

}

void Character::Move(float deltaX, float deltaY)
{
	m_x += deltaX;
	m_y += deltaY;
}

void Character::Rotate(float deltaDegrees)
{
	m_angle += deltaDegrees;
}

void Character::Scale(float scaleAmount)
{
	m_size *= scaleAmount;
	m_DestRect.w = (int)m_size;
	m_DestRect.h = (int)m_size;

	m_Center = SDL_Point{ m_DestRect.w / 2, m_DestRect.h / 2 };
}

void Character::MovementCalc(float deltaTime)
{
	if (m_movePlayer)
	{
		if (m_movingRight)
		{
			if(m_x < WINDOW_WIDTH - 64)
				Move(m_moveSpeed * deltaTime, 0.0f);
		}
		if (m_movingLeft)
		{
			if(m_x > 32)
				Move(-(m_moveSpeed * deltaTime), 0.0f);
		}
		if (m_movingUp)
		{
			if(m_y > 32)
				Move(0.0f, -(m_moveSpeed * deltaTime));
		}
		if (m_movingDown)
		{
			if(m_y < WINDOW_HEIGHT - 64)
			Move(0.0f, m_moveSpeed * deltaTime);
		}

		m_movePlayer = false;
	}
	
	m_DestRect.x = (int)m_x;
	m_DestRect.y = (int)m_y;
}
