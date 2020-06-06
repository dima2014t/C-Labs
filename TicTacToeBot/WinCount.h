#pragma once

#include <iostream>
#include "PlayField.h"

class WinCount
{
public:
	WinCount() {};
	WinCount(int, int, int);
	void setCrossWinCount(int);
	int getCrossWinCount() const { return m_crossWinCount; };
	void setNoughtWinCount(int);
	int getNoughtWinCount() const { return m_noughtWinCount; };
	void setDrawWinCount(int);
	int getDrawWinCount() const { return m_drawWinCount; };
	void operator += (WinCount);
	int getTotalWinCount();
	double getShareFavorableOutcomes(PlayField::cellValue);

private:
	int m_crossWinCount = 0;
	int m_noughtWinCount = 0;
	int m_drawWinCount = 0;
};
