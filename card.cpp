#include <iostream>
#include <string>
#include <sstream>
#include "card.h"

using namespace std;


Card::Card() {
    myRank = 1;
    mySuit = spades;
}          

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

bool Card::sameSuitAs(const Card& c) const {
    return this->mySuit == c.mySuit;
}

string Card::suitString(Suit s) const {
    if (s == spades) {
        return "s";
    }
    else if (s == hearts) {
        return "h";
    }
    else if (s == diamonds) {
        return "d";
    }
    else {
        return "c";
    }
}

string Card::rankString(int r) const {
    if (r == 1) {
        return "A";
    }
    else if (r == 11) {
        return "J";
    }
    else if (r == 12) {
        return "Q";
    }
    else if (r == 13) {
        return "K";
    }
    else {
        string out_string;
        stringstream ss;
        ss << r;
        out_string = ss.str();
        return out_string;
    }
}


bool Card::operator == (const Card& rhs) const {
    if (this->mySuit == rhs.mySuit) {
        if (this->myRank == rhs.myRank) {
            return true;
        }
    }
    return false;
}
bool Card::operator != (const Card& rhs) const {
    if ((this->mySuit != rhs.mySuit) || (this->myRank != rhs.myRank)) {
        return true;
    }
    return false;
}

ostream& operator << (ostream& out, const Card& c) {
    out << c.toString();
    return out;
}