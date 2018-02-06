#include "RectCollider.h"
#include "Rect.h"

RectCollider::RectCollider(ECollisionLayer _layer, Rect * _pRect)
{
	m_layer = _layer;
	m_pRect = _pRect;
}

RectCollider::RectCollider(ECollisionLayer _layer, Point * _pPoint, int _w, int _h)
{
	m_layer = _layer;
	m_pRect = new Rect(_pPoint, _w, _h);
}

RectCollider::~RectCollider()
{
	delete m_pRect;
}