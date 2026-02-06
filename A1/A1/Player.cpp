#include "Player.h"
#include "Deck.h"       // Required for 'new Deck()'
#include "Hand.h"       // Required for 'new Hand()'
#include "OrdersList.h" // Required for 'new OrdersList()'
#include "Territory.h"
#include "algorithm"
#include "iostream"
using namespace std;

Player::Player() {
  playerName = new std::string("Default Player");
  this->territories = new std::vector<Territory *>();
  this->hand = new Hand();
  this->deck = new Deck();
  this->orderslist = new OrdersList();
  armyPool = 0;
}

Player::Player(const std::string &name) {
  this->playerName = new std::string(name);
  this->territories = new std::vector<Territory *>();
  this->hand = new Hand();
  this->deck = new Deck();
  this->orderslist = new OrdersList();
  armyPool = 0;
}

Player &Player::operator=(const Player &oldPlayer) {
  if (this != &oldPlayer) {
    playerName = oldPlayer.playerName;
    territories = oldPlayer.territories;
    hand = oldPlayer.hand;
    deck = oldPlayer.deck;
    orderslist = oldPlayer.orderslist;
    armyPool = oldPlayer.armyPool;
  }
  return *this;
}

// Destructor for Player.
Player::~Player() {
  delete playerName;
  delete territories;
  delete hand;
  delete deck;
  delete orderslist;
}

std::string Player::getPlayerName() const { return *playerName; }

Hand *Player::getHand() const { return hand; }

OrdersList *Player::getOrderList() const { return orderslist; }

Deck *Player::getDeck() const { return deck; }

int Player::getArmyPool() const { return armyPool; }

void Player::addTerritory(Territory *territory) {
  territories->push_back(territory);
}

void Player::removeTerritory(Territory *territory) {
  // std::find requires <algorithm>
  auto it = std::find(territories->begin(), territories->end(), territory);
  if (it != territories->end()) {
    territories->erase(it);
  }
}

void Player::issueOrder() {
  // Fixed typo: changed 'tihs' to 'this'
  Order *newOrder = new Order(this, nullptr, 5);
  orderslist->addOrder(newOrder);
}

std::vector<Territory *> *Player::getTerritories() const { return territories; }

bool Player::isTerritoryOwned(Territory *territory) const {
  return std::find(territories->begin(), territories->end(), territory) !=
         territories->end();
}

void Player::setPlayerName(const std::string &name) {
  *(this->playerName) = name;
}

void Player::setArmyPool(int armyPool) { this->armyPool = armyPool; }

void Player::increaseArmyPool() {
  if (armyPool < 6) { // 'this->' is optional here
    armyPool += 1;
  } else {
    cout << "You already deployed all armies"; // Fixed: << instead of <
  }
}

void Player::addCard(Card *card) { hand->addCard(card); }
void Player::removeCard(Card *card) { hand->removeCard(card); }
void Player::setHand(Hand *hand) { this->hand = hand; }

std::vector<Territory *> *Player::toAttack() const {
  // Implementation for determining territories to attack
  return new std::vector<Territory *>();
}

std::vector<Territory *> *Player::toDefend() const {
  // Implementation for determining territories to defend
  return new std::vector<Territory *>();
}
