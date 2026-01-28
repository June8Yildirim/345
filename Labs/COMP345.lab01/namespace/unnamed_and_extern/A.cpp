// A.cpp and B.cpp are compiled separately and each have their separate 
// compilation unit scope. Thus, the variable y is local to the compilation 
// usit scope of A.cpp. 
#include "A.h"
// x is declared as a global variable. in order for other compilation units 
// to use it, they need to rely on an "extern" varaible declaration, which 
// is provided to them in the A.h header file. 
int x = 3; 

// y is declared in the unnamed namespace and is not visible to the exterior. 
// As it is now, by including A.h, B.cpp is made aware that there is such 
// a thing as a variable y, and will assume that it will be linked at linkage 
// time. However, as y is now declared in the local compilation unit scope 
// of A.cpp, it is not visible as externally linkable from the linker. 
// If the following namespace is removed, then y is globally visible and 
// A.cpp will be connected to it by the linker. 
namespace{
	int y = 4;
}
