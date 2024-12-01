#ifndef IATTACKER_H__
#define IATTACKER_H__

#include "Alive.h"

class IAttacker {

public:
	virtual void attack(Alive* _target) = 0;
};

#endif

