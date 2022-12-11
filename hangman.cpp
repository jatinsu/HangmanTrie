#include "hangman.h"

Hangman::Hangman(){
        this->endOfWord = false;
        for(int i = 0; i < SIZE; i++){
            this->leaf[i] = nullptr;
        }
}

Hangman::~Hangman(){
    Hangman *temp = this;
    for(int i = 0; i < SIZE; i++){
        delete temp->leaf[i];
    }
}

void Hangman::insert(string key){
    string charToString;
    string keys[5] = {};

    for(int i = 0;  i < (int) key.length(); i++){
        charToString = key[i];
        keys[i] = charToString;
    }
    int n = sizeof(keys)/sizeof(keys[0]);
    for (int i = 0; i < n; i++)
        insertArray(keys[i]);
}

void Hangman::insertArray(string theWord){
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