//Eren Güngör
//29465
//Lab Section C2
//Homework5 with VS2012

#include <string>
#include <sstream>
using namespace std;

struct Card
{
    string name;
    int energy;
};

class Deck
{
public:
	//member functions
    Deck(); //default constructor
    ~Deck(); //destructor
    Deck(const Deck& copy); //deep copy constructor
    Deck operator+ (const Card& cardToAdd); //Card to deck addition. adds the card to the bottom of the deck.
    Deck operator+ (const Deck& deckToAdd); //Deck to deck addition. for a=b+c, add deck c to the bottom of deck b.
    const Deck& operator= (const Deck& rhs); //Left deck becomes the same as right deck
    int getSize() const; //a getter function to reach the size within free functions
    Card* getHead() const; //a getter function to reach the cardp within free functions
    Deck& operator+= (const Deck& rhs); //adds the cards in rhs deck to the bottom of this deck
    Card& operator[] (const int rhs) const; //returns the card in the deck specified with the given index rhs
    Deck operator- (const int rhs); //deletes the rhs number of cards from the top of the deck.
    
private: 
	//private member variables
    Card *cardp; //pointer that points to the dynamic array consisting of cards
    int size; //number of cards in the deck
};

//free funtions
bool operator< (const Deck& lhs, const Deck& rhs); //checks whether the number of cards in lhs is greater than the number o cards in rhs
bool operator> (const Deck& lhs, const int rhs); //checks whether the number of cards in a deck is greater than rhs or not
bool operator== (const Deck& lhs, const Deck& rhs); //checks whether the total energy of the cards in both decks are equal or not
ostream& operator << (ostream& os, const Deck& deck); //to print cards in a deck
bool operator<= (const Card& lhs, const Deck& rhs); //checks whether the card lhs exists in the deck rhs or not
