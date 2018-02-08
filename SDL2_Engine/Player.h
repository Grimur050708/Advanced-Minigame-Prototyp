#pragma once
#include "Actor.h"
#include "Macros.h"
#include <list>

class Scene;

class Player :
	public Actor
{
public:
	// constructor
	Player(Renderer* _pRenderer, const char* _pFileName, Rect* _pRect);

	// destructor
	~Player();
	
	// update every frame
	virtual void Update(float _deltaTime) override;

	// render every frame
	virtual void Render(Renderer* _pRenderer) override;

	// check collision
	void CheckMoveable(std::list<TexturedEntity*> _pEntities, float _deltaTime);

	// set moveable
	inline void SetMoveable(bool _moveable) { m_isMoveable = _moveable; };

	// set scene
	inline void SetScene(Scene* _pScene) { m_pScene = _pScene; };

	// get scene
	inline Scene* GetScene() { return m_pScene; };

private:
	// is moveable
	bool m_isMoveable = true;

	// bullet texture
	Texture* m_pBulletTexture;

	// current scene
	Scene* m_pScene;
};