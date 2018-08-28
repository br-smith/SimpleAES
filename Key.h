//
// Created by Brandon Smith on 7/24/18
//

#ifndef SIMPLEAES_KEY_H
#define SIMPLEAES_KEY_H

#include <iostream>
#include "Word.h"

class Key {
    private:
	Word word1;
	Word word2;

    public:
	Key(Word w1=NULL, Word w2=NULL){
	    // std::cout << "Hello; setting word 1 to: " << w1 << " and word 2 to: " << w2 << std::endl;
	    word1 = w1;
	    word2 = w2;	
	}

	const Word& getWord1() const {
	    return word1;
	}
    
    std::string getBinary() const {
       return word1.getBinary() + word2.getBinary();
    }

	char* getWord1Bin() {
	    std::cout << "Entering getWord1Bin method" << std::endl;
	    return word1.getBitArray();
	}

	char* getWord2Bin() {
	    return word2.getBitArray();
	}

	const Word& getWord2() const {
	    return word2;
	}

	void setWord1(const Word w) {
	    word1 = w;
	}

	void setWord2(const Word w) {
	    word2 = w;
	}

	Key operator^(const Key& k) const {
	    return Key(k.getWord1()^word1, k.getWord2()^word2);
	}

};

std::ostream& operator<<(std::ostream& os, Key k);

#endif // SIMPLEAES_KEY_H
