/*****************************************************************************
 * PokerTH - The open source texas holdem engine                             *
 * Copyright (C) 2006-2011 Felix Hammer, Florian Thauer, Lothar May          *
 *                                                                           *
 * This program is free software: you can redistribute it and/or modify      *
 * it under the terms of the GNU Affero General Public License as            *
 * published by the Free Software Foundation, either version 3 of the        *
 * License, or (at your option) any later version.                           *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU Affero General Public License for more details.                       *
 *                                                                           *
 * You should have received a copy of the GNU Affero General Public License  *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
 *****************************************************************************/

#ifndef CLIENTBOARD_H
#define CLIENTBOARD_H

#include <boardinterface.h>
#include <boost/thread.hpp>
#include <vector>


class PlayerInterface;
class HandInterface;


class ClientBoard : public BoardInterface
{
public:
	ClientBoard(unsigned dealerPosition);
	~ClientBoard();

	void setPlayerLists(PlayerList, PlayerList, PlayerList);

	void setMyCards(int* theValue);
	void getMyCards(int* theValue);

	int getPot() const;
	void setPot(int theValue);
	int getSets() const;
	void setSets(int theValue);

	void setAllInCondition(bool theValue);
        void setLastActionPlayerID(unsigned theValue);

	void collectSets();
	void collectPot();

	void distributePot();
	void determinePlayerNeedToShowCards();

	std::list<unsigned> getWinners() const;
	void setWinners(const std::list<unsigned> &winners);

	std::list<unsigned> getPlayerNeedToShowCards() const;
	void setPlayerNeedToShowCards(const std::list<unsigned> &playerNeedToShowCards);

private:
	mutable boost::recursive_mutex m_syncMutex;

	PlayerList seatsList;
	PlayerList activePlayerList;
	PlayerList runningPlayerList;

	std::list<unsigned> winners;
	std::list<unsigned> playerNeedToShowCards;

	int myCards[5];
	int pot;
	int sets;
	unsigned dealerPosition;
	bool allInCondition;
        unsigned lastActionPlayerID;
};

#endif
