#include "myDeck.h"

#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <random>

char getCardSuit(const Card &c) {
    switch (c.suit) {
        case CardSuits::Clubs:
            return 'C';
        case CardSuits::Diamonds:
            return 'D';
        case CardSuits::Hearts:
            return 'H';
        case CardSuits::Spades:
            return 'S';
        default:
            return ' ';
    }
}

char getCardRank(const Card &c) {
    switch (c.rank) {
        case CardRanks::Rank_10:
            return 'T';
        case CardRanks::Rank_Jack:
            return 'J';
        case CardRanks::Rank_Queen:
            return 'Q';
        case CardRanks::Rank_King:
            return 'K';
        case CardRanks::Rank_Ace:
            return 'A';
        default:
            return static_cast<int>(c.rank) + 2 + '0';
    }
}

int getCardValue(const Card &c) {
    switch (c.rank) {
        case CardRanks::Rank_Jack:
        case CardRanks::Rank_Queen:
        case CardRanks::Rank_King:
            return 10;
        case CardRanks::Rank_Ace:
            return 11;
        default:
            return static_cast<int>(c.rank) + 2;
    }
}

void printCard(const Card &c) {
    char suit{getCardSuit(c)};
    char rank{getCardRank(c)};
    std::cout << rank << suit << " ";
}

void printDeck(const std::array<Card, DeckSize> deck) {
    for (auto &card : deck) {
        printCard(card);
    }
    std::cout << std::endl;
}

std::array<Card, DeckSize> createDeck() {
    std::array<Card, DeckSize> deck;

    int suitSize{static_cast<int>(CardSuits::MaxSuits)};
    int rankSize{static_cast<int>(CardRanks::MaxRanks)};

    for (auto suit{0}; suit < suitSize; suit++) {
        for (auto rank{0}; rank < rankSize; rank++) {
            int index{suit * rankSize + rank};
            deck[index].rank = static_cast<CardRanks>(rank);
            deck[index].suit = static_cast<CardSuits>(suit);
        }
    }

    return deck;
}
void shuffleDeck(std::array<Card, DeckSize> &deck) {
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(deck.begin(), deck.end(), mt);
}