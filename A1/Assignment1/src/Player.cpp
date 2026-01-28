#include "player.h"
int Player::uniqueID = 0;

// Default Constructor
Player::Player() {
  this->playerId = ++uniqueID;
  this->name = "player";
  this->hand = "new hand";
}
