#pragma once

// The Observer class is an abstract class, as it contains at least one pure virtual function. 
// This is essentially the same concept as an "interface" in Java, except that it is still an inherited class. 
// Just like in the case of a Java interface, this abstract class "forces" its subclasses to implement its 
// pure virtual functions. 
// Pure virtual functions are covered in slide 7.

class Observer {
public:
	~Observer();
	virtual void Update() = 0;
protected:
	Observer();
};
