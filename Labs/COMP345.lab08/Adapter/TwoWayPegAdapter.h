#pragma once
#include "SquarePeg.h"
#include "RoundPeg.h"

class TwoWayPegAdapter : public SquarePeg, public RoundPeg {
private:
  RoundPeg *roundPeg;
  SquarePeg *squarePeg;
public:
  TwoWayPegAdapter(RoundPeg *peg) {
    //a roundPeg is plugged into the adapter
    roundPeg = peg;
    squarePeg = NULL;
  }
  TwoWayPegAdapter(SquarePeg *peg) {
    //a squarePeg is plugged into the adapter
    squarePeg = peg;
    roundPeg = NULL;
  }
  void insertIntoRoundHole(string str) {
    cout << "TwoWayAdapter insertIntoSquareHole()" << endl;
    squarePeg->insertIntoSquareHole(str);
  }
  void insertIntoSquareHole(string str) {
    cout << "TwoWayAdapter insertIntoRoundHole()" << endl;
    roundPeg->insertIntoRoundHole(str);
  }
};

