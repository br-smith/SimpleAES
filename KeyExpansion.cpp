#include <iostream>
//#include <windef.h>
#include "Word.h"
#include "Key.h"
#include "KeyExpansion.h"

using namespace std;

/*
int SBOX();
unsigned int RC(int i);
Word RCON(int i);
Word SubNib(Word w);
Word RotNib(Word w);
Word* key_expansion(int key1, int key2);
*/

const unsigned int SBOX_lookup[16] = {9, 4, 10, 11, 13, 1, 8, 5, 6, 2, 0, 3, 12, 14, 15, 7};


/*
 * This RC function is just hard coded with the return values to see if it's at least slightly working.
 * I'll come back to this one and see if I can get a better implementation
 *
 */
unsigned int RC(const int i){
    unsigned int r = 0;
    switch(i+2){
        case 3:
            r = 8;
            break;
        case 4:
            r = 3;
            break;
        case 5:
            r = 6;
            break;
        default:
            break;
    }
    return r;
}


/*
 *  function: RCON()
 *
 *  description: This function returns a word with RC(i) as the first nibble and 0000 as the second. i.e. RCON(1) returns
 *  RC(1), 0 = 8 0 = 1000 0000
 * 
 */
Word RCON(int i){
    //    Word rcon = {RC(i), 0};
    return (Word(RC(i), 0));
}


/*
 *  function: SubNib
 *
 *  description: This function replaces the nibbles with the value of their SBOX index, i.e. nib1 = SBOX[nib1];
 *
 */
Word SubNib(const Word w){
    return (Word(SBOX_lookup[w.getNib1()], SBOX_lookup[w.getNib2()]));
}


/*
 *  function: RotNib
 *
 *  description: This function just switches the position of the two nibbles, i.e. nib1 <-> nib2
 *
 */
Word RotNib(const Word w){
    return (Word(w.getNib2(), w.getNib1()));
}


Word* key_expansion(const Word key1, const Word key2){
    Word* W = new Word[6];
    W[0] = key1;
    W[1] = key2;
    
    for (int i = 2; i < 6; i++){
        if (i % 2 == 0) {
            //            cout << "Calculating W[" << i << "]: W[" << i - 2 << "](" << W[i - 2] << ") XOR ";
            //            cout << "RCON(" << i / 2 << ")(" << RCON(i / 2) << ") XOR";
            //            cout << "SubNib(RotNib(W[" << i - 1 << "](" << SubNib(RotNib(W[i - 1])) << ")\n";
            W[i] = W[i - 2] ^ RCON(i / 2) ^ SubNib(RotNib(W[i - 1]));
        }
        else {
            //            cout << "Calculating W[" << i << "]: W[" << i - 2 << "](" << W[i - 2] << ") XOR ";
            //            cout << "W[" << i - 1 << "](" << W[i - 1] << ")\n";
            W[i] = W[i - 2] ^ W[i - 1];
        }
    }
    
    for (int i = 0; i < 6; i++){
        cout << "W[" << i << "]: " << W[i] << "\n";
    }
    return W;
}


/*
 *
 * function: main
 *
 * description: Just used for testing the other functions; making sure that the key expansion is working correctly
 *
 */
int main() {
    //    Word* key0 = new Word(12, 11);
    //    Word* key1 = new Word(15, 14);
    
    Word* word0 = new Word(5, 9);
    Word* word1 = new Word(7, 10);
    
    Word* word_arr;
    word_arr = key_expansion(*word0, *word1);
    
    Key* key_arr[3];
    for (int i = 0; i < 3; i++)
        key_arr[i] = new Key(word_arr[2 * i], word_arr[2 * i + 1]);
    //    cout << "Key 0: " << key_arr[0].getNib1() << key_arr[0].getNib2() << endl;
    for (int i = 0; i < 3; i++){
        //cout << "Key: " << key_arr[i].getNib1() << key_arr[i].getNib2() << endl;
        cout << "Key " << i <<": " << *key_arr[i] << endl;
    }
    
    return 0;
}
