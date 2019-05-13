#include "AnimatedCharacter.h"

#include <SDL_image.h>
#include <iostream>

AnimatedCharacter::AnimatedCharacter()
{
}


AnimatedCharacter::~AnimatedCharacter()
{
}

void AnimatedCharacter::Init(SDL_Renderer * Renderer)
{
	m_pRenderer = Renderer;
	Load_Test("Assets/TestAnim.png");
	
	m_offset = 26 / 2;
	characterCircle = new Circle(m_x + (int)m_offset, m_y + (int)m_offset, 15);
	m_collider.SetShape(characterCircle);
	m_CurrentDirection = EDirection::Down;
	ChangeAnimation(EPlayerAnimation::Down);
}

void AnimatedCharacter::Load_Test(const char * FilePath)
{
	m_pTexture = IMG_LoadTexture(m_pRenderer, "Assets/Link.png");

	Animation anim;

	// Move Down
	anim.m_Frames =
	{
		{ 205, 43, 16, 22, .15 },
		{227, 43, 16, 22, .15 },
		{248, 42, 16, 23, .15 },
		{270, 41, 16, 24, .15 },
		{293, 43, 16, 22, .15 },
		{315, 43, 16, 22, .15 },
		{337, 42, 16, 23, .15 },
		{357, 41, 16, 24, .15 }
	};

	m_Animations.emplace(EPlayerAnimation::Down, anim);

	// Move Left
	anim.m_Frames =
	{
		{ 14, 11, 16, 23, .15 },
		{39, 10, 16, 24, .15},
		{62, 10, 16, 24, .15},
		{84, 11, 17, 23, .15},
		{107, 11, 16, 23, .15},
		{132, 10, 16, 24, .15},
		{156, 10, 16, 24, .15},
		{178, 11, 16, 23, .15}
	};

	m_Animations.emplace(EPlayerAnimation::Left, anim);

	// Move Right
	anim.m_Frames = 
	{
		{ 200, 10, 16, 23, .15 },
		{221, 9, 16, 24, .15},
		{247, 9, 16, 24, .15},
		{269, 10, 17, 23, .15},
		{293, 10, 16, 23, .15},
		{317, 9, 16, 24, .15},
		{339, 9, 16, 24, .15},
		{360, 10, 16, 23, .15}
	};

	m_Animations.emplace(EPlayerAnimation::Right, anim);

	// Move Up
	anim.m_Frames = 
	{
		{ 14, 44, 16, 23, .15 },
		{36, 43, 16, 24, .15},
		{60, 45, 16, 22, .15},
		{84, 45, 16, 22, .15},
		{108, 43, 16, 23, .15},
		{130, 42, 16, 24, .15},
		{152, 44, 16, 22, .15},
		{175, 43, 16, 22, .15}
	};

	m_Animations.emplace(EPlayerAnimation::Up, anim);

	// Left Attack
	anim.m_Frames =
	{
		{7, 286, 16, 23, .15 },
		{30, 287, 23, 24, .15 },
		{58, 292, 29, 21, .15 },
		{97, 294, 31, 21, .15 },
		{140, 293, 28, 28, .15 },
		{183, 293, 23, 31, 99999 }
	};
	m_Animations.emplace(EPlayerAnimation::LAttack, anim);
	
	// Right Attack
	anim.m_Frames=
	{
		{219, 296, 16, 23, .15 },
		{247, 295, 23, 24, .15 },
		{279, 298, 29, 21, .15 },
		{308, 298, 30, 21, .15 },
		{340, 297, 28, 28, .15 },
		{374, 296, 23, 31, 99999 }
	};
	m_Animations.emplace(EPlayerAnimation::RAttack, anim);
	
	// Up Attack
	anim.m_Frames=
	{
		{182, 254, 23, 22, .15 },
		{213, 254, 23, 24, .15 },
		{243, 246, 20, 32, .15 },
		{278, 245, 20, 34, .15 },
		{309, 252, 29, 27, .15 },
		{346, 256, 32, 23, 99999 }
	};
	m_Animations.emplace(EPlayerAnimation::UAttack, anim);
	
	// Down Attack
	anim.m_Frames=
	{
		{19, 247, 20, 23, .15 },
		{47, 244, 21, 29, .15 },
		{75, 246, 20, 27, .15 },
		{105, 245, 23, 29, .15 },
		{136, 245, 32, 27, 99999 }
	};
	m_Animations.emplace(EPlayerAnimation::DAttack, anim);
	
	// Hit Left
	anim.m_Frames =
	{
		{285, 144, 19, 22, .15 },
		{306, 144, 21, 22, .15 },
		{331, 144, 22, 22, .15 }
	};
	m_Animations.emplace(EPlayerAnimation::HLeft, anim);
	
	// Hit Right
	anim.m_Frames =
	{
		{205, 144, 19, 22, .15 },
		{228, 144, 21, 22, .15 },
		{253, 144, 23, 22, .15 }
	};
	m_Animations.emplace(EPlayerAnimation::HRight, anim);
	
	// Hit Up
	anim.m_Frames =
	{
		{118, 145, 16, 20, .15 },
		{139, 145, 24, 20, .15 },
		{165, 145, 22, 20, .15 }
	};
	m_Animations.emplace(EPlayerAnimation::HUp, anim);
	
	// Hit Down
	anim.m_Frames =
	{
		{28, 146, 16, 20, .15 },
		{47, 146, 24, 20, .15 },
		{73, 145, 26, 21, .15 }
	};
	m_Animations.emplace(EPlayerAnimation::HDown, anim);
}

void AnimatedCharacter::Update(float DeltaSeconds)
{
	characterCircle->SetPosition(m_x + (int)m_offset, m_y + (int)m_offset);
	std::cout << "X: " << m_x << " Y: " << m_y << std::endl;
	MovementCalc(DeltaSeconds);
	m_TimeSpentInFrame += DeltaSeconds;
	Animation* curAnim = &m_Animations[m_CurrentAnimationName];

	if (m_TimeSpentInFrame >=
		curAnim->m_Frames[m_FrameIndex].m_Duration)
	{
		// Next frame
		m_FrameIndex++;
		m_TimeSpentInFrame = 0;

		if (m_FrameIndex >= curAnim->m_Frames.size())
		{
			m_FrameIndex = 0;
		}
	}
}

void AnimatedCharacter::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(m_pRenderer, m_pTexture,
		&m_Animations[m_CurrentAnimationName].m_Frames[m_FrameIndex].m_Rect, &m_DestRect);


	m_collider.DrawDebug(renderer);
}

void AnimatedCharacter::ChangeAnimation(EPlayerAnimation key)
{
	if (m_CurrentAnimationName != key)
	{
		m_FrameIndex = 0;
	}
	if (m_Animations.find(key) == m_Animations.end())
	{
		std::cout << "That animation does not exist" << std::endl;
		return;
	}
	m_CurrentAnimationName = key;
}

bool AnimatedCharacter::IsOverlapping(Collider * pOther)
{
	// Check which collision algorithm to use!
	if (m_collider.GetShape()->GetType() == EShapeType::Box &&
		pOther->GetShape()->GetType() == EShapeType::Box)
	{
		return m_collider.BoxOverlapsBox(m_collider.GetShape(), pOther->GetShape());
	}
	if (m_collider.GetShape()->GetType() == EShapeType::Circle &&
		pOther->GetShape()->GetType() == EShapeType::Circle)
	{
		return m_collider.CircleOverlapsCircle(m_collider.GetShape(), pOther->GetShape());
	}

	return false;
}

void AnimatedCharacter::Attack()
{
	if (m_CurrentDirection == EDirection::Right)
		ChangeAnimation(EPlayerAnimation::RAttack);
	else if (m_CurrentDirection == EDirection::Left)
		ChangeAnimation(EPlayerAnimation::LAttack);
	else if (m_CurrentDirection == EDirection::Up)
		ChangeAnimation(EPlayerAnimation::UAttack);
	else if (m_CurrentDirection == EDirection::Down)
		ChangeAnimation(EPlayerAnimation::DAttack);
}
