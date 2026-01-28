// Since B.cpp includes B.h that in turn includes A.h, 
// the following is compiled as B.cpp is compiled. 
// Thus, the variable x is in the compilation unit scope 
// of B.cpp. 

// If a cpp file uses a global variable that it want to share 
// with other compilation units, it should declare the variable, 
// then have its header file have an "extern" declaration, and
// the other compilation unit should include the heared file, 
// thus being aware that the variable is declared in another 
// compilation unit. 

extern int x;
extern int y; 
