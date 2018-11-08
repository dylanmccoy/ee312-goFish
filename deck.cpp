#include "card.h"
#include "deck.h"
#include <cstdlib>

using namespace std;

Deck::Deck() {

}           

void Deck::shuffle() {
}

// dealCard
// precondition: deck has cards to deal
Card Deck::dealCard() {
    int cardIndex = this->myIndex;
    if (cardIndex >= 52) {  // if the deck is empty
        return Card();          // returns ace of spades
    }
    else {
        this->myIndex++;
        return this->myCards[cardIndex];
    }
}
