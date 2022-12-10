#include <iostream>
#include <random>
using namespace std;
// 2 hangman arrays that prints when someone gets somethign wrong
const string hangmanWithoutArms[5] = {"O","\n|", "/", "\n\\", "-"};
const string hangmanWithArms[5] = {" O","\n-|-", "", "\n /\\"};
// array of alphabet
const char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
#define SIZE 128
struct Tester;

class Hangman{
    Hangman *leaf[sizeof(alphabet)];
    Hangman();
    ~Hangman();
    void insert(string key);
    void insertArray(string theWord);
    bool search(string wordSearch);
    bool endOfWord;
    Hangman *leaf[SIZE];
    Hangman *root = nullptr;
};