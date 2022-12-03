#include <iostream>
#include <random>
using namespace std;
// 2 hangman arrays that prints when someone gets somethign wrong
const string hangmanWithoutArms[5] = {"O","\n|", "/", "\n\\", "-"};
const string hangmanWithArms[5] = {" O","\n-|-", "", "\n /\\"};
// array of alphabet
char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
struct Tester;

struct Node{
    Node *leaf[sizeof(alphabet)];
    bool endOfWord;
};

struct Hangman{
    friend class Tester;
    Hangman();
    ~Hangman();
    void insert();
    bool search();
    
    // the actual word
    Node *word;
};