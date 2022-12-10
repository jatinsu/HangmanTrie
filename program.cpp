#include "hangman.h"
#include <fstream>
#include <ctime>

const int WORD_SIZE = 2315;
string loadWords(){
    string myArray[WORD_SIZE];
    string word;
    int counter = 0;
    ifstream myFile ("proj1_data.txt");
    if(myFile.is_open()){
        while(myFile >> word && counter < WORD_SIZE){
            myArray[counter] = word;
            counter++;
        }
        cout << "Your file was imported!" << endl;
        cout << counter << " words were imported" << endl;
    }else{
        cout << "The word list doesn't exist! (make sure to have it in the same directory)" << endl;
    }
    myFile.close();
    string realWord;
    srand(time(NULL));
    realWord = myArray[rand() % WORD_SIZE];
    return realWord;
}



int main(){
    Hangman* hangman = new Hangman();
    string key;
    string letterToGuess;
    cout << loadWords();
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