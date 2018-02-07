#include "Player.h"
#include "Input.h"
#include "Rect.h"
#include "Physics.h"
#include "Scene.h"
#include "Bullet.h"
#include "Helper.h"
#include "Texture.h"

Player::Player(Renderer * _pRenderer, const char * _pFileName, Rect * _pRect)
	: Actor(_pRenderer, _pFileName, _pRect)
{
	m_pBulletTexture = new Texture(GetAssetPath("Texture/Bullet/T_Bullet.png", 5).c_str(), _pRenderer);
}

Player::~Player()
{
	delete m_pBulletTexture;
}

void Player::Update(float _deltaTime)
{
	// if not moveable return
	if (!m_isMoveable)
		return;

	// rotate player to 0
	if (Input::GetKey(SDL_SCANCODE_D))
		m_xMovement += 1;

	// rotate player to 90
	if (Input::GetKey(SDL_SCANCODE_S))
		m_yMovement += 1;

	// rotate player to 180
	if (Input::GetKey(SDL_SCANCODE_A))
		m_xMovement -= 1;

	// rotate player to 270
	if (Input::GetKey(SDL_SCANCODE_W))
		m_yMovement -= 1;

	// update rect
	Actor::Update(_deltaTime);

	// x direction
	int x = 0;

	// y direction
	int y = 0;

	if (m_angle == 0 || m_angle == 45 || m_angle == 315)
		x = 1;
	else if (m_angle == 135 || m_angle == 180 || m_angle == 225)
		x = -1;

	if (m_angle == 45 || m_angle == 90 || m_angle == 135)
		y = 1;
	else if (m_angle == 225 || m_angle == 270 || m_angle == 315)
		y = -1;

	// if space is pressed down spawn bullet
	if (Input::GetKeyDown(SDL_SCANCODE_SPACE))
	{
		// create bullet
 		Bullet* bullet = new Bullet(nullptr, nullptr,
			new Rect(m_pRect->x + x * UNIT,
				m_pRect->y + y * UNIT, 16, 16), x, y);

		// add to list
		m_pScene->AddMoveEntity(bullet);

		// set texture of bullet
		bullet->GetTexture()->SetSDLTexture(m_pBulletTexture->GetSDLTexture());
	}
}

void Player::Render(Renderer * _pRenderer)
{
	Actor::Render(_pRenderer);
}

void Player::CheckMoveable(std::list<TexturedEntity*> _pEntities, float _deltaTime)
{
	// rect after movement frame
	Rect* nextRect = new Rect(m_pRect->x, m_pRect->y,
		m_pRect->w, m_pRect->h);

	// save input
	int x = 0;
	int y = 0;

	// rotate player to 0
	if (Input::GetKey(SDL_SCANCODE_D))
		x = 1;

	// rotate player to 90
	if (Input::GetKey(SDL_SCANCODE_S))
		y = 1;

	// rotate player to 180
	if (Input::GetKey(SDL_SCANCODE_A))
		x = -1;

	// rotate player to 270
	if (Input::GetKey(SDL_SCANCODE_W))
		y = -1;

	// increase rect x and y
	nextRect->x += x * m_speed * _deltaTime;
	nextRect->y += y * m_speed * _deltaTime;

	// check entities
	for each (Entity* entity in _pEntities)
	{
		if (Physics::RectRectCollision(nextRect, entity->GetRect())
			&& (entity->GetColType() == ECollisionType::MOVE
			|| entity->GetColType() == ECollisionType::WALL))
		{
			m_isMoveable = false;
		}
		if (Physics::RectRectCollision(nextRect, entity->GetRect()) 
			&& entity->GetColType() == ECollisionType::TRIGGER)
		{
			entity->Trigger(this);
			// m_pScene->AddRemoveEntity(entity);
		}
	}
}