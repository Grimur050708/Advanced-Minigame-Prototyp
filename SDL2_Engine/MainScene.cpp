#include "MainScene.h"
#include "Renderer.h"
#include "TexturedEntity.h"
#include "Rect.h"
#include "Helper.h"
#include "Player.h"
#include "Text.h"
#include "Font.h"
#include "Color.h"
#include "Physics.h"
#include "FollowEntity.h"
#include "World.h"
#include "Time.h"
#include "Enemy.h"
#include "Soulstone.h"
#include "Chest.h"

MainScene::MainScene(Engine * _pEngine)
	: Scene(_pEngine)
{
	
}

MainScene::~MainScene()
{
}

void MainScene::Render(Renderer * _pRenderer)
{
	// set camera position before rendering anything
	_pRenderer->m_CameraX = m_pPlayer->GetRect()->x + m_pPlayer->GetRect()->w / 2;
	_pRenderer->m_CameraY = m_pPlayer->GetRect()->y + m_pPlayer->GetRect()->h / 2;

	// render world entities
	m_pWorld->RenderEntities(_pRenderer, m_pPlayer->GetRect()->x, m_pPlayer->GetRect()->y);
	
	// render every move entity
	for each(Entity* entity in m_pMoveEntities)
		entity->Render(_pRenderer);

	// render every text
	// important text after entities
	for each (Text* text in m_pTexts)
		text->Render(_pRenderer);

	// set string
	std::string fpsText = "FPS: ";
	fpsText.append(std::to_string(Time::GetFPS()));

	// set text to fpsText
	m_pFPS->SetText(fpsText.c_str());

	// load text
	m_pFPS->Load(_pRenderer);

	// render text
	m_pFPS->Render(_pRenderer);
}

void MainScene::Update(float _deltaTime)
{
	// update every move entity
	for each(Entity* entity in m_pMoveEntities)
		entity->Update(_deltaTime);

	// set player moveable
	m_pPlayer->SetMoveable(true);

	// check player collision
	m_pPlayer->CheckMoveable(m_pWorld->GetEntities(), _deltaTime);

	// check player collision with move entitues
	m_pPlayer->CheckMoveable(m_pMoveEntities, _deltaTime);

	// check collisions
	CheckCollision(_deltaTime);
}

void MainScene::Load(Renderer * _pRenderer)
{
	// create player
	m_pPlayer = new Player(_pRenderer, 
		GetAssetPath("Texture/Character/T_Character_Idle.png", 5).c_str(), 
		new Rect(Point::Zero(), new Point(64, 64)));

	// set speed
	m_pPlayer->SetSpeed(150);

	// set current scene of player
	m_pPlayer->SetScene(this);

	m_pMoveEntities.push_back(m_pPlayer);

	// create text
	m_pFPS = new Text(new Rect(100, 50), "FPS:",
		new Font(GetAssetPath("Texture/Font/T_Arial.ttf", 5).c_str(), 24),
		new Color());

	// load text
	m_pFPS->Load(_pRenderer);

	// create new world
	m_pWorld = new World(_pRenderer, GetAssetPath("Texture/World/T_Atlas.png", 5).c_str(),
		new Rect());

	// load world
	m_pWorld->LoadWorld(_pRenderer);

	// create enemy
	Enemy* enemy = new Enemy(_pRenderer,
		GetAssetPath("Texture/Character/T_Enemy_Idle.png", 5).c_str(),
		new Rect(new Point(128), Point::Unit()),
		GetAssetPath("Texture/Character/T_HealthBar.png", 5).c_str());

	// set speed
	enemy->SetSpeed(100);

	// set collision type
	enemy->SetColType(ECollisionType::MOVE);

	// add enemy to list
	m_pMoveEntities.push_back(enemy);

	// create enemy 2
	Enemy* enemy2 = new Enemy(_pRenderer,
		GetAssetPath("Texture/Character/T_Enemy_Idle.png", 5).c_str(),
		new Rect(256, 128, Point::Unit()),
		GetAssetPath("Texture/Character/T_HealthBar.png", 5).c_str());

	// set speed
	enemy2->SetSpeed(100);

	// set collision type
	enemy2->SetColType(ECollisionType::MOVE);

	// add enemy to list
	m_pMoveEntities.push_back(enemy2);

	// create soulstone
	Soulstone* soulstone = new Soulstone(_pRenderer,
		GetAssetPath("Texture/Items/T_Soulstone.png", 5).c_str(),
		new Rect(new Point(256 + 16), new Point(32)));

	// add soulstone to entity list
	m_pMoveEntities.push_back(soulstone);

	// create chest
	Chest* chest = new Chest(_pRenderer,
		GetAssetPath("Texture/Objects/T_Chest.png", 5).c_str(),
		new Rect(new Point(512), new Point(64)), this);

	// addchest to entity list
	m_pMoveEntities.push_back(chest);
	m_pMoveEntities.push_back((TexturedEntity*)chest->GetTrigger());

	// create chest
	Chest* chest2 = new Chest(_pRenderer,
		GetAssetPath("Texture/Objects/T_Chest.png", 5).c_str(),
		new Rect(new Point(512 - 128), new Point(64)), this);

	// addchest to entity list
	m_pMoveEntities.push_back(chest2);
	m_pMoveEntities.push_back((TexturedEntity*)chest2->GetTrigger());
}

void MainScene::Unload()
{
	// delete world
	delete m_pWorld;
}

void MainScene::CheckCollision(float _deltaTime)
{
	// check all move entities
	for each (TexturedEntity* entity in m_pMoveEntities)
	{
		// if bullet
		if (entity->GetColType() == ECollisionType::BULLET)
		{
			for each (TexturedEntity* moveEntity in m_pMoveEntities)
			{
				// if collision type none or bullet ignore collision
				if (moveEntity->GetColType() == ECollisionType::NONE ||
					moveEntity->GetColType() == ECollisionType::BULLET)
					continue;
				
				// check collision
				if (Physics::RectRectCollision(entity->GetRect(), moveEntity->GetRect()))
				{
					m_pEntitiesToRemove.push_back(entity);

					// if hitted move entity is enemy
					if (moveEntity->GetTag() == ENEMY)
					{
						// take damage
						((Enemy*)moveEntity)->TakeDamage(25);

						// if enemy health lower than 0 add to remove list
						if (((Enemy*)moveEntity)->GetHealth() <= 0)
							m_pEntitiesToRemove.push_back(moveEntity);
					}
				}
			}

			for each (Entity* moveEntity in m_pWorld->GetEntities())
			{
				// if collision type none or bullet ignore collision
				if (moveEntity->GetColType() == ECollisionType::NONE ||
					moveEntity->GetColType() == ECollisionType::BULLET)
					continue;

				// check collision
				if (Physics::RectRectCollision(entity->GetRect(), moveEntity->GetRect()))
				{
					m_pEntitiesToRemove.push_back(entity);
				}
			}

			// if bullet hits player
			if (Physics::RectRectCollision(entity->GetRect(), m_pPlayer->GetRect()))
				m_pEntitiesToRemove.push_back(entity);

			// if bullet is out of screen
			if (entity->GetRect()->x < m_pPlayer->GetRect()->x - 624 ||
				entity->GetRect()->x > m_pPlayer->GetRect()->x + 688 ||
				entity->GetRect()->y < m_pPlayer->GetRect()->y - 344 ||
				entity->GetRect()->y > m_pPlayer->GetRect()->y + 408) 
			{
				m_pEntitiesToRemove.push_back(entity);
			}
		}
	}

	// as long as there is an entity to remove
	// NO FOR EACH
	while (m_pEntitiesToRemove.size() > 0)
	{
		// get first entity
		Entity* entity = m_pEntitiesToRemove.front();

		// remove entity from entities to remove
		m_pEntitiesToRemove.remove(entity);

		// remove entity from move entities
		m_pMoveEntities.remove((TexturedEntity*)entity);

		// delete entity
		delete entity;
	}
}