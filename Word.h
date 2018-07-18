//
// Created by acous_000 on 5/13/2018.
//

#ifndef SIMPLEAES_WORD_H
#define SIMPLEAES_WORD_H

#include <iostream>
#include <string>

class Word {
    private:
        unsigned int nib1 : 4;
        unsigned int nib2 : 4;

    public:
        Word(unsigned int n1=0, unsigned int n2=0){
            nib1=n1;
            nib2=n2;
        }

        unsigned int getNib1() const {
            return nib1;
        }

        unsigned int getNib2() const {
            return nib2;
        }

        Word operator^(const Word& w) const{
            return Word(w.getNib1()^nib1, w.getNib2()^nib2);
        }

        std::string toBinary(unsigned int v){
//            std::cout << "Entering toBinary\n";
            std::string bin = "";
            int count = 0;
            while(v > 0 || count < 4){
//                std::cout << bin << "\n";
                bin = std::to_string(v % 2) + bin;
                v = v / 2;
                count ++;
            }

            return bin;
        }
};
std::ostream& operator<<(std::ostream& os, Word w);

#endif //SIMPLEAES_WORD_H
