# Yu-Gi-Oh

The project is a part of "Object - oriented programming in C++" course.

## Introduction
Cards, deck and duleist structure similar to Yu-Gi-Oh ideas.

## Cards requirements
There are 3 types of cards: 
- Monster cards which have name, effect, attack points, defence points and rarity
- Magic cards which have name, effect, type and rarity
- Pendulum cards which have name, effect, attack points, defence points, type and rarity

## Deck requirements
- A deck has name and cards
- Cards can be added to the deck
- Cards from the deck can be changed
- A deck can be shuffled. 

## Duelist requirements
- A duelist has a name and a deck
- Duelist's deck can be read from a file with a certain format: 
deckname|CardsCount|monsterCardsCount|magicCardsCount|pendulumCardsCount <br>
name|effect|rarity|attackPoints|defencePoints  //monsterCardsCount lines <br>
name|effect|rarity|type   //magicCardsCount lines <br>
name|effect|rarity|attackPoints|defencePoints|pendulumScale|type   //PendulumCardsCount lines <br>
- Duelist's deck can be saved to a file with the same format

## Duel requirements
- A simple duel can take place between duelists with the same number of cards 
- Their decks are compared based on rarity
