#include <iostream>
#include <random>
using namespace std;
// 2 hangman arrays that prints when someone gets somethign wrong
const string hangmanWithoutArms[5] = {"O","\n|", "/", "\n\\", "-"};
const string hangmanWithArms[5] = {" O","\n-|-", "", "\n /\\"};
// array of alphabet
char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
struct Tester;

void printHangMan(int tries){
    cout<<endl<<endl;
	cout<<"  -----"<<endl;
	cout<<"  |   |"<<endl; 
	cout<<"  |"; if(tries>=1) cout<<"   O    "; cout<<endl;
	cout<<"  |"; if(tries>=3) cout<<"  /|\\   "; cout<<endl;
	cout<<"  |"; if(tries>=5) cout<<"  / \\    "; cout<<endl;
	cout<<"  |"<<endl; 
	cout<<"__|__"<<endl;
}

class Hangman{
    Hangman *leaf[sizeof(alphabet)];
    Hangman();
    ~Hangman();
    void insert();
    bool search();
    
    // the actual word
    Hangman *root;
    bool endOfWord;
};