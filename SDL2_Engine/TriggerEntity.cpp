#include "TriggerEntity.h"
#include "Rect.h"
#include "InteractiveEntity.h"
#include "Input.h"

TriggerEntity::TriggerEntity(InteractiveEntity* _pInterEntity, Rect* _pRect)
	: TexturedEntity(nullptr, nullptr, _pRect)
{
	m_pInterEntity = _pInterEntity;

	m_colType = ECollisionType::TRIGGER;
}

TriggerEntity::~TriggerEntity()
{
	delete m_pRect;
}

void TriggerEntity::Update(float _deltaTime)
{
}

void TriggerEntity::Render(Renderer * _pRenderer)
{
}

void TriggerEntity::Trigger(Player * _pPlayer)
{
	if (Input::GetKeyDown(SDL_SCANCODE_E))
		m_pInterEntity->Interact();
}