#pragma once
#include <list>
using namespace std;

class Observer;

class Observable
{
public:
  virtual ~Observable() {};
  virtual void attach(Observer *) = 0;
  virtual void detach(Observer *) = 0;
  virtual void notify() = 0;
protected:
  Observable() {};
private:
  list<Observer*> _observers;
};

