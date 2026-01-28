// inspired from: https://docs.microsoft.com/en-us/cpp/cpp/program-termination?view=vs-2019
// abort.cpp
#include <stdio.h>
#include <stdlib.h>

class ShowData {
public:
    // Constructor opens a file.
    // This constructor is called when the sd1 and sd2 objects are created below 
    // and instantiated with strings, essentially acting as a convertor between the 
    // char* type and the ShowData type.  
    ShowData(const char* szDev) {
        // fopen_s() uses an error code
        errno_t err;
        // creates a file open in write mode and assigns it to the OutputDev data member  
        err = fopen_s(&OutputDev, szDev, "w");
    }

    // Destructor closes the file.
    // If the destructor is not called--such as if abort() is called--the file handled is not freed. 
    ~ShowData() { 
        // prints a string to the device, indicating that the destructor was called. 
        fputs("closing output device", OutputDev);
        // close the device
        fclose(OutputDev); 
    }

    // Disp function writes a string on the output device.
    void Disp(const char* szData) {
        fputs(szData, OutputDev);
    }
private:
    FILE* OutputDev;
};

//  Define a static object of type ShowData. The output device
//   selected is "CON" -- the standard output device.
//  "CON" is a Windows C++ reserved name which stants for the console output, which is written to as a file.  
ShowData sd1 = "CON";

int main() {
    //  Define an object of type ShowData local to the main function's body. The output
    //   is directed to a file called "hello.dat"
    ShowData sd2 = "hello.dat";

    sd1.Disp("hello to default device\n");
    sd2.Disp("hello to file hello.dat\n");
    // if return(0) is used, the main function must return int, not void. 
    // This triggers the destructors before the program is terminated. 
    // See the message output in the console and the file. 
    // return(0); // uncomment this line to try

    // if exit(0) is used, the main function can return void or int. 
    // This triggers the destructors before the program is terminated. 
    // See the message output in the console and the file. 
    // exit(0); // uncomment this line to try
 
    // if abort() is used, the main function can return void or int, 
    // and the global objects and the objects declared in the main function 
    // are not freed, as their destructor is not called. 
    // See the absence of message output in the console and the file. 
    // abort(); // uncomment this line to try

    // if none of the above is executed before the end of the main function \
    // (i.e. return, ext, abort), the program terminates at 
    // then end of the main function's body, and the destructors are called for all 
    // global objects and objects declared locally in the main function's body.
    // See the message output in the console and the file. 
}
