#include "Spider.h"



Spider::Spider(SDL_Renderer* pRenderer, int x, int y)
{
	m_pRenderer = pRenderer;

	m_pTexture = IMG_LoadTexture(m_pRenderer, "Assets/ZeldaEnemies.png");
	m_x = x;
	m_y = y;

	//m_SourceRect = SDL_Rect{ 205, 43, 16, 22 }; // Draw the whole texture
	m_DestRect = SDL_Rect{ (int)m_x, (int)m_y, 32, 32 };
	
	CalculateCenter(m_DestRect);

	characterCircle = new Circle(m_Center.x, m_Center.y, 15);
	m_collider.SetShape(characterCircle);

	// Spider
	m_Animation.m_Frames =
	{
		{224, 101, 16, 12, .15},
		{243, 98, 16, 15, .15}
	};

}


Spider::~Spider()
{
}

void Spider::Init()
{
}

void Spider::Update(float DeltaSeconds)
{
	m_TimeSpentInFrame += DeltaSeconds;

	if (m_TimeSpentInFrame >=
		m_Animation.m_Frames[m_FrameIndex].m_Duration)
	{
		// Next frame
		m_FrameIndex++;
		m_TimeSpentInFrame = 0;

		if (m_FrameIndex >= m_Animation.m_Frames.size())
		{
			m_FrameIndex = 0;
		}

	}

	CalculateCenter(m_DestRect);
	characterCircle->SetPosition(&m_Center);
	m_x = m_DestRect.x;
	m_y = m_DestRect.y;
}

void Spider::Draw(SDL_Renderer * pRenderer)
{
	SDL_RenderCopy(m_pRenderer, m_pTexture,
		&m_Animation.m_Frames[m_FrameIndex].m_Rect, &m_DestRect);

	m_collider.DrawDebug(pRenderer);
}

void Spider::CalculateCenter(SDL_Rect rect)
{
	m_Center.x = rect.x + 15;
	m_Center.y = rect.y + 15;
	m_Center.w = rect.w;
	m_Center.h = rect.h;
};


void Spider::SetRect(int x, int y)
{
	m_DestRect.x += x;
	m_DestRect.y += y;
}
