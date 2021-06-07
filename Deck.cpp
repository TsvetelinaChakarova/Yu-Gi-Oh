/*
@author Tsvetelina Chakarova
@compiler VC
*/

#include "Deck.hpp"

Deck::Deck(const string& name)
{
    this->name = name;
}

Deck::Deck(const Deck& rhs)
{
    this->name = name;
    for (auto x : rhs.cards) {
        cards.push_back(x->clone());
    }
}

Deck& Deck::operator=(const Deck& rhs)
{
    if (this != &rhs) {
        for (auto x : cards) {
            delete x;
        }
        cards.clear();

        this->name = name;
        for (auto x : rhs.cards) {
            cards.push_back(x->clone());
        }
    }
    return *this;
}

string Deck::getName() const
{
    return name;
}

unsigned int Deck::getMonsterCardsNumber() const
{
    unsigned int num = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (typeid(*cards[i]) == typeid(MonsterCard)) {
            num++;
        }
    }

    return num;
}

unsigned int Deck::getMagicCardsNumber() const
{
    unsigned int num = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (typeid(*cards[i]) == typeid(MagicCard)) {
            num++;
        }
    }

    return num;
}

unsigned int Deck::getPendulumCardsNumber() const
{
    unsigned int num = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (typeid(*cards[i]) == typeid(PendulumCard)) {
            num++;
        }
    }

    return num;
}

unsigned int Deck::getCardsNumber() const
{
    return cards.size();
}

void Deck::add(Card* to_add)
{
    this->cards.push_back(to_add->clone());
}

void Deck::change(unsigned int index, Card* to_change)
{
    cards[index] = to_change->clone();
}

void Deck::empty()
{
    cards.clear();
}

void Deck::shuffle()
{
   srand(time(0));
   random_shuffle(cards.begin(), cards.end());
}

void Deck::print() const
{
    cout << name << endl;
    for (unsigned int i = 0; i < this->cards.size(); i++) {
        cards[i]->print();
    }
}

void Deck::setName(const string& name)
{
    this->name = name;
}

vector<Card*> Deck::getCards()
{
    return cards;
}

Deck::~Deck()
{
    for (auto x : cards) {
        delete x;
    }
}