#include "hangman.h"

Hangman::Hangman(){
        this->endOfWord = false;
        for(int i = 0; i < SIZE; i++){
            this->leaf[i] = nullptr;
        }
}

Hangman::~Hangman(){
    delete[] this;
}


void Hangman::insert(string theWord){
    Hangman *temp = this;
    for(int i = 0; i < (int) theWord.length(); i++){
        unsigned char word = theWord[i];
        if(temp->leaf[word] == nullptr){
            temp->leaf[word] = new Hangman();
        }
        temp = temp->leaf[word];
    }
    temp->endOfWord = true;
}

bool Hangman::search(string wordSearch){
    Hangman *temp = this;
    for(int i = 0; i < (int) wordSearch.length(); i++){
        unsigned char word = wordSearch[i];
        temp = temp->leaf[word];
        if(temp == nullptr){
            return false;
        }
    }

    return temp->endOfWord;
}