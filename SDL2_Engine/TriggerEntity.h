#pragma once
#include "TexturedEntity.h"

class InteractiveEntity;

class TriggerEntity :
	public TexturedEntity
{
public:
	// constructor
	TriggerEntity(InteractiveEntity* _pInterEntity, Rect* _pRect);

	// destructor
	~TriggerEntity();

	// update every frame
	virtual void Update(float _deltaTime) override;

	// render every frame
	virtual void Render(Renderer* _pRenderer) override;

	// trigger
	virtual void Trigger(Player* _pPlayer) override;

protected:
	// Interactive Entity
	InteractiveEntity* m_pInterEntity;
};