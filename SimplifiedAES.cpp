#include <iostream>
#include <vector>
#include "Key.h"
#include "Word.h"
#include "KeyExpansion.h"

using namespace std;

/*
 * function: add_key
 *
 * description: The function add_key(i) consists of XORing key[i] with the current state 
 */

Key add_key(Key k, Key curr){
	return k ^ curr;
}


/*
 * function: nib_sub
 *
 * description: The function nib_sub calls the KeyExpansion SubNib function on both of the words it contains
 */

Key nib_sub(Key k) {
	//k.setWord1(SubNib(k.getWord1()));
	//k.setWord2(SubNib(k.getWord2()));
    return Key(SubNib(k.getWord1()), SubNib(k.getWord2()));
}


/*
 * function: shift_row 
 *
 * description: The function shift row switches the values of each word's second nibble
 * i.e. W0 = N0N1, W1 = N2N3. shift_row() -> W0 = N0N3, W1 = N2N1
 */

Key shift_row(Key k) {
	return (Key(Word(k.getWord1().getNib1(), k.getWord2().getNib2()), Word(k.getWord2().getNib1(), k.getWord1().getNib2())));
}

/*
 * function: mix_column
 *
 * description: This function is pretty complicated, but I'll come back to that. For functionality, and to save time,
 * it's fine to note that MC sends a word b0; b1; b2; b3; b4; b5; b6; b7 to 
 *                b0^b6; b1^b4^b7; b2^b4^b5; b3^b5; b2^b4; b0^b3^b5; b0^b1^b6; b1^b7;
 */

Key mix_column(Key k) {
	
	int add_nib1 = 0;
	int add_nib2 = 0;

    //TODO: Is there a better way to do this?
    Word W[2];
    W[0] = k.getWord1();
    W[1] = k.getWord2();

    string word_bits[2];
    word_bits[0] = W[0].getBinary();
    word_bits[1] = W[1].getBinary();

    for(int i = 0; i < 2; i++){
        add_nib1 = 0;
        add_nib1 += word_bits[i][6];
        add_nib1 = add_nib1 << 1;
        add_nib1 += word_bits[i][4] ^ word_bits[i][7];
        add_nib1 = add_nib1 << 1;
        add_nib1 += word_bits[i][4] ^ word_bits[i][5];
        add_nib1 = add_nib1 << 1;
        add_nib1 += word_bits[i][5];
         
        add_nib2 = 0;
        add_nib2 += word_bits[i][2];
        add_nib2 = add_nib2 << 1;
        add_nib2 += word_bits[i][0] ^ word_bits[i][3];
        add_nib2 = add_nib2 << 1;
        add_nib2 += word_bits[i][0] ^ word_bits[i][1];
        add_nib2 = add_nib2 << 1;
        add_nib2 += word_bits[i][1];
       
        W[i] = Word(W[i].getNib1() ^ add_nib1, W[i].getNib2() ^ add_nib2);
    }

    return Key(W[0], W[1]);
} 

int main(){

Key start_key = Key(Word(5, 9), Word(7, 10));
    vector<Key> keys(3);

    keys = key_expansion(start_key);
    for (int i = 0; i < 3; i++){
        cout << "Key " << i << ": " << keys[i] << endl;
    }
    
	Key pt = Key(Word(4, 5), Word(6, 4));
    
	cout << "Plain text value: " << pt << endl;

	pt = add_key(keys[2], shift_row(nib_sub(add_key(keys[1], mix_column(shift_row(nib_sub(add_key(keys[0], pt))))))));

	cout << "Cipher text value: " << pt << endl;
/*
    pt = add_key(pt, keys[0]);

    cout << "After add key: " << pt << endl;

    pt = nib_sub(pt);

    cout << "After nib sub: " << pt << endl;

    pt = shift_row(pt);

    cout << "After shift row: " << pt << endl;

    pt = mix_column(pt);

    cout << "After mix column: " << pt << endl;
*/
    return 0;
}







