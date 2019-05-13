#pragma once

// Try not to include in headers if you can help it
#include <SDL.h>
//#include "AnimatedCharacter.h"

class Character
{
protected:
	SDL_Renderer* m_pRenderer;
	SDL_Surface* m_pSurface;
	SDL_Texture* m_pTexture;

	SDL_Rect m_SourceRect;
	SDL_Rect m_DestRect;

	SDL_Point m_Center;
	float m_x;
	float m_y;
	float m_size;
	float m_angle;
	bool m_facingRight;
	bool m_movePlayer = false;

	//AnimatedCharacter m_Terra;
	bool m_movingUp;
	bool m_movingDown;
	bool m_movingLeft;
	bool m_movingRight;
	float m_moveSpeed;
private:
	void Move(float deltaX, float deltaY);

public:
	Character();
	~Character();

	void Init(SDL_Renderer* renderer);
	void Draw(SDL_Renderer* renderer);
	void Update(float deltaTime);
	void Rotate(float deltaDegrees);
	void Scale(float scaleAmount);

	void SetMoveRight(bool set) { m_movingRight = set; };
	void SetMoveLeft(bool set) { m_movingLeft = set; };
	void SetMoveUp(bool set) { m_movingUp = set; };
	void SetMoveDown(bool set) { m_movingDown = set; };
	void SetMovePlayer(bool set) { m_movePlayer = set; };
	bool GetMovePlayer() { return m_movePlayer; };
	void MovementCalc(float deltaTime);

};