#include "Scorable.h"

Scorable::Scorable(int _pts) : m_pts(_pts), m_mustGivePts(false) {}

int Scorable::getPts() {
	return m_pts;
}

bool Scorable::mustGivePts() {
	return m_mustGivePts;
}

void Scorable::ptsMustBeGiven() {
	m_mustGivePts = true;
}

void Scorable::ptsAreGiven() {
	m_mustGivePts = false;
}