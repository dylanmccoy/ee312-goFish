#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "player.h"

using namespace std;

Player::Player() {
    cout << "invalid player" << endl;
}

void Player::addCard(Card c) {
    myHand.push_back(c);
    Card* card1 = new Card;
    Card* card2 = new Card;
    if (checkHandForBook(*card1, *card2)) {
        bookCards(*card1, *card2);
    }
}

// assumes checkHandForBook has already been called
// precondition: c1 and c2 are both in players hand, and they are the same
void Player::bookCards(Card c1, Card c2) {
    Card card1 = removeCardFromHand(c1);
    Card card2 = removeCardFromHand(c2);
    myBook.push_back(card1);
    myBook.push_back(card2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair. 
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2) {
    for (auto it1 = myHand.begin(); it1 != myHand.end(); it1++) {
        for (auto it2 = it1 + 1; it2 != myHand.end(); it2++) {
            if (it1->getRank() == it2->getRank()) {
                c1 = *it1;
                c2 = *it2;
                return true;
            }
        }
    }
    return false;
}

// //OPTIONAL
// // comment out if you decide to not use it    
// //Does the player have a card with the same rank as c in her hand?
// bool Player::rankInHand(Card c) const {

// }

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const {
    int r = rand() % myHand.size();
    auto iter = myHand.begin() + r;
    return *iter;
} 

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const {
    for (auto iter = myHand.begin(); iter != myHand.end(); iter++) {
        if (*iter == c) {
            return true;
        }
    }
    return false;
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c) {
    Card card;
    for (auto iter = myHand.begin(); iter != myHand.end(); iter++) {
        if (*iter == c) {
            card = c;
            myHand.erase(iter);
            return card;
        }
    }
    return card;
}

string Player::showHand() const {
    string str = "[";
    for(auto it = myHand.begin(); it != myHand.end(); it++) {
        str += it->toString();
        if (it != myHand.end()-1) {
            str += ", ";
        }
    }
    str += "]";
    return str;
} 

string Player::showBooks() const {
    string str = "{";
    for (auto it = myBook.begin(); it != myBook.end(); it += 2) {
        str += "[" + it->toString() + ", " + (it+1)->toString() + "]";
        if (it != myBook.end()-2) {
            str += ", ";
        }
    }
    str += "}";
    return str;
}


    
//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair. 
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

//bool Player::checkHandForPair(Card &c1, Card &c2) {
//
//}

//OPTIONAL
// comment out if you decide to not use it    
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

bool Player::sameRankInHand(Card c) const {
    for( auto iter = myHand.begin(); iter != myHand.end(); iter++) {
        if (iter->getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}



