#include <iostream>
#include <string>
#include "card.h"

using namespace std;


Card::Card() {
    this->mySuit = spades;
    this->myRank = 1;
}          

Card::Card(int rank, Suit s) {
    mySuit = s;
    myRank = rank;
}

bool Card::sameSuitAs(const Card& c) const {

}




string Card::suitString(Suit s) const {
    string str = "S";
    return str;
}

string Card::rankString(int r) const {
    string str = "A";
    return str;
}


bool Card::operator == (const Card& rhs) const {

}
bool Card::operator != (const Card& rhs) const {

}