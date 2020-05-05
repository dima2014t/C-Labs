#include <iostream>
#include <cassert>
#include "WinCount.h"

WinCount::WinCount(int crossWin, int noughtWin, int drawWin)
{
	m_crossWinCount = crossWin;
	m_noughtWinCount = noughtWin;
	m_drawWinCount = drawWin;
}

void WinCount::setCrossWinCount(int value)
{
	assert(("incorrect win count", value >= 0));
	m_crossWinCount = value;
}

void WinCount::setNoughtWinCount(int value)
{
	assert(("incorrect win count", value >= 0));
	m_noughtWinCount = value;
}

void WinCount::setDrawWinCount(int value)
{
	assert(("incorrect win count", value >= 0));
	m_drawWinCount = value;
}

void WinCount::operator+=(WinCount left)
{
	m_crossWinCount += left.getCrossWinCount(),
	m_noughtWinCount += left.getNoughtWinCount(),
	m_drawWinCount += left.getDrawWinCount();
}
