#include "card.h"
#include "deck.h"
#include <cstdlib>

using namespace std;

Deck::Deck() {                                      //creates a deck that starts with Ace of spades, 2 of spades, ..., A of hearts, 2 of hearts... etc. in that order
    myIndex = 0;
    Card temp;
    for (int i = 0; i < 13; i++) {
        myCards[i] = Card(i+1, Card::spades);
    }
    for (int i = 13; i < 26; i++) {
        myCards[i] = Card(i-12, Card::hearts);
    }
    for (int i = 26; i < 39; i++) {
        myCards[i] = Card(i-25, Card::diamonds);
    }
    for (int i = 39; i < 52; i++) {
        myCards[i] = Card(i-38, Card::clubs);
    }
}           

void Deck::shuffle() {
    for (int i=0; i<52; i++) {
        int r = rand() % 52;
        Card temp = myCards[i];
        myCards[i] = myCards[r];
        myCards[r] = temp;
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
