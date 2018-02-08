// Nils Jungjohann

#pragma once
#include "Pickup.h"

class Soulstone :
	public Pickup
{
public:
	// constructor
	Soulstone(Renderer* _pRenderer, const char* _pFileName, Rect* _pRect);

	// destructor
	~Soulstone();

	// render every frame
	void Render(Renderer* _pRenderer) override;

	// trigger
	void Trigger(Player* _pPlayer) override;
};