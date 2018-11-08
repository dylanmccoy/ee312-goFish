#include "card.h"
#include "deck.h"
#include <cstdlib>

using namespace std;

Deck::Deck() {

}           

void Deck::shuffle() {
    for (int i=0; i<SIZE; i++) {
        int r = rand() % SIZE;
        Card temp = this->myCards[i];
        this->myCards[i] = this->myCards[r];
        this->myCards[r] = temp;
    }
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
