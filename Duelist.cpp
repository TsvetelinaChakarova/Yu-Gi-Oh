/*
@author Tsvetelina Chakarova
@compiler VC
*/

#include "Duelist.hpp"

Duelist::Duelist(string name, Deck deck)
{
	this->name = name;
	this->deck = deck;
}

Deck& Duelist::getDeck()
{
	return deck;
}

bool Duelist::saveDeck(string fileName)
{
	ofstream file;
	file.open(fileName);
	if (file.is_open()) {
		file << deck.getName() << '|' << deck.getCardsNumber() << "|" << deck.getMonsterCardsNumber() << '|' << deck.getMagicCardsNumber() <<
			'|' << deck.getPendulumCardsNumber() << endl;
		
		for (int i = 0; i < deck.getCardsNumber(); i++) {
			if (typeid(*deck.getCards()[i]) == typeid(MonsterCard)) {
				file << deck.getCards()[i]->forSaveDeck() << endl;
			}
		}

		for (int i = 0; i < deck.getCardsNumber(); i++) {
			if (typeid(*deck.getCards()[i]) == typeid(MagicCard)) {
				file << deck.getCards()[i]->forSaveDeck() << endl;
			}
		}

		for (int i = 0; i < deck.getCardsNumber(); i++) {
			if (typeid(*deck.getCards()[i]) == typeid(PendulumCard)) {
				file << deck.getCards()[i]->forSaveDeck() << endl;
			}
		}
	   
		return true;
	}
	else {
		return false;
	}
}

bool Duelist::loadDeck(string fileName)
{
	vector<string> fileLines;
	unsigned int i = 0;
	string divider = "|";

	ifstream file;
	file.open(fileName, ios::in);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			fileLines.push_back(line);
			i++;
		}

		if (i > 0) {
			// reading the first line - deck name, number of cards, number of monster cards, number of magic cards and number of pendulum cards
			string deckName = fileLines[0].substr(0, fileLines[0].find(divider));
			fileLines[0].erase(0, fileLines[0].find(divider) + 1);
			
			unsigned int cardsNumber = stoi(fileLines[0].substr(0, fileLines[0].find(divider)));
			fileLines[0].erase(0, fileLines[0].find(divider) + 1);

			unsigned int monsterCardsNumber = stoi(fileLines[0].substr(0, fileLines[0].find(divider)));
			fileLines[0].erase(0, fileLines[0].find(divider) + 1);

			unsigned int magicCardsNumber = stoi(fileLines[0].substr(0, fileLines[0].find(divider)));
			fileLines[0].erase(0, fileLines[0].find(divider) + 1);
			
			unsigned int pendulumCardsNumber = stoi(fileLines[0].substr(0, fileLines[0].find(divider)));

			deck.empty(); // the deck is empty end it will be filled with the informtion form the file using deck::add method
			deck.setName(deckName);

			// reading the lines with monster cards - name, effect, rarity, attack points, defence points; 
			// creating a card for each line and adding it to the deck
			for (unsigned int index = 1; index <= monsterCardsNumber; index++) { // i = 1 because monster cards start on the first line of the file (if they are any)
				string name = fileLines[index].substr(0, fileLines[index].find(divider));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				string effect = fileLines[index].substr(0, fileLines[index].find(divider));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				int rarity = stoi(fileLines[index].substr(0, fileLines[index].find(divider)));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				int attackPoints = stoi(fileLines[index].substr(0, fileLines[index].find(divider)));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				int defencePoints = stoi(fileLines[index].substr(0, fileLines[index].find(divider)));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);

				MonsterCard to_add(name, effect, rarity, attackPoints, defencePoints);
				deck.add(&to_add);
			}

			// reading the lines with magic cards - name, effect, rarity, type;
			// creating a card for each line and adding it to the deck
			for (unsigned int index = monsterCardsNumber + 1; index <= monsterCardsNumber + magicCardsNumber; index++) {
				string name = fileLines[index].substr(0, fileLines[index].find(divider));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				string effect = fileLines[index].substr(0, fileLines[index].find(divider));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				int rarity = stoi(fileLines[index].substr(0, fileLines[index].find(divider)));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				string type = fileLines[index].substr(0, fileLines[index].find(divider));
				if (type == "spell") {
					MagicCard to_add(name, effect, rarity, Type::spell);
					deck.add(&to_add);
				}
				if (type == "buff") {
					MagicCard to_add(name, effect, rarity, Type::buff);
					deck.add(&to_add);
				}
				if (type == "trap") {
					MagicCard to_add(name, effect, rarity, Type::trap);
					deck.add(&to_add);
				}

			}

			// reading the lines with pendulum cards - name, effect, rarity attack points, defence points, pendulum scale, type;
			//creating a card for each line and adding it to the deck
			for (unsigned int index = monsterCardsNumber + magicCardsNumber + 1; index <= cardsNumber; index++) {
				string name = fileLines[index].substr(0, fileLines[index].find("|"));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				string effect = fileLines[index].substr(0, fileLines[index].find(divider));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				int rarity = stoi(fileLines[index].substr(0, fileLines[index].find(divider)));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				int attackPoints = stoi(fileLines[index].substr(0, fileLines[index].find(divider)));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				int defencePoints = stoi(fileLines[index].substr(0, fileLines[index].find(divider)));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				int pendulumScale = stoi(fileLines[index].substr(0, fileLines[index].find(divider)));
				fileLines[index].erase(0, fileLines[index].find(divider) + 1);
				
				string type = fileLines[index].substr(0, fileLines[index].find(divider));
				if (type == "spell") {
					PendulumCard to_add(name, effect, rarity, attackPoints, defencePoints, Type::spell, pendulumScale);
					deck.add(&to_add);
				}
				if (type == "buff") {
					PendulumCard to_add(name, effect, rarity, attackPoints, defencePoints, Type::buff, pendulumScale);
					deck.add(&to_add);
				}
				if (type == "trap") {
					PendulumCard to_add(name, effect, rarity, attackPoints, defencePoints, Type::trap, pendulumScale);
					deck.add(&to_add);
				}
			}
		}

		file.close();
		return true;
	}

	else {
		return false;
	}
}

string Duelist::duel(Duelist& duelist1)
{
	if (duelist1.deck.getCardsNumber() != this->deck.getCardsNumber()) {
		return "Duel cannot take place. The duelists must have equal number of cards!";
	}
	else {
		duelist1.deck.shuffle();
		deck.shuffle();
		unsigned int duelist1Points = 0, duelist2Points = 0; // duelist2Points are the points of this duelist
		for (int i = 0; i < deck.getCardsNumber(); i++) {
			if (duelist1.deck.getCards()[i] > deck.getCards()[i]) {
				duelist1Points++;
			}
			else {
				if (duelist1.deck.getCards()[i] < deck.getCards()[i]) {
					duelist2Points++;
				}
			}
		}
		if (duelist1Points == duelist2Points) {
			return "Equal result: " + to_string(duelist1Points) + " points for each duelist";
		}
		else {
			if (duelist1Points > duelist2Points) {
				return duelist1.name + " won (" + to_string(duelist1Points) + " points)." +
					name + " lost (" + to_string(duelist2Points) + " points).";
			} 
			else {
				return name + " won (" + to_string(duelist2Points) + " points)." +
					duelist1.name + " lost (" + to_string(duelist1Points) + " points).";
			}
		}
	}
}

void Duelist::print() const
{
	cout << name << endl;
	deck.print();
}