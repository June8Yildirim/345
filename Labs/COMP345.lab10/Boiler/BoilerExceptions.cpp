#include <ctime>   // for time() and ctime()
#include "BoilerExceptions.h"
#include "States.h"
using namespace std;

HardwareException::HardwareException() {
	cout << "in HardwareExceptionconstructor" << endl;
	time_t now  = time(0);
	exc_time = ctime(&now);
}

const char * HardwareException::what() const
{
	return typeid(*this).name();
}

ActuatorException::ActuatorException(HardwareState s) : hw_State(s){
	cout << "in ActuatorException constructor" << endl;
};

ostream& operator<<(ostream &output, const ActuatorException& e) {
	cout << "in ActuatorException stream output operator" << endl;
	output << e.hw_State << " @ " << e.exc_time
		   << " : " << e.what() << endl;
	return output;
}

SensorException::SensorException(int v) : valueRead(v){
	cout << "in SensorException constructor" << endl;
};

ostream& operator<<(ostream &output, const SensorException& e) {
	cout << "in SensorException stream output operator" << endl;
	output << e.valueRead << " @ " << e.exc_time
		   << " : " << e.what() << endl;
	return output;
}

NegativePressureException::NegativePressureException(int v) : SensorException(v){
	cout << "in NegativePressureException constructor" << endl;
};

OverloadPressureException::OverloadPressureException(int v) : SensorException(v){
	cout << "in OverloadPressureException constructor" << endl;
};

StuckValveException::StuckValveException(HardwareState s) : ActuatorException(s){ 
	cout << "in StuckValveException constructor" << endl; 
};