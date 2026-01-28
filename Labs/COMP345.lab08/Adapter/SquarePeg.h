#pragma once
#include<iostream>
#include<string>
using namespace std;

/**
* The RoundPeg class.
* This is the Target class.
*/
class SquarePeg {
public:
  virtual void insertIntoSquareHole(string str) {
    cout << "SquarePeg insertIntoSquareHole(): " << str;
  }
};
