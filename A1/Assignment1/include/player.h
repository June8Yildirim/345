#include <string>

class Player {
public:
  Player();

private:
  static int uniqueID;
  int playerId;
  std::string name;
  std::string hand; // assuming Hand is a class
};
