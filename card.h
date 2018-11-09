//File Name: card.h
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13

#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
  public:


    enum Suit {spades, hearts, diamonds, clubs};

    //pre:
    Card();          // default, ace of spades
    //post: ace of spades created

    //pre: valid rank and suit
    Card(int rank, Suit s);
    //post: card created with rank and suit

    //pre: valid card
    string toString()              const {return rankString(myRank) + suitString(mySuit);}  // return string version e.g. Ac 4h Js
    //post: returns string representation of the card

    //input: card to check, valid card
    bool sameSuitAs(const Card& c) const;  // true if suit same as c
    //output: true if same suit as c, false otherwise

    //preconditions: valid card
    int  getRank()                 const {return myRank;}  // return rank, 1..13
    //post: returns rank of card as int

    //pre: valid suit
    string suitString(Suit s)      const;  // return "s", "h",...
    //post: returns suit as a string

    //pre: valid rank between 1 and 13
    string rankString(int r)       const;  // return "A", "2", ..."Q"  
    //post: returns rank as a string


    //pre: two valid cards
    bool operator == (const Card& rhs) const;
    bool operator != (const Card& rhs) const;
    //post: corresponding boolean values (for == if rank and suit are matching, return true, else false, vice versa for !=)

    
  private:

    int myRank;
    Suit mySuit;

    
};

ostream& operator << (ostream& out, const Card& c);



#endif
