#pragma once

enum ECollisionLayer
{
	MOVE,
	BULLET,
	WALL,
	NONE
};

class Collider
{
public:
	// set collision layer
	inline void SetCollisionLayer(ECollisionLayer _layer) { m_layer = _layer; };

	// get collision layer
	inline ECollisionLayer GetCollisionLayer() { return m_layer; };

protected:
	// collision layer
	ECollisionLayer m_layer = ECollisionLayer::MOVE;
};