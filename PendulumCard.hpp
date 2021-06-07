/*
@author Tsvetelina Chakarova
@compiler VC
*/

#pragma once

#include "MagicCard.hpp"
#include "MonsterCard.hpp"
#include "Card.hpp"

class PendulumCard : public MagicCard, public MonsterCard {
public:
	PendulumCard(string name, string effect, unsigned int rarity, unsigned int attackPoints, unsigned int ddefencePoints, Type type, unsigned int pendulumScale);

	unsigned int getPendulumScale() const;

	void print() const;
	Card* clone() const;
	string forSaveDeck() const; // returns a string in the format for the file that is created in Duelist::saveDeck

	~PendulumCard() {}

private:
	unsigned int pendulumScale;   // number between 1 and 13
};