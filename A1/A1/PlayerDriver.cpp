/**
 * @file PlayerDriver.cpp
 * @brief Assignment 1 : Player class driver
 * @author
 * @version 1.0
 *
 * This file contains the test driver for the Player class functionality,
 * demonstrating all requirements including hand ownership, territory management
 * methods (toDefend/toAttack), and order issuance capabilities.
 */

#include "../include/Cards.h"
#include "../include/Map.h"
#include "../include/Orders.h"
#include "../include/Player.h"
#include "Player.h"
#include <iostream>

// Importing only the neccessary std functions.
using std::cout;

void PlayerDriver() {
  cout << "\n==== Player Class functionality starts testing";

  Player janeDoe("Jane Doe");
  Player johnDoe("John Doe");

  Player copyJane(janeDoe);

  Territory *qc = new Territory(1, "Quebec");
  Territory *on = new Territory(2, "Ontario");
  Territory *al = new Territory(3, "Alberta");
  Territory *br = new Territory(4, "New Brunswick");
  Territory *ny = new Territory(5, "New-York");

  // Quebec's neighboors
  qc.addAdjacent(on);
  qc.addAdjacent(ny);
  qc.addAdjacent(br);

  // Ontario's neighboors
  on.addAdjacent(qc);
  on.addAdjacent(al);
  on.addAdjacent(ny);

  // New Brunswick's neighboors
  br.addAdjacent(qc);

  // Alberta's neighboors
  al.addAdjacent(on);

  // New-York's neighboors
  ny.addAdjacent(qc);

  qc.setOwner(janeDoe);
  al.setOwner(johnDoe);

  janeDoe.addTerritory(qc);
  johnDoe.addTerritory(al);
}
