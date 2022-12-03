#include "hangman.h"

Hangman::Hangman(){
    root = new Hangman();
}

Hangman::~Hangman(){
    delete[] root;
}
