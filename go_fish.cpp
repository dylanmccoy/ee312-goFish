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


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    ofstream myfile;
    myfile.open ("gofish_results.txt");
    myfile << "Writing this to a file.\n";

    myfile << "Testing card.h" << endl;
    Card c;

    myfile << "c is:" << c.toString() << endl;

    Card c1(3, Card::hearts);
    Card c2;

    myfile << "c1 is:" << c.toString() << endl;

    myfile << "Testing '==' operator" << endl;
    if(c1 == c2){
        myfile << "error"<< endl;
    }else{
        myfile << "success" << endl;
    }
    myfile << "Testing '!=' operator" << endl;
    if(c1 != c2) {
        myfile << "success" << endl;
    } 
    else {
        myfile << "error" << endl;
    }

    
    myfile << "testing deck.h" << endl;

    myfile << "testing deck constructors and deal card" << endl;
    myfile << "________________________________________" << endl;

    Deck d;
    Card* temp = new Card;

    for(int i = 0; i < 53; i++){
        *temp = d.dealCard();
        myfile << temp->toString() << endl;
    }


    myfile << "testing shuffle with full deck" << endl;
    myfile << "________________________________________" << endl;

    Deck d1;

    d1.shuffle();

    myfile << "size is:" << d1.size() << endl;
    for(int i = 0; i < 52; i++){
        *temp = d1.dealCard();
        myfile << temp->toString() << endl;
    }
    myfile << "size is:" << d1.size() << endl;  //expect 0

    myfile << "testing shuffle within a deck" << endl;
    myfile << "________________________________________" << endl;


    Deck d2;

    for(int i = 0; i < 25; i++){
        *temp = d2.dealCard();
        //myfile << temp->toString() << endl;
    }

    d2.shuffle();

    int size = d2.size();
    myfile << "size is:" << size << endl;

    for(int i = 0; i < size; i++){
        *temp = d2.dealCard();
        myfile << temp->toString() << endl;
    }

    
    // // myfile << "testing one player functions" << endl;
    // // myfile << "________________________________________" << endl;


    // // Player p1("Joe");


    // // Deck deck;


    // p1.addCard(deck.dealCard());

    // myfile << p1.showHand() << endl;

    // p1.addCard(Card(1, Card::spades));

    // Card* card1 = new Card;
    // Card* card2 = new Card;

    // if(p1.checkHandForBook(*card1, *card2)){
    //     p1.bookCards(*card1, *card2);
    // }

    // myfile << p1.showHand() << endl;
    // myfile << p1.showBooks() << endl;


    // myfile << "testing two players asking for cards -- swap success" << endl;
    // myfile << "________________________________________" << endl;


    // Player p2("Dylan");
    // Player p3("Geof");

    // Deck deck2;

    // for(int i = 0; i < 7; i++){
    //     p2.addCard(deck2.dealCard());
    // }

    // for(int i = 0; i < 7; i++){
    //     p3.addCard(deck2.dealCard());
    // }

    // myfile << "testing chooseCardFromHand()" << endl;
    // myfile << "________________________________________" << endl;

    // for(int i = 0; i < 3; i++){
    //     *temp = p2.chooseCardFromHand();
    //     myfile << "card chosen is:"<< temp->toString() << endl;
    // }

    // for(int i = 0; i < 3; i++){
    //     *temp = p3.chooseCardFromHand();
    //     myfile << "card chosen is:"<< temp->toString() << endl;
    // }

    // if (p2.cardInHand(Card(10, Card::spades))) {
    //     myfile << "error: cardInHand" << endl;
    // }
    // else {
    //     myfile << "10 of spades not in p2 hand" << endl;
    // }

    // if (p2.cardInHand(Card(1, Card::spades))) {
    //     myfile << "Ace of spades in p2 hand" << endl;
    //     p3.addCard(p2.removeCardFromHand(Card(1, Card::spades)));
    //     myfile << p2.showHand() << endl;
    //     myfile << p3.showHand() << endl;
    // }
    // else {
    //     myfile << "error: cardInHand" << endl;
    // }

    // myfile << "p2 hand size is:" << p2.getHandSize() << endl;
    // myfile << "p2 book size is:" << p2.getBookSize() << endl;
    // myfile << "p3 hand size is:" << p3.getHandSize() << endl;
    // myfile << "p3 book size is:" << p3.getBookSize() << endl;





   /* int numCards = 5;
    Player p1("Joe");
    Player p2("Jane");

    //Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;


    myfile.close();*/
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   



