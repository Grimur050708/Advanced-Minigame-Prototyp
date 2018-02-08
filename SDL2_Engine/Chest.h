// Nils Jungjohann

#pragma once
#include "InteractiveEntity.h"

class Chest :
	public InteractiveEntity
{
public:
	// constructor
	Chest(Renderer* _pRenderer, const char* _pFileName,
		Rect* _pRect, Scene* _pScene);

	// render every frame
	void Render(Renderer* _pRenderer) override;

	// interact
	void Interact() override;

	// get tooltip displayed
	static bool GetTooltipDisplayed() { return m_isDisplayed; };

	// set tooltip displayed
	static void SetTooltipDisplayed(bool _isDisplayed) { m_isDisplayed = _isDisplayed; };

	// is tooltip already displayed for chests
	static bool m_isDisplayed;
};