/*
@author Tsvetelina Chakarova
@compiler VC
*/

#include "MagicCard.hpp"

MagicCard::MagicCard(string name, string effect, unsigned int rarity, Type type)
	:Card(name, effect, rarity), type(type)
{
}

Type MagicCard::getType() const
{
	return type;
}

void MagicCard::print() const
{
	cout << getName() << "; " << getEffect() << "; " << GetRarity() << "; ";
	switch (type) {
	case Type::buff: cout << "buff" << endl; break;
	case Type::trap: cout << "trap" << endl; break;
	case Type::spell: cout << "spell" << endl; break;
	}
}

Card* MagicCard::clone() const
{
	return new MagicCard(*this);
}

string MagicCard::forSaveDeck() const
{
	string to_return = getName() + "|" + getEffect() + "|" + to_string(GetRarity()) + "|";
	switch (type) {
	case Type::buff: to_return += "buff"; break;
	case Type::trap: to_return += "trap"; break;
	case Type::spell: to_return += "spell"; break;
	}

	return to_return;
}
