/*
@author Tsvetelina Chakarova
@compiler VC
*/

#include "MonsterCard.hpp"

MonsterCard::MonsterCard(string name, string effect, unsigned int rarity, unsigned int attackPoints, unsigned int defencePoints)
	: Card(name, effect, rarity), attackPoints(attackPoints), defencePoints(defencePoints)
{
}

unsigned int MonsterCard::getAttackPoints() const
{
	return attackPoints;
}

unsigned int MonsterCard::getDefencePoints() const
{
	return defencePoints;
}

void MonsterCard::print() const
{
	cout << getName() << "; " << getEffect() << "; " << GetRarity() << "; " << attackPoints << "; " << defencePoints << endl;
}

Card* MonsterCard::clone() const
{
	return new MonsterCard(*this);
}
string MonsterCard::forSaveDeck() const
{
	return getName() + "|" + getEffect() + "|" + to_string(GetRarity()) + "|" + to_string(attackPoints) + "|" + to_string(defencePoints);
}