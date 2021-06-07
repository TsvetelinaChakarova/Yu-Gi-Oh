/*
@author Tsvetelina Chakarova
@compiler VC
*/

#pragma once

#include <vector>
#include <typeinfo>
#include <algorithm>
#include <time.h>
#include "PendulumCard.hpp"

class Deck {
public:
	Deck() = default;
	Deck(const string& name);
	Deck(const Deck& rhs);
	Deck& operator=(const Deck& rhs);

	string getName() const;
	unsigned int getMonsterCardsNumber() const;
	unsigned int getMagicCardsNumber() const;
	unsigned int getPendulumCardsNumber() const;
	unsigned int getCardsNumber() const;

	void add(Card* to_add);
	void change(unsigned int index, Card* to_change);
	void empty();
	void shuffle();
	
	void print() const; 
	void setName(const string& name);
	vector<Card*> getCards();

	~Deck();

private:
	string name;
	vector<Card*> cards;
};