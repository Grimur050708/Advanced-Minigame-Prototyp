// Nils Jungjohann

#include "Chest.h"
#include "Macros.h"
#include "Scene.h"
#include "TriggerEntity.h"
#include "Rect.h"

bool Chest::m_isDisplayed = false;

Chest::Chest(Renderer * _pRenderer, const char * _pFileName,
	Rect * _pRect, Scene* _pScene)
	: InteractiveEntity(_pRenderer, _pFileName, _pRect, _pScene)
{
	Rect* rect = new Rect(m_pRect->x + 16, m_pRect->y + 64, 32, 8);

	m_pTrigger = new TriggerEntity(this, rect);

	m_pTag = CHEST;
}

void Chest::Render(Renderer * _pRenderer)
{
	InteractiveEntity::Render(_pRenderer);
}

void Chest::Interact()
{
	m_sourceX = 64;

	m_pScene->RemoveMoveEntity(m_pTooltip);

	Chest::SetTooltipDisplayed(true);
}