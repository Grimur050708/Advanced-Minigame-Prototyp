#pragma once
#include "Collider.h"

struct Point;

class CircleCollider :
	public Collider
{
public:
	// constructor
	CircleCollider(ECollisionLayer _layer, Point* _pPoint, int _radius);

	// destructor
	~CircleCollider();

	// position
	Point* m_pPosition;

	// radius
	int m_radius;
};