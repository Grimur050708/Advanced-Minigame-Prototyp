// Nils Jungjohann

#include "TriggerEntity.h"
#include "Rect.h"
#include "InteractiveEntity.h"
#include "Input.h"
#include "Chest.h"

TriggerEntity::TriggerEntity(InteractiveEntity* _pInterEntity, Rect* _pRect)
	: TexturedEntity(nullptr, nullptr, _pRect)
{
	m_pInterEntity = _pInterEntity;

	m_colType = ECollisionType::TRIGGER;
}

void TriggerEntity::Update(float _deltaTime)
{
	if (m_lastTriggered && !m_nowTriggered)
		m_pInterEntity->HideTooltip();

	m_lastTriggered = m_nowTriggered;
	m_nowTriggered = false;
	m_pInterEntity->SetTooltipDisplayed(false);
}

void TriggerEntity::Trigger(Player * _pPlayer)
{
	if (m_pInterEntity->GetTag() == CHEST &&
		!Chest::GetTooltipDisplayed() &&
		!m_pInterEntity->GetTooltipDisplayed())
	{
		m_pInterEntity->ShowTooltip();
		m_pInterEntity->SetTooltipDisplayed(true);
	}

	if (Input::GetKeyDown(SDL_SCANCODE_E))
		m_pInterEntity->Interact();

	m_nowTriggered = true;
}