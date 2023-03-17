#include "erengungor_gungor_eren_HW5_DeckHW5.h"

Deck::Deck() //default constructor
{
	size = 0;
	cardp = NULL;
}

Deck::~Deck() //destructor for dynamic arrays
{
	delete[] cardp;
	cardp = NULL;
	size = 0;
}

Deck::Deck(const Deck& copyThis) //deep copy constructor
{
	Card* tempcardp = new Card[copyThis.size];
	for (int i = 0; i < copyThis.size; i++)
	{
		tempcardp[i] = copyThis.cardp[i];
	}
	cardp = tempcardp; 
	size = copyThis.size;
}

Deck Deck::operator+ (const Card& cardToAdd) //Card to deck addition. adds the card to the bottom of the deck.
{
	Deck newdeck; //creating a new deck to return including both decks' elements
	newdeck.cardp = new Card[size + 1];
	for (int i = 0; i < size; i++) 
	{
		newdeck.cardp[i] = cardp[i];
	}
	newdeck.cardp[size] = cardToAdd;
	newdeck.size = size + 1;

	return newdeck;
}

Deck Deck::operator+ (const Deck& deckToAdd) //Deck to deck addition. for a=b+c, add deck c to the bottom of deck b.
{
	Deck newdeck; //creating a new deck to return including both decks' elements
	newdeck.cardp = new Card[size + deckToAdd.size];
	for (int i = 0; i < size; i++) 
	{
		newdeck.cardp[i] = cardp[i];
	}
	for (int j = 0; j < deckToAdd.size; j++)
	{
		newdeck.cardp[size+j] = deckToAdd.cardp[j];
	}
	newdeck.size = size + deckToAdd.size;

	return newdeck;
}

const Deck& Deck::operator= (const Deck& rhs) //Left deck becomes the same as right deck
{
	Card* tempcardp = cardp;
	cardp = new Card[rhs.size];
	for (int i = 0; i < rhs.size; i++)
	{
		cardp[i] = rhs.cardp[i];
	}
	size = rhs.size;
	delete[] tempcardp;

	return *this;
}

int Deck::getSize() const //a getter function to reach the size within free functions
{
	return (*this).size;
}

Card* Deck::getHead() const //a getter function to reach the cardp within free functions
{
	return (*this).cardp;
}

bool operator> (const Deck& lhs, const int rhs) //checks whether the number of cards in a deck is greater than rhs or not
{
	return lhs.getSize() > rhs;
}

bool operator< (const Deck& lhs, const Deck& rhs) //checks whether the number of cards in lhs is greater than the number o cards in rhs
{
	int lhssum = 0, rhssum = 0;
	for (int i = 0; i < lhs.getSize(); i++)
	{
		lhssum += lhs.getHead()[i].energy;
	}
	for (int j = 0; j < rhs.getSize(); j++)
	{
		rhssum += rhs.getHead()[j].energy;
	}

	return lhssum < rhssum;
}

bool operator== (const Deck& lhs, const Deck& rhs) //checks whether the total energy of the cards in both decks are equal or not
{
	int lhssum = 0, rhssum = 0;
	for (int i = 0; i < lhs.getSize(); i++)
	{
		lhssum += lhs.getHead()[i].energy;
	}
	for (int j = 0; j < rhs.getSize(); j++)
	{
		rhssum += rhs.getHead()[j].energy;
	}

	return lhssum == rhssum;
}

Deck Deck::operator- (const int rhs) //deletes the rhs number of cards from the top of the deck.
{
	if (rhs == size || rhs > size)
	{
		Deck newdeck;
		return newdeck;
	}
	else
	{
		Deck newdeck;
		Card* tempcardp = new Card[size - rhs];
		newdeck.cardp = tempcardp; 
		for (int i = rhs; i < size; i++)
		{
			tempcardp[i - rhs] = cardp[i];
		}
		newdeck.size = size - rhs;
		return newdeck; 
	}
}

ostream& operator << (ostream& os, const Deck& deck) //to print cards in a deck 
{
	for (int i = 0; i < deck.getSize(); i++)
	{
		os << (i + 1) << ": " << deck.getHead()[i].name << " - " << deck.getHead()[i].energy << endl;
	}

	return os;
}

Deck& Deck::operator+= (const Deck& rhs) //adds the cards in rhs deck to the bottom of this deck
{
	Card* tempcardp = cardp;
	cardp = new Card[size + rhs.size];
	for (int i = 0; i < size; i++)
	{
		cardp[i] = tempcardp[i];
	}
	for (int j = 0; j < rhs.size; j++)
	{
		cardp[size + j] = rhs.cardp[j];
	}
	size = rhs.size + size;
	delete[] tempcardp;

	return *this;
}

bool operator<= (const Card& lhs, const Deck& rhs) //checks whether the card lhs exists in the deck rhs or not
{
	for (int i = 0; i < rhs.getSize(); i++)
	{
		if (lhs.energy == rhs.getHead()[i].energy && lhs.name == rhs.getHead()[i].name)
		{
			return true;
		}
	}
	return false;
}

Card& Deck::operator[] (const int rhs)  const //returns the card in the deck specified with the given index rhs
{
	return (*this).cardp[rhs];
}