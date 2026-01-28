#pragma once
#include<string>
#include "SquarePeg.h"
#include "RoundPeg.h"

/**
 * The SquareToRoundPegAdapter class.
 * This is the Adapter class.
 * It adapts a SquarePeg to a RoundPeg.
 * Its interface is that of a SquarePeg.
 */
class SquareToRoundPegAdapter : public SquarePeg {
private:
  RoundPeg roundPeg;
public:
  SquareToRoundPegAdapter(RoundPeg peg) {
    //the roundPeg is plugged into the adapter
    roundPeg = peg;
  }
  void insertIntoSquareHole(string str) {
    cout << "SquareToRoundPegAdapter insertIntoSquareHole()" << endl;
    //the roundPeg can now be inserted in the same manner as a squarePeg!
    roundPeg.insertIntoRoundHole(str);
  }
};

