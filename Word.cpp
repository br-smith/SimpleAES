//
// Created by acous_000 on 5/13/2018.
//

#include "Word.h"

std::ostream& operator<<(std::ostream& os, Word w){
//    os << "Decimal value of nib 1: " << w.getNib1() << " Decimal value of nib 2: " << w.getNib2() << "\n";
//    os << "Binary value of nib 1: " << w.toBinary(w.getNib1()) << " Binary value of nib 2: " << w.toBinary(w.getNib2()) << "\n";
//    os << w.getNib1() << " " << w.getNib2() << "\n";
    // os << w.toBinary(w.getNib1()) << w.toBinary(w.getNib2());
    os << w.getBinary();
    return os;
}
