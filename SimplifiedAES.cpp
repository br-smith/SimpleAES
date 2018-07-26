#include <iostream>
#include "KeyExpansion.h"

/*
 * function: add_key
 *
 * description: The function add_key(i) consists of XORing key[i] with the current state 
 */

Key add_key(const int i){
	return 0;
}

/*
 * function: nib_sub
 *
 * description: The function nib_sub calls the KeyExpansion SubNib function on both of the words it contains
 */

Key nib_sub(const Key k) const{
	k.setWord1(SubNib(k.getWord1()));
	k.setWord2(SubNib(k.getWord2()));
}
