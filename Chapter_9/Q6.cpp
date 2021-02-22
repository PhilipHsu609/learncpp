#include "myDeck.h"

int main() {
    auto deck{createDeck()};
    printDeck(deck);
    shuffleDeck(deck);
    printDeck(deck);
    return 0;
}