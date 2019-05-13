#pragma once
#include <vector>
#include <SDL.h>
// This is where we can place all of our common
// - Typedefs
// - Macros
// - Enums
// - Defines
// - Constants
// - ?Globals?

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
#define CIRCLE_SEGMENTS 25

enum class EGameState
{
	Menu = 0,
	Play,
	Credits
};

// Enumeration: use for human-friendly representation of numbers
enum class EShapeType
{
	Box,
	Circle
};

enum class EDirection
{
	Up,
	Down,
	Left,
	Right
};

enum class EPlayerAnimation
{
	Right,
	Left,
	Up,
	Down,
	UAttack,
	DAttack,
	LAttack,
	RAttack,
	HRight,
	HLeft,
	HUp,
	HDown
};

struct Point
{
	int x;
	int y;
};

struct Frame
{
	SDL_Rect m_Rect;
	double m_Duration;
};

struct Animation
{
	std::vector<Frame> m_Frames;
	bool m_IsLooping;
};