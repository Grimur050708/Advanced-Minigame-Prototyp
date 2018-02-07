#pragma once
#include "InteractiveEntity.h"

class Chest :
	public InteractiveEntity
{
public:
	// constructor
	Chest(Renderer* _pRenderer, const char* _pFileName,
		Rect* _pRect, Rect* _pTriggerRect);

	// destructor
	~Chest();

	// render every frame
	void Render(Renderer* _pRenderer) override;

	void Interact() override;
};