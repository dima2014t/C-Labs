#include <cassert>
#include "XOPlayer.h"

using namespace std;

XOPlayer::XOPlayer(TreeNode& tree, PlayField::cellValue botSimbol) :m_tree(tree)
{
	m_currentState = &tree;
	m_botSymbol = botSimbol;
}

PlayField::cellValue XOPlayer::selectPlayer() const
{
	return m_botSymbol;
}

void XOPlayer::makeMove(PlayField::CellPosition iCell)
{
	assert(("this cell is already taken", m_currentState->value()[iCell] == PlayField::csEmpty));
	for (int i = 0; i < m_currentState->childCount(); i++)
	{
		if ((*m_currentState)[i].value()[iCell] != PlayField::cellValue::csEmpty &&
			(*m_currentState)[i].value()[iCell] != m_botSymbol)
		{
			m_currentState = &(*m_currentState)[i];
			break;
		}
	}
}

void XOPlayer::makeMove()
{
	TreeNode* bestMove = m_currentState;
	double bestShareFavorableOutcomes = 0;
	for (int i = 0; i < m_currentState->childCount(); i++)
	{
		TreeNode& possibleMove = (*m_currentState)[i];
		double shareFavorableOutcomes = possibleMove.winCount.getShareFavorableOutcomes(m_botSymbol);
		if (shareFavorableOutcomes > bestShareFavorableOutcomes)
		{
			bestShareFavorableOutcomes = shareFavorableOutcomes;
			bestMove = &possibleMove;
		}
	}
	m_currentState = bestMove;
}

PlayField XOPlayer::currentState() const
{
	return m_currentState->value();
}

PlayField::fieldStatus XOPlayer::fieldStatus() const
{
	return currentState().checkFieldStatus();
}
