#include "hangman.h"

Hangman::Hangman(){
    root->endOfWord = false;
    for(int i = 0; i < (int) sizeof(alphabet); i++){
        root->leaf[i] = nullptr;
    }
}

Hangman::~Hangman(){
    delete[] root;
}


