#include <iostream>
//#include <windef.h>
#include "Word.h"
#include "Key.h"
#include "KeyExpansion.h"
#include <vector>

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

/*
 * function: key_expansion
 *
 * description: This functions performs the core of the key expansion function. 
 * It takes a key and calculates two new keys from it, based on the two words that make up the key.. 
 * The function returns an array of the three keys
 */
vector<Key> key_expansion(const Key key){

    Word W[6];
    // Key* K = new Key[3];
    vector<Key> K(3);

    // cout << "Entering the key expansion function. The first word is " << key.getWord1() << "\n and the second word is " << key.getWord2() << endl;
    W[0] = key.getWord1();
    W[1] = key.getWord2();
    
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
   

    // This will test if the words are getting set correctly 
    /*
    for (int i = 0; i < 6; i++){
        cout << "W[" << i << "]: " << W[i] << "\n";
    }
    */

    for (int i = 0; i < 3; i++){
	    K[i] = Key(W[2 * i], W[2 * i + 1]);
    }
    return K;
}


/*
 *
 * function: main
 *
 * description: Just used for testing the other functions; making sure that the key expansion is working correctly
 *
 */

/*
int main() {

    // cout << "Program starts here. Hello!\n";
 
    Word word0 = Word(5, 9);
    Word word1 = Word(7, 10);

    Key key1 = Key(word0, word1);
    
    // cout << "Word 0 value: " << key1.getWord1().getVal() << endl;
    // cout << "Word 1 value: " << key1.getWord2().getVal() << endl;    

    vector<Key> key_arr(3);
    key_arr = key_expansion(key1);
    
    //for (int i = 0; i < 3; i++)
    //    key_arr[i] = new Key(word_arr[2 * i], word_arr[2 * i + 1]);
    //    cout << "Key 0: " << key_arr[0].getNib1() << key_arr[0].getNib2() << endl;
    for (int i = 0; i < 3; i++){
        //cout << "Key: " << key_arr[i].getNib1() << key_arr[i].getNib2() << endl;
        cout << "Key " << i <<": " << key_arr[i] << endl;
        cout << "Key from getBinary(): " << key_arr[i].getBinary() << endl;
    }


    return 0;
}
*/

