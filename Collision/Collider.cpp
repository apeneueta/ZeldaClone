#include "Collider.h"

#include "Box.h"
#include "Circle.h"

bool Collider::BoxOverlapsBox(Shape * pBoxA, Shape * pBoxB)
{
	// First, convert Shapes to Boxes
	// Casting - Convert one type to another (Static & Dynamic)
	// static -> Use this when you are sure of the type
	// dynamic -> use when you are not sure of the type

	Box* A = static_cast<Box*>(pBoxA);
	Box* B = static_cast<Box*>(pBoxB);

	Point AMin = A->GetMin();
	Point AMax = A->GetMax();
	Point BMin = B->GetMin();
	Point BMax = B->GetMax();

	bool BIsToRight = (BMin.x > AMax.x);
	bool BIsBelow = (BMin.y > AMax.y);
	bool BIsToLeft = (BMax.x < AMin.x);
	bool BIsAbove = (BMax.y < AMin.y);

	// If all are false, they are overlapping (return true)
	// if any are true, they are not overlapping

	if (BIsToRight || BIsToLeft || BIsAbove || BIsBelow)
	{
		return false;
	}

	return true;

}

bool Collider::CircleOverlapsCircle(Shape* pCircleA, Shape* pCircleB)
{
	Circle* A = static_cast<Circle*>(pCircleA);
	Circle* B = static_cast<Circle*>(pCircleB);

	// Calculate the distance between the two circles
	Point APos = A->GetPosition();
	Point BPos = B->GetPosition();

	int DeltaX = APos.x - BPos.x;
	int DeltaY = APos.y - BPos.y;
	float DistanceSq = (DeltaX * DeltaX) + (DeltaY * DeltaY);

	//if (DistanceSq < A->GetRadiusSq() + B->GetRadiusSq())
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}

	// 45 * 45 + 20 * 20 != 65 * 65
	int TotalRadius = A->GetRadius() + B->GetRadius();
	return (DistanceSq < TotalRadius * TotalRadius);
}

Collider::Collider()
{
}


Collider::~Collider()
{
	delete m_pShape;
}

bool Collider::IsOverlapping(Collider * pOther)
{
	// Check which collision algorithm to use!
	if (m_pShape->GetType() == EShapeType::Box &&
		pOther->m_pShape->GetType() == EShapeType::Box)
	{
		return BoxOverlapsBox(m_pShape, pOther->m_pShape);
	}
	else if (m_pShape->GetType() == EShapeType::Circle &&
		pOther->m_pShape->GetType() == EShapeType::Circle)
	{
		return CircleOverlapsCircle(m_pShape, pOther->m_pShape);
	}
	return false;
}

void Collider::SetShape(Shape * pShape)
{
	if (m_pShape)
	{
		delete m_pShape;
	}

	m_pShape = pShape;
}