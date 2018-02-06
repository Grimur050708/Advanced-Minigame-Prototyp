#pragma once
#include "TexturedEntity.h"

class Pickup
	: public TexturedEntity
{
public:
	// constructor
	Pickup(Renderer* _pRenderer, const char* _pFileName, Rect* _pRect);

	// destructor
	~Pickup();

	// render every frame
	virtual void Render(Renderer* _pRenderer) override;

	virtual void Trigger(Player* _pPlayer) override;
};