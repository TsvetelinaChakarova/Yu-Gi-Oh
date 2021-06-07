/*
@author Tsvetelina Chakarova
@compiler VC
*/

#include "PendulumCard.hpp"

PendulumCard::PendulumCard(string name, string effect, unsigned int rarity, unsigned int attackPoints, unsigned int ddefencePoints, 
						   Type type, unsigned int pendulumScale)
	:Card(name, effect, rarity), MonsterCard(name, effect, rarity, attackPoints, ddefencePoints), 
	 MagicCard(name, effect, rarity, type), pendulumScale(pendulumScale)
{
}

unsigned int PendulumCard::getPendulumScale() const
{
	return pendulumScale;
}

void PendulumCard::print() const
{
	cout << getName() << "; " << getEffect() << "; " << GetRarity() << ";" << getAttackPoints() << "; "
		<< getDefencePoints() << "; ";
	switch (getType()) {
	case Type::buff: cout << "buff"; break;
	case Type::trap: cout << "trap"; break;
	case Type::spell: cout << "spell"; break;
	}
	cout<< "; " << pendulumScale << endl;
}

Card* PendulumCard::clone() const
{
	return new PendulumCard(*this);
}

string PendulumCard::forSaveDeck() const
{
	string to_return = getName() + "|" + getEffect() + "|" + to_string(GetRarity()) + "|" + to_string(getAttackPoints()) + "|"
		+ to_string(getDefencePoints()) + "|"; 

	switch (getType()) {
	case Type::buff: to_return += "buff"; break;
	case Type::trap: to_return += "trap"; break;
	case Type::spell: to_return += "spell"; break;
	}

	to_return += "|" + to_string(pendulumScale);

	return to_return;
}
