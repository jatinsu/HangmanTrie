#include "hangman.h"
#include <fstream>
#include <ctime>

const int WORD_SIZE = 2315;
string loadWords(){
    string myArray[WORD_SIZE];
    string word;
    int counter = 0;
    ifstream myFile ("wordlist.txt");
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
    string key, choice, letterToGuess, wordGuess;
    int win = 0;
    int loss = 0;
    cout << "\nWelcome to Hangman!\n";
    cout << "Would you like the computer to randomly pick a word for you to guess (y/n)? ";
    cin >> choice;
    cin.ignore();
    if(choice == "y"){
        key = loadWords();
    }else{
        cout << "Enter the word you would like to guess for yourself: ";
        cin >> key;
        cin.ignore();
    }
    hangman->insert(key);
    string letterArray[(int) key.length()];
    string wrongLetterArray[26];
    while(win != (int) key.length()){
        cout << "Letters that you have guess that are right: ";
        for(int i = 0; i < (int) key.length(); i++){
            cout << letterArray[i];
        }
        cout << endl;
        cout << "Letters that you have guessed that are wrong: ";
        for(int i = 0; i < (int) key.length(); i++){
            cout << wrongLetterArray[i];
        }
        cout << endl;
        cout << "Guess a letter or press 2 to guess the word! ";
        getline(cin, letterToGuess);
        if(letterToGuess == "2"){
            cout << "What do you think the word is? ";
            getline(cin, wordGuess);
            if(wordGuess == key){
                cout << "You guessed correctly!\n";
                break;
            }else{
                cout << "That's not right! ";
                loss--;
            }
        }
        while(letterToGuess.length() > 1){
            cout << "Please only enter one letter!";
            getline(cin, letterToGuess);
        }
        if(hangman->search(letterToGuess)){
            letterArray[win] = letterToGuess;
            win++;
            cout << "Letter " << letterToGuess << " found!\n";
        }else if(hangman->search(letterToGuess) == false){
            cout << "That's the wrong letter!\n";
            wrongLetterArray[loss] = letterToGuess;
            loss++;
        }
        if(loss == 5){
            cout << "You ran out of guesses!";
            break;
        }
    }
    delete hangman;
    cout << "Thank you for playing!";
    return 0;
}