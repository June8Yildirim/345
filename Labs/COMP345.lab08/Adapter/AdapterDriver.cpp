#include "SquareToRoundPegAdapter.h"
#include "TwoWayPegAdapter.h"

int main(int argc, char *argv[]){
  // Create some pegs.
  RoundPeg *roundPeg = new RoundPeg();
  SquarePeg *squarePeg = new SquarePeg();
  
  // Do an insert using the square peg.
  squarePeg->insertIntoSquareHole("Inserting square peg...\n\n");
  
  // Now we'd like to do an insert using the round peg.
  // But this client only understands the insert()
  // method of pegs, not a insertIntoHole() method.
  // The solution: create an adapter that adapts
  // a square peg to a round peg!
  
  SquareToRoundPegAdapter *adapter = new SquareToRoundPegAdapter(*roundPeg);
  adapter->insertIntoSquareHole("Inserting round peg...\n\n");
  
  SquarePeg *sq_pegs[2] = { new SquarePeg(),
			    new SquareToRoundPegAdapter(*roundPeg) };
  sq_pegs[0]->insertIntoSquareHole("Inserting square peg [0]...\n");
  sq_pegs[1]->insertIntoSquareHole("Inserting square peg [1]...\n\n");
  
  // Using two way adapter.
  SquarePeg *squarePegArray[2] = { squarePeg,
				   new TwoWayPegAdapter(roundPeg) };
  squarePegArray[0]->insertIntoSquareHole("Inserting Square Peg in squarePegArray[0]...\n");
  squarePegArray[1]->insertIntoSquareHole("Inserting Square Peg in squarePegArray[1]...\n\n");
  
  RoundPeg *roundPegArray[2] = { roundPeg,
				 new TwoWayPegAdapter(squarePeg) };
  roundPegArray[0]->insertIntoRoundHole("Inserting Round Peg in roundPegArray[0]...\n");
  roundPegArray[1]->insertIntoRoundHole("Inserting Round Peg in roundPegArray[1]...\n\n");
  
  delete roundPeg;
  delete squarePeg;
  delete adapter;
  int x; cin >> x;
  return 0;
  
}
