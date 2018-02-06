#include "CircleCollider.h"

CircleCollider::CircleCollider(ECollisionLayer _layer, Point * _pPoint, int _radius)
{
	m_layer = _layer;
	m_pPosition = _pPoint;
	m_radius = _radius;
}

CircleCollider::~CircleCollider()
{
	delete m_pPosition;
}