/*
@author Tsvetelina Chakarova
@compiler VC
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card {
public:
	Card(string name, string effect, unsigned int rarity);
	
	string getName() const;
	string getEffect() const;
	unsigned int GetRarity() const;

	bool operator>(const Card& rhs) const;
	bool operator<(const Card& rhs) const;

	virtual void print() const = 0;
	virtual Card* clone() const = 0;

	virtual string forSaveDeck() const = 0;

	virtual ~Card() {};

private:
	string name;
	string effect;
	unsigned int rarity;
};