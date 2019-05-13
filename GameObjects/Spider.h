#pragma once
#include "Entity.h"
class Spider :
	public Entity
{
private:
	SDL_Rect m_Center;
public:
	Spider(SDL_Renderer* pRenderer, int x, int y);
	~Spider();

	// Inherited via Entity
	virtual void Init() override;
	virtual void Update(float DeltaSeconds) override;
	virtual void Draw(SDL_Renderer * pRenderer) override;

	void CalculateCenter(SDL_Rect rect);
	Collider* GetCollider() { return &m_collider; };

	void SetRect(int x, int y);
};

