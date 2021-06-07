/*
@author Tsvetelina Chakarova
@compiler VC
*/

#pragma once

#include "Deck.hpp"

#include <fstream>

class Duelist {
public:
	Duelist(string name, Deck deck);

	Deck& getDeck();
	bool saveDeck(string fileName);
	bool loadDeck(string fileName);
	string duel(Duelist& duelist1);
	void print() const;

private:
	string name;
	Deck deck;
};