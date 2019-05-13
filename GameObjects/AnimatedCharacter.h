#pragma once

#include <SDL.h>
#include <vector>
#include <string>
#include <map>
#include "Character.h"
#include "GameStd.h"

#include "Box.h"
#include "Circle.h"
#include "Collider.h"

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


class AnimatedCharacter : public Character
{
private:


	//std::vector<Animation> m_Animations;
	SDL_Texture* m_pTexture;
	SDL_Renderer* m_pRenderer;

	std::map<EPlayerAnimation, Animation> m_Animations;
	EPlayerAnimation m_CurrentAnimationName;
	EDirection m_CurrentDirection;

	//int m_AnimationIndex = 0;
	int m_FrameIndex = 0;
	double m_TimeSpentInFrame = 0;
	float m_offset;

	Circle* characterCircle;
	Box* characterBox;
	Collider m_collider;

public:
	AnimatedCharacter();
	~AnimatedCharacter();

	void Init(SDL_Renderer* Renderer);
	void Load_Test(const char* FilePath);
	void Update(float DeltaSeconds);
	void Draw(SDL_Renderer* renderer);
	void ChangeAnimation(EPlayerAnimation key);
	bool IsOverlapping(Collider* pOther);
	void Attack();

	void SetCurrentDirection(EDirection key) { m_CurrentDirection = key; };

	float GetX() { return m_x; };
	float Gety() { return m_y; };

};

