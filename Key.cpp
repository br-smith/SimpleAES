//
// Created by Brandon Smith on 7/24/2018
//

#include "Key.h"

std::ostream& operator<<(std::ostream& os, Key k){
    //std::cout << "Word 1: " << k.getWord1() << std::endl;
    //std::cout << "Word 2: " << k.getWord2() << std::endl;
    os << k.getWord1() << k.getWord2();
    return os;
}
