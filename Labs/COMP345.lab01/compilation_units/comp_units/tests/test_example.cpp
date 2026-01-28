#include <iostream>
#include "../include/project.h"

int main() {
    std::cout << "Running tests..." << std::endl;
    
    Project p;
    p.greet();
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
