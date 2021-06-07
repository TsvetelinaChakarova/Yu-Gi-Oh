/*
@author Tsvetelina Chakarova
@compiler VC
*/

#pragma once

#include "Card.hpp"

class MonsterCard : virtual public Card {
public:
	MonsterCard(string name, string effect, unsigned int rarity, unsigned int attackPoints, unsigned int defencePoints);

	 unsigned int getAttackPoints() const;
	 unsigned int getDefencePoints() const;

	void print() const;
	Card* clone() const;
	string forSaveDeck() const; // returns a string in the format for the file that is created in Duelist::saveDeck

	~MonsterCard() {}

private:
	unsigned int attackPoints;
	unsigned int defencePoints;
};
