#include <ctime>
#include <iostream>
#include "PressureReleaseValve.h"
#include "BoilerExceptions.h"
#include "Boiler.h"
using namespace std; 

PressureReleaseValve::PressureReleaseValve(HardwareState s = operational) : hw_state(s), act_state(closed){
	cout << "in PressureRelaeaseValve constructor" << endl;
};

void PressureReleaseValve::close(){
	cout << "in PressureReleaseValve::close()" << endl;
	int malfunction;
	malfunction = rand() % 100;
	if (malfunction <= 2) {
		hw_state = stuck;
	}
	if (hw_state == stuck && act_state == opened) {
		cout << "about to throw StuckValveException" << endl;
		throw new StuckValveException(hw_state);
	} else {
		act_state = closed; 
	}
}

void PressureReleaseValve::open(){
	cout << "in PressureReleaseValve::open()" << endl;
	int malfunction;
	malfunction = rand() % 100;
	if (malfunction <= 2) {
		hw_state = stuck;
	}
	if (hw_state == stuck && act_state == closed) {
		cout << "about to throw StuckValveException" << endl;
		throw new StuckValveException(hw_state);
	} else { 
		act_state = opened; 
	}
}

PressureReleaseValveConnector::PressureReleaseValveConnector(PressureReleaseValve *prv, Boiler *b) : prv(prv), b(b){};
	
void PressureReleaseValveConnector::close(){
	try{
		prv->close();
	}
	catch (StuckValveException e) {
		cout << "catching StuckValveException in PressureReleaseValveConnector::close()" << endl;
		b->emergencyFile << e;
	}
}

void PressureReleaseValveConnector::open(){
	cout << "in PressureReleaseValveConnector::open()" << endl;
	try{
		prv->open();
	}
	catch (StuckValveException* e) {
		cout << "catching StuckValveException in PressureReleaseValveConnector::open()" << endl;
		cout << "Evacuation!!" << endl;
		b->boilerState = critical;
		b->emergencyFile << *e;
		b->emergencyFile << "Evacuation!!" << endl;
	}
}