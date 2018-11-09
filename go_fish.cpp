// #include <iostream>    // Provides cout and cin
// #include <cstdlib>     // Provides EXIT_SUCCESS


// #include "card.h"
// #include "player.h"
// #include "deck.h"

// using namespace std;

// int main() {
//     srand(time(NULL));
// }
// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.

#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

//#define GAME_DEBUGGING

// PROTOTYPES for functions used by this demonstration program:


//input params: either name of the player that won or tie!
string declareWinner(string winner);
//output params: announces winner or tie!

//input param: current player, and next player
void changeTurn(Player &cur, Player &next);
//output param: switches current player and next player

//input: card to remove, player to remove from
Card removeCardRank(Card c, Player &p);
//output: returns card that is removed from player's hand

//input: card to check rank, player to check rank from;
Card returnHandRank(Card c, Player p);
//output: returns card that matches the same rank in the input players hand
// void dealHand(Deck &d, Player &p, int numCards);


int main() {
    srand(time(NULL));
    ofstream myfile;
    myfile.open ("gofish_results.txt");
    myfile << "Starting game of Go Fish" << endl;

    Deck d;
    Player p1("Dylan");
    Player p2("Geof");
    Player* currentPlayer = &p1;
    Player* nextPlayer = &p2;

    string turn = "p1";
    Card chosenCard;
    Card addedCard;

    d.shuffle();

    for (int i = 0; i < 7; i++) {
        p1.addCard(d.dealCard());
        p2.addCard(d.dealCard());
    }

    while ((p1.getBookSize() + p2.getBookSize()) < 26) {    // loop through turns until game ends
        if (currentPlayer->getHandSize() == 0) {
            myfile << currentPlayer->getName() << "'s hand is empty" << endl;                               //draw a card if hand is empty, end turn
            if(d.size() != 0) {
                addedCard = d.dealCard();
                currentPlayer->addCard(addedCard);
                myfile << currentPlayer->getName() << " draws " << addedCard.toString() << endl << endl;
            }
            else {
                myfile << "Deck is empty!" << endl << endl;
            }
            changeTurn(*currentPlayer, *nextPlayer);
        }
        else {
            chosenCard = currentPlayer->chooseCardFromHand();
            myfile << currentPlayer->getName() << " asks - Do you have a " << chosenCard.rankString(chosenCard.getRank()) << "?" << endl;
            
            
            #ifdef GAME_DEBUGGING
                myfile << nextPlayer->showHand() << endl;
                myfile << currentPlayer->showHand() << endl;
            #endif


            if (nextPlayer->sameRankInHand(chosenCard)) {
                myfile << nextPlayer->getName() << " says - Yes. I have a " << chosenCard.rankString(chosenCard.getRank()) << "." << endl;
                addedCard = removeCardRank(chosenCard, *nextPlayer); //removes chosen card from one players hand and returns it to asking players hand
                currentPlayer->addCard(addedCard);
                myfile << currentPlayer->getName() << " books " << chosenCard.toString() << " and " << addedCard.toString() << "." << endl << endl;
            }
            else {
                myfile << nextPlayer->getName() << " says - Go Fish." << endl;
                if (d.size() != 0) {
                    addedCard = d.dealCard();
                    if (currentPlayer->sameRankInHand(addedCard)) {
                        Card cardToBook = returnHandRank(addedCard, *currentPlayer);    //checks to see if they draw a card that needs to be booked at every GoFish
                        myfile << currentPlayer->getName() << " draws " << addedCard.toString() << " and books with " << cardToBook.toString() << "." << endl << endl;
                    }
                    else {
                        myfile << currentPlayer->getName() << " draws " << addedCard.toString() << endl << endl;
                    }
                    currentPlayer->addCard(addedCard);
                }
                else {
                    myfile << "Deck is empty!" << endl << endl;
                }
                changeTurn(*currentPlayer, *nextPlayer);
            }
        }
    }

    myfile << p1.getName() <<  " has " << p1.getBookSize() << " books." << endl;
    myfile << p2.getName() <<  " has " << p2.getBookSize() << " books." << endl;

    #ifdef GAME_DEBUGGING
        myfile << "deck has " << d.size() << " cards left." << endl;
        myfile << p1.getName() <<  " hand is " << p1.showHand() << "." << endl;
        myfile << p2.getName() <<  " hand is " << p2.showHand() << "." << endl;
        myfile << p1.getName() <<  " book is " << p1.showBooks() << "." << endl;
        myfile << p2.getName() <<  " book is " << p2.showBooks() << "." << endl;
    #endif

    if (p1.getBookSize() > p2.getBookSize()) {
        myfile << declareWinner(p1.getName()) << endl;
    }
    else if (p1.getBookSize() == p2.getBookSize()) {
        myfile << declareWinner("tie") << endl;
    }
    else {
        myfile << declareWinner(p2.getName()) << endl;
    }
}

string declareWinner(string winner) {
    string str = "";
    if (winner == "tie") {
        str += "There is a tie!";
    }
    else {
        str += winner + " is the winner!";
    }
    return str;
}

// assumes p has a card with same rank as c
Card removeCardRank(Card c, Player &p) {                        //removes the card that matches the rank of the chosen card from the asked persons hand
    int rank = c.getRank();                                     //this is for when players ask other players successfully
    Card card;
    if (p.cardInHand(Card(rank, Card::spades))) {
        card = p.removeCardFromHand(Card(rank, Card::spades));
    }
    else if (p.cardInHand(Card(rank, Card::hearts))) {
        card = p.removeCardFromHand(Card(rank, Card::hearts));
    }
    else if (p.cardInHand(Card(rank, Card::diamonds))) {
        card = p.removeCardFromHand(Card(rank, Card::diamonds));
    }
    else if (p.cardInHand(Card(rank, Card::clubs))) {
        card = p.removeCardFromHand(Card(rank, Card::clubs));
    }
    return card;
}

Card returnHandRank(Card c, Player p){                          //returns the card that matches the rank of the chosen card from the asked players hand
    int rank = c.getRank();                                     //this is for booking cards from GoFishing
    Card card;
    if (p.cardInHand(Card(rank, Card::spades))) {
        card = Card(rank, Card::spades);
    }
    else if (p.cardInHand(Card(rank, Card::hearts))) {
        card = Card(rank, Card::hearts);
    }
    else if (p.cardInHand(Card(rank, Card::diamonds))) {
        card = Card(rank, Card::diamonds);
    }
    else if (p.cardInHand(Card(rank, Card::clubs))) {
        card = Card(rank, Card::clubs);
    }
    return card;
}

void changeTurn(Player &cur, Player &next) {
    Player temp = cur;
    cur = next;
    next = temp;
}

// int main1()
// {
//     ofstream myfile;
//     myfile.open ("gofish_test.txt");
//     myfile << "Writing this to a file.\n";

//     myfile << "Testing card.h" << endl;
//     Card c;

//     myfile << "c is:" << c.toString() << endl;

//     Card c1(3, Card::hearts);
//     Card c2;

//     myfile << "c1 is:" << c.toString() << endl;

//     myfile << "Testing '==' operator" << endl;
//     if(c1 == c2){
//         myfile << "error"<< endl;
//     }else{
//         myfile << "success" << endl;
//     }
//     myfile << "Testing '!=' operator" << endl;
//     if(c1 != c2) {
//         myfile << "success" << endl;
//     } 
//     else {
//         myfile << "error" << endl;
//     }

    
//     myfile << "testing deck.h" << endl;

//     myfile << "testing deck constructors and deal card" << endl;
//     myfile << "________________________________________" << endl;

//     Deck d;
//     Card* temp = new Card;

//     for(int i = 0; i < 53; i++){
//         *temp = d.dealCard();
//         myfile << temp->toString() << endl;
//     }


//     myfile << "testing shuffle with full deck" << endl;
//     myfile << "________________________________________" << endl;

//     Deck d1;

//     d1.shuffle();

//     myfile << "size is:" << d1.size() << endl;
//     for(int i = 0; i < 52; i++){
//         *temp = d1.dealCard();
//         myfile << temp->toString() << endl;
//     }
//     myfile << "size is:" << d1.size() << endl;  //expect 0

//     myfile << "testing shuffle within a deck" << endl;
//     myfile << "________________________________________" << endl;


//     Deck d2;

//     for(int i = 0; i < 25; i++){
//         *temp = d2.dealCard();
//         //myfile << temp->toString() << endl;
//     }

//     d2.shuffle();

//     int size = d2.size();
//     myfile << "size is:" << size << endl;

//     for(int i = 0; i < size; i++){
//         *temp = d2.dealCard();
//         myfile << temp->toString() << endl;
//     }

    
//     myfile << "testing one player functions" << endl;
//     myfile << "________________________________________" << endl;


//     Player p1("Joe");


//     Deck deck;


//     p1.addCard(deck.dealCard());

//     myfile << p1.showHand() << endl;

//     p1.addCard(Card(1, Card::hearts));

//     myfile << p1.showHand() << endl;

//     // myfile << "testing checkHandForBook" << endl;
//     // Card* card1 = new Card;
//     // Card* card2 = new Card;

//     // if(p1.checkHandForBook(*card1, *card2)){
//     //     myfile << "found match" << endl;
//     //     p1.bookCards(*card1, *card2);
//     // }

//     // myfile << "card1 is:" << card1->toString() << endl;
//     // myfile << "card2 is:" << card2->toString() << endl;
//     myfile << p1.showHand() << endl;
//     myfile << p1.showBooks() << endl;


//     myfile << "testing two players asking for cards -- swap success" << endl;
//     myfile << "________________________________________" << endl;


//     Player p2("Dylan");
//     Player p3("Geof");

//     Deck deck2;

//     myfile << "size of deck is: " << deck2.size() << endl;

//     for(int i = 0; i < 7; i++){
//         p2.addCard(deck2.dealCard());
//     }

//     for(int i = 0; i < 7; i++){
//         p3.addCard(deck2.dealCard());
//     }
//     myfile << "p2 hand is: " << p2.showHand() << endl;
//     myfile << "p2 book is: " << p2.showBooks() << endl;
//     myfile << "p3 hand is: " << p3.showHand() << endl;
//     myfile << "p3 book is: " << p3.showBooks() << endl;
//     myfile << "testing chooseCardFromHand()" << endl;
//     myfile << "________________________________________" << endl;

//     for(int i = 0; i < 3; i++){
//         *temp = p2.chooseCardFromHand();
//         myfile << "card: " << i <<" for p2 chose is:"<< temp->toString() << endl;
//     }

//     for(int i = 0; i < 3; i++){
//         *temp = p3.chooseCardFromHand();
//         myfile << "card: " << i << " for p3 chose is:"<< temp->toString() << endl;
//     }

//     if (p2.cardInHand(Card(10, Card::spades))) {
//         myfile << "error: cardInHand" << endl;
//     }
//     else {
//         myfile << "10 of spades not in p2 hand" << endl;
//     }

//     myfile << "p3 asks p2 for Ace of spades" << endl;
//     if (p2.cardInHand(Card(1, Card::spades))) {
//         myfile << "p2 hand:" << p2.showHand() << endl;
//         myfile << "p3 hand:" << p3.showHand() << endl;
//         myfile << "Ace of spades in p2 hand" << endl;
//         p3.addCard(p2.removeCardFromHand(Card(1, Card::spades)));
//         myfile << "p3 should have a book now:" << endl;
//         myfile << p3.showBooks() << endl;
//     }
//     else {
//         myfile << "error: cardInHand" << endl;
//     }

//     myfile << "p2 hand size is:" << p2.getHandSize() << endl;
//     myfile << "p2 book size is:" << p2.getBookSize() << endl;
//     myfile << "p3 hand size is:" << p3.getHandSize() << endl;
//     myfile << "p3 book size is:" << p3.getBookSize() << endl;






//     return EXIT_SUCCESS;  
// }



// void dealHand(Deck &d, Player &p, int numCards)
// {
//    for (int i=0; i < numCards; i++)
//       p.addCard(d.dealCard());
// }
   



