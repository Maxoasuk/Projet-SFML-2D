#ifndef SCORABLE_H__
#define SCORABLE_H__

class Scorable {
	int m_pts;
	bool m_mustGivePts;

public:
	Scorable(int _pts);
	int getPts();
	bool mustGivePts();
	void ptsMustBeGiven();
	void ptsAreGiven();
};

#endif

