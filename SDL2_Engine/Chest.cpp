#include "Chest.h"

Chest::Chest(Renderer * _pRenderer, const char * _pFileName,
	Rect * _pRect, Rect* _pTriggerRect)
	: InteractiveEntity(_pRenderer, _pFileName, _pRect, _pTriggerRect)
{
}

Chest::~Chest()
{
}

void Chest::Render(Renderer * _pRenderer)
{
	InteractiveEntity::Render(_pRenderer);
}

void Chest::Interact()
{
	m_sourceX = 64;
}