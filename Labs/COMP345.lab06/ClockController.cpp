#include "ClockController.h"
#include <iostream>
using namespace std; 

ClockController::ClockController(DigitalClock* newView, ClockTimer* newModel) {
	clockView = newView;
	clockModel = newModel;
}
void ClockController::controlClock() {
	while (true) {
		int command;
		cout << "1. Set the timer's start time (1 int int int <return>)" << endl;
		cout << "2. Set the timer's timed interval (2 int <return>)" << endl;
		cout << "3. Start the timer (3 <return>)" << endl;
		cout << "4. Exit (4 <return>)" << endl;
		cout << "Enter action (1,2,3,4) : ";
		cin >> command;
		switch (command) {
		case 1:
			int h, m, s;
			cin >> h >> m >> s;
			clockModel->setTime(h, m, s);
			break;
		case 2:
			int t;
			cin >> t;
			clockModel->setTimedInterval(t);
			break;
		case 3:
			clockModel->start();
			break;
		case 4:
			return;
		}
	}
}