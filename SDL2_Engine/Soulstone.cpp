// Nils Jungjohann

#include "Soulstone.h"
#include "Player.h"

Soulstone::Soulstone(Renderer * _pRenderer, const char * _pFileName, Rect * _pRect)
	: Pickup(_pRenderer, _pFileName, _pRect)
{
}

Soulstone::~Soulstone()
{
}

void Soulstone::Render(Renderer * _pRenderer)
{
	Pickup::Render(_pRenderer);
}

void Soulstone::Trigger(Player* _pPlayer)
{
	_pPlayer->SetSpeed(_pPlayer->GetSpeed() * 2);

	Pickup::Trigger(_pPlayer);
}