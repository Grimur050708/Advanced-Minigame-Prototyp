// Nils Jungjohann

#include "Pickup.h"
#include "Scene.h"
#include "Player.h"

Pickup::Pickup(Renderer * _pRenderer, const char * _pFileName, Rect * _pRect)
	: TexturedEntity(_pRenderer, _pFileName, _pRect)
{
	m_colType = ECollisionType::TRIGGER;
}

Pickup::~Pickup()
{
}

void Pickup::Render(Renderer * _pRenderer)
{
	TexturedEntity::Render(_pRenderer);
}

void Pickup::Trigger(Player * _pPlayer)
{
	_pPlayer->GetScene()->AddRemoveEntity(this);
}