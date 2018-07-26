#ifndef SIMPLEAES_KEYEXPANSION_H
#define SIMPLEAES_KEYEXPANSION_H

#include "Word.h"

int SBOX();
unsigned int RC(int i);
Word RCON(int i);
Word SubNib(Word w);
Word RotNib(Word w);
Word* key_expansion(int word1, int word2);

#endif // SIMPLEAES_KEYEXPANSION_H
