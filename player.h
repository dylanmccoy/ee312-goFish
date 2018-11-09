// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "card.h"
using namespace std;


class Player
{
  public:
    //pre:
    Player();
    //post: creates player with no name and 0 cards, 0 books

    //pre: valid name
    Player(string name) {
       myName = name;
    }
    //post: creates player with name and 0 cards, 0 books


    //pre: valid player
    string getName() const {
        return myName;
    }
    //post: return player name

    //pre: valid player, valid card
    void addCard(Card c);  //adds a card to the hand
    //post: add specified card to specified player's hand


    //pre: valid player, valid cards
    void bookCards(Card c1, Card c2);
    //post: removes cards from players hand and adds to book

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.


    //pre: valid player, valid card
    bool checkHandForBook(Card &c1, Card &c2);
    //post: returns true in player has book in hand

    // //OPTIONAL
    // // comment out if you decide to not use it    
    // //Does the player have a card with the same rank as c in her hand?
    // bool rankInHand(Card c) const; 
    
    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"

    //pre: valid player, cards in hand of player
    Card chooseCardFromHand() const;
    //post: returns a randomly chosen card from player's hand

    
    //Does the player have the card c in her hand?
    //pre: valid player, valid card
    bool cardInHand(Card c) const; 
    //post: returns true if specified card is in hand

    //Remove the card c from the hand and return it to the caller
    //pre: valid player, valid card
    Card removeCardFromHand(Card c); 
    //post: returns card removed from players hand

    //pre: valid player
    string showHand() const;
    //post: prints players hand as a string

    //pre: valid player
    string showBooks() const; 
    //post: prints players book as a string

    //pre: valid player
    int getHandSize() const { return myHand.size();}
    //post: returns size of players hand as int

    //pre: valid player
    int getBookSize() const { return myBook.size() / 2;}
    //post: returns size of players book as int


//    //OPTIONAL
//    // comment out if you decide to not use it
//    //this function will check a players hand for a pair.
//    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
//
//    bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c


    //pre: valid player and valid card
    bool sameRankInHand(Card c) const; 
    //post: returns true if the player has the same rank as the card specified in their hand

    
  private:
          
    vector <Card> myHand;
    vector <Card> myBook;
    
    string myName;     
   
};


#endif
