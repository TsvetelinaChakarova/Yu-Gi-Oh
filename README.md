Cards, deck and duleist structure similar to Yu-Gi-Oh ideas.

There are 3 types of cards: 
- Monster cards which have name, effect, attack points, defence points and rarity
- Magic cards which have name, effect, type and rarity
- Pendulum cards which have name, effect, attack points, defence points, type and rarity

A deck has name and cards.
Cards can be added to the deck. cards from the deck can be changed. A deck can be shuffled. 

A duelist has name and deck.
Duelist's deck can be read from a file with a certain format: 
<deckname>|<CardsCount>|<monsterCardsCount>|<magicCardsCount>|<pendulumCardsCount>
<name>|<effect>|<rarity>|<attackPoints>|<defencePoints>  //monsterCardsCount lines 
<name>|<effect>|<rarity> |<type>   //magicCardsCount lines
<name>|<effect>|<rarity>|<attackPoints>|<defencePoints>|<pendulumScale>|<type>   //PendulumCardsCount lines
And can be saved to a file with the same format.

A simple duel can take place between duelists with the same number of cards. Their decks are compared based on rarity.

//The project is a part of "Object - oriented programming in C++" course.
