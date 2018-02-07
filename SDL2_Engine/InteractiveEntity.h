#pragma once
#include "TexturedEntity.h"

class TriggerEntity;

class InteractiveEntity :
	public TexturedEntity
{
public:
	// constructor
	InteractiveEntity(Renderer* _pRenderer, const char* _pFileName,
		Rect* _pRect, Rect* _pTriggerRect);

	// destructor
	~InteractiveEntity();

	// render every frame
	virtual void Render(Renderer* _pRenderer) override;

	// interact
	virtual void Interact() = 0;

	// get trigger
	TriggerEntity* GetTrigger() { return m_pTrigger; };

protected:
	// sourcerect x
	int m_sourceX;

	// trigger
	TriggerEntity* m_pTrigger;
};