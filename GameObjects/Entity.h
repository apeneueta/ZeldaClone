#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
//#include <map>
#include "GameStd.h"
#include "Collider.h"
#include "Circle.h"

//struct Frame
//{
//	SDL_Rect m_Rect;
//	double m_Duration;
//};
//
//struct Animation
//{
//	std::vector<Frame> m_Frames;
//	bool m_IsLooping;
//};

class Entity
{
protected:
	SDL_Renderer* m_pRenderer;
	SDL_Surface* m_pSurface;
	SDL_Texture* m_pTexture;

	SDL_Rect m_SourceRect;
	SDL_Rect m_DestRect;

	/*std::map<EPlayerAnimation, Animation> m_Animations;
	EPlayerAnimation m_CurrentAnimationName;
	EDirection m_CurrentDirection;*/

	//int m_AnimationIndex = 0;
	Animation m_Animation;
	int m_FrameIndex = 0;
	double m_TimeSpentInFrame = 0;

	Circle* characterCircle;
	Collider m_collider;

	float m_x;
	float m_y;

public:
	Entity();
	virtual ~Entity();

	virtual void Init() = 0;
	virtual void Update(float DeltaSeconds) = 0;
	virtual void Draw(SDL_Renderer* pRenderer) = 0;

};

