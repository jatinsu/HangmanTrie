#include "hangman.h"

int main(){
    Hangman* hangman = new Hangman();
    string key;
    string letterToGuess;
    cout << "\nWelcome to Hangman!\n";
    cout << "Enter the word you would like to guess: ";
    getline(cin, key);
    hangman->insert(key);
    cout << "Guess a letter! ";
    getline(cin, letterToGuess);
    while(letterToGuess.length() > 1){
        cout << "Please only enter one letter!";
        getline(cin, letterToGuess);
    }
    if(hangman->search(letterToGuess)){
        cout << "Letter " << letterToGuess << " found!\n";
    }
    cout << hangman->search("H") << endl;
    cout << hangman->search("e") << endl;
    cout << hangman->search("l") << endl;
    cout << hangman->search("o") << endl;
    delete hangman;
}