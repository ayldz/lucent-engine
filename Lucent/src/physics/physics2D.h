#pragma once

#include <box2d/b2_body.h>
#include <box2d/b2_world.h>

#include "contact_listener.h"

class PhysicsWorld2D
{
private:
	b2Vec2 m_gravity = b2Vec2(0.0f, -9.8f);
	b2World *m_world = new b2World(m_gravity);

	float m_physicsTime;
	float physicsTimeStep;

	PhysicsWorld2D()
	{
		m_world->SetContactListener(new LucentContactListener());
	}
};