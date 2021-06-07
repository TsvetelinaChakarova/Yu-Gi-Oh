/*
@author Tsvetelina Chakarova
@compiler VC
*/

#pragma once

#include "Card.hpp"

enum Type
{
	trap,
	buff,
	spell,
};

class MagicCard : virtual public Card {
public:
	MagicCard(string name, string effect, unsigned int rarity, Type type);
	
	Type getType() const;

	void print() const;
	Card* clone() const;
	string forSaveDeck() const; // returns a string in the format for the file that is created in Duelist::saveDeck

	~MagicCard() {}

private:
	Type type;
};
