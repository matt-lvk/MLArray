#include "MLArrays.hpp"
#include <iostream>


int main () {
    MLArray a{1,2,3,4,5};
    
    for (int i=0; i < a.size(); i++) {
        std::cout << a[i] << " ";
        std::cout << std::endl;
    }
    return 0;
}
