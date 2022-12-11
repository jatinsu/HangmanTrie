#include <iostream>
#include <random>
#include <fstream>
#include <ctime>
using namespace std;
// array of alphabet
const char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
#define SIZE 128
struct Tester;
const int WORD_SIZE = 2315;

struct Hangman{
    Hangman();
    ~Hangman();
    void printHangMan(int tries){
        cout<<endl<<endl;
        cout<<"  -----"<<endl;
        cout<<"  |   |"<<endl; 
        cout<<"  |"; if(tries>=1) cout<<"   O    "; cout<<endl;
        cout<<"  |"; if(tries>=3) cout<<"  /|\\   "; cout<<endl;
        cout<<"  |"; if(tries==5) cout<<"  / \\    "; cout<<endl;
        cout<<"  |"<<endl; 
        cout<<"__|__"<<endl;
    }
    void insert(string key);
    void insertArray(string theWord);
    bool search(string wordSearch);
    bool endOfWord;
    string loadWords();
    void program();
    Hangman *leaf[SIZE];
    Hangman *root = nullptr;
};