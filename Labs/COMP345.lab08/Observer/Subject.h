#pragma once
#include<list>
#include "Observable.h"

using namespace std;

class Subject : public Observable {

public:
	Subject();
	~Subject();

	void attach(Observer *);
	void detach(Observer *);
	void notify();
private:
	list<Observer*>* _observers;
};