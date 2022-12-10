#include "hangman.h"

int main(){
    cout << "hi";
    Hangman* hangman = new Hangman();
    string charToString;
    string key = "Hello";
    string keys[5] = {};

    for(int i = 0;  i < (int) key.length(); i++){
        charToString = key[i];
        keys[i] = charToString;
    }
    int n = sizeof(keys)/sizeof(keys[0]);

    // Construct trie
    for (int i = 0; i < n; i++)
        hangman->insert(keys[i]);
    
    cout << hangman->search("H") << endl;

}