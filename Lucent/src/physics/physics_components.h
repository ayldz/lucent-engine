#pragma once

#include <Lucent.h>
#include <box2d/box2d.h>

namespace Lucent {
	class RigidBody2D : public Component
	{
	private:
		b2Vec2 m_velocity;
		float m_angularDamping;
		float m_linearDamping;
		float m_mass;
		b2BodyType m_bodyType;
		float m_friction;
		float m_angularVelocity;
		float m_gravityScale;
		bool m_isSensor;
		bool m_fixedRotation;
		bool m_continuosCollision;
		b2Body m_body;

	public:
		//TODO: Add constructors

		void Update(float) override;

		void AddVelocity(b2Vec2 forceToAdd);
		void AddImpulse(b2Vec2 impulse);
		b2Vec2 GetVelocity();
	};

	class BoxCollider2D : public Component
	{
	private:
		b2Vec2 m_halfSize;
		b2Vec2 m_origin;
		b2Vec2 m_offset;

	public:
		//TODO: Add constructors

		b2Vec2 GetHalfSize() const;
		void SetHalfSize();

		b2Vec2 GetOffset() const;
		void SetOffset();

		b2Vec2 GetOrigin() const;
	};

	class CircleCollider2D : public Component
	{
	private:
		float m_radius;
		b2Vec2 m_origin;
		b2Vec2 m_offset;

	public:
		//TODO:: Add constructors

		float GetRadius() const;
		void SetRadius(float radius);

		b2Vec2 GetOffset() const;
		void SetOffset(b2Vec2 offset);

		b2Vec2 GetOrigin() const;
	};
}