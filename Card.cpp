/*
@author Tsvetelina Chakarova
@compiler VC
*/

#include "Card.hpp"

Card::Card(string name, string effect, unsigned int rarity)
	: name(name), effect(effect), rarity(rarity)
{
}

string Card::getName() const
{
	return name;
}

string Card::getEffect() const
{
	return effect;
}

unsigned int Card::GetRarity() const
{
	return rarity;
}

bool Card::operator>(const Card& rhs) const
{
	return (rarity > rhs.rarity);
}

bool Card::operator<(const Card& rhs) const
{
	return (rarity < rhs.rarity);
}

void Card::print() const {
	cout << name << "; " << effect << "; " << rarity << endl;
}