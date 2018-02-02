#include "Bullet.h"

Bullet::Bullet(Renderer * _pRenderer, const char * _pFileName,
	Rect * _pRect, int _xDirection, int _yDirection)
	: Actor(_pRenderer, _pFileName, _pRect)
{
	m_xDIrection = _xDirection;
	m_yDirection = _yDirection;

	// set speed
	m_speed = 500;

	m_colType = ECollisionType::BULLET;

	// calculate angle
	CalculateAngle();
}

void Bullet::Update(float _deltaTime)
{
	// update movement
	m_xMovement = m_xDIrection;
	m_yMovement = m_yDirection;

	// update parent class
	Actor::Update(_deltaTime);
}

void Bullet::Render(Renderer * _pRenderer)
{
	// render parent class
	Actor::Render(_pRenderer);
}