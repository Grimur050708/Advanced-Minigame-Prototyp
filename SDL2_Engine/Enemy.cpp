#include "Enemy.h"
#include "Helper.h"
#include "Rect.h"
#include "Macros.h"

Enemy::Enemy(Renderer * _pRenderer, const char * _pFileName, Rect * _pRect,
	const char * _pHealthBarFileName)
	: Actor(_pRenderer, _pFileName, _pRect)
{
	m_pHealthBar = new TexturedEntity(_pRenderer, _pHealthBarFileName,
		new Rect(64, 8));

	m_pTag = ENEMY;
}

Enemy::~Enemy()
{
	delete m_pHealthBar;
}

void Enemy::Update(float _deltaTime)
{
	// update parent
	Actor::Update(_deltaTime);

	// get health bar rect
	Rect rect = *m_pHealthBar->GetRect();

	// set width rect
	rect.w = 64 * m_health / 100;

	// set x and y of rect
	rect.x = m_pRect->x;
	rect.y = m_pRect->y;

	// set rect of health bar
	m_pHealthBar->SetRect(&rect);
}

void Enemy::Render(Renderer * _pRenderer)
{
	// render health bar
	m_pHealthBar->Render(_pRenderer);

	// render parent
	Actor::Render(_pRenderer);
}

void Enemy::ChangeState()
{

}