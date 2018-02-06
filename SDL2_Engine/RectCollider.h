#pragma once
#include "Collider.h"

class Rect;
struct Point;

class RectCollider :
	public Collider
{
public:
	// constructor
	RectCollider(ECollisionLayer _layer, Rect* _pRect);
	RectCollider(ECollisionLayer _layer, Point* _pPoint, int _w, int _h);

	// destructor
	~RectCollider();

	// position
	Rect* m_pRect;
};