#pragma once
#include<iostream>
#include<string>
using namespace std;

/**
 * The RoundPeg class.
 * This is the Adaptee class.
 */
class RoundPeg {
public:
  virtual void insertIntoRoundHole(string str) {
    cout << "RoundPeg insertIntoRoundHole(): " << str;
  }
};
