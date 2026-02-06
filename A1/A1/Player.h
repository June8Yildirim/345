#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

class Card;
class Deck;
class Hand;
class Order;
class OrdersList;
class Territory;

class Player {
private:
  std::string *playerName;
  std::vector<Territory *> *territories;
  Hand *hand;
  Deck *deck;
  OrdersList *orderslist;
  int armyPool = 0;

public:
  Player();
  Player(const std::string &name);

  Player &operator=(const Player &oldPlayer);
  ~Player();

  std::string getPlayerName() const;
  void setPlayerName(const std::string &name);

  OrdersList *getOrderList() const;

  // Getters for deck and army pool
  Deck *getDeck() const;
  int getArmyPool() const;
  void increaseArmyPool();
  void setArmyPool(int armyPool);

  // Methods to manage territories
  void addTerritory(Territory *territory);
  void removeTerritory(Territory *territory);
  bool isTerritoryOwned(Territory *territory) const;
  std::vector<Territory *> *getTerritories() const;

  // Getter for hand
  Hand *getHand() const;
  void setHand(Hand *hand);

  // Methods to manage cards
  void addCard(Card *card);
  void removeCard(Card *card);

  // Method to issue orders
  void issueOrder();

  std::vector<Territory *> *toAttack() const;
  std::vector<Territory *> *toDefend() const;
};
#endif
