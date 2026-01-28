#include <ctime> //for rand() and time()
#include "PressureSensor.h"
#include "BoilerExceptions.h"
#include "Boiler.h"

int PressureSensor::getPressure(){
	cout << "in PressureSensor::getPressure()" << endl;
	int pressure = rand() % 105 - 1;
	if (pressure < 0) {
		cout << "about to throw NegativePressureException" << endl;
		throw new NegativePressureException(pressure);
	}
	if (pressure > 100) {
		cout << "about to throw OverloadPressureException" << endl;
		throw new OverloadPressureException(pressure);
	}
	return pressure;
}

PressureSensorConnector::PressureSensorConnector(PressureSensor *ps, Boiler *b) : ps(ps), b(b) {
	cout << "in PressureSensorConnector constructor" << endl;
};

int PressureSensorConnector::getPressure(){
	cout << "in PressureSensorConnector::getPressure()" << endl;
	int pressure = 999;
	try{
		pressure = ps->getPressure();
		time_t now = time(0);
		char *read_time = ctime(&now);
		b->pressureReportFile << pressure << " @ " << read_time << endl;
	}
	catch (SensorException* e){
		cout << "catching SensorException in PressureSensorConnector::getPressure()" << endl;
		b->emergencyFile << *e;
		b->boilerState = unsafe;
		b->shutdown();
	}
	return pressure;
}