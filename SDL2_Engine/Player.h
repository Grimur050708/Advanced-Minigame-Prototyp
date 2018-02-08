#pragma once
#include "Actor.h"
#include "Macros.h"
#include "Engine.h"
#include <list>

class Scene;
class Sound;

#define PLAYER_WIDTH_HEIGHT 64

class Player : public Actor
{
public:
	// constructor
	Player(Renderer* _pRenderer, const char* _pFileName, Rect* _pRect, 
		const char* _pFileHealthBar, const char* _pRunBar);

	// destructor
	~Player();
	
	// update every frame
	virtual void Update(float _deltaTime) override;

	// render every frame
	virtual void Render(Renderer* _pRenderer) override;

	// check collision
	void CheckMoveable(std::list<TexturedEntity*> _pEntities, float _deltaTime);

	// set moveable
	inline void SetMoveable(bool _moveable) 
		{ m_isMoveable = _moveable; };

	// get current scene
	inline Scene* GetCurrentScene() { return m_pScene; };

	// set current scene
	inline void SetCurrentScene(Scene* _pScene) { m_pScene = _pScene; };

	// get bullet texture
	inline Texture* GetBulletTexture() { return m_pBulletTexture; };

	// take damage
	inline void TakeDamage(int _damage) 
	{
		// decrease health
		m_health -= _damage;
	};

	// increase health
	inline void IncreaseHealth(int _health)
	{
		m_health += _health;
		if (m_health > 100)
			m_health = 100;
	}

	// get health
	inline int GetHealth() { return m_health; };

	// get sound
	inline Sound* GetShotSound() { return m_pShotSound; };

private:
	// is moveable
	bool m_isMoveable = true;

	// player hits
	bool m_playerHits = false;

	// health
	int m_health = 100;

	// run value
	float m_run = 100.0f;

	// bullet texture
	Texture* m_pBulletTexture;

	// healthbar textured entity
	TexturedEntity* m_pHealthBar;

	// runBar textured entity
	TexturedEntity* m_pRunBar;

	// shot sound
	Sound* m_pShotSound;

	// current scene
	Scene* m_pScene;
};