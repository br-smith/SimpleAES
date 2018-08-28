#ifndef SIMPLEAES_KEYEXPANSION_H
#define SIMPLEAES_KEYEXPANSION_H

#include "Word.h"
#include "Key.h"

int SBOX();
unsigned int RC(int i);
Word RCON(int i);
Word SubNib(Word w);
Word RotNib(Word w);
std::vector<Key> key_expansion(const Key key);

#endif // SIMPLEAES_KEYEXPANSION_H
