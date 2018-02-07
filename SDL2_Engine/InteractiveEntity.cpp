#include "InteractiveEntity.h"
#include "Renderer.h"
#include "Point.h"
#include "Rect.h"
#include "TriggerEntity.h"

InteractiveEntity::InteractiveEntity(Renderer * _pRenderer, const char * _pFileName,
	Rect * _pRect, Rect* _pTriggerRect)
	: TexturedEntity(_pRenderer, _pFileName, _pRect)
{
	m_pTrigger = new TriggerEntity(this, _pTriggerRect);

	m_colType = ECollisionType::WALL;
}

InteractiveEntity::~InteractiveEntity()
{
	delete m_pTrigger;
}

void InteractiveEntity::Render(Renderer * _pRenderer)
{
	// render texture
	_pRenderer->RenderTexture(m_pTexture, m_pRect,
		new Rect(m_sourceX, 0, Point::Unit()), m_angle, true);
}