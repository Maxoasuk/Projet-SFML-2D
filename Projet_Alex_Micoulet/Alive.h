#ifndef ALIVE_H__
#define ALIVE_H__

class Alive {
	float m_maxLife;
	float m_currentLife;
	float m_invincibilityFrame;
	float m_currentInvincibility;

public:
	Alive(float _life, float m_invincibilityFrame);
	virtual float getMaxLife();
	virtual float getCurrentLife();
	void decreaseInvincibilityFrame(float _time);
	virtual void takeDamage(float _dmg);
};

#endif
