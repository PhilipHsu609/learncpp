#ifndef MYDECK_H
#define MYDECK_H

#include <array>

constexpr int DeckSize{52};

enum class CardSuits {
    Clubs,
    Diamonds,
    Hearts,
    Spades,

    MaxSuits
};

enum class CardRanks {
    Rank_2,
    Rank_3,
    Rank_4,
    Rank_5,
    Rank_6,
    Rank_7,
    Rank_8,
    Rank_9,
    Rank_10,
    Rank_Jack,
    Rank_Queen,
    Rank_King,
    Rank_Ace,

    MaxRanks
};

struct Card {
    CardSuits suit{};
    CardRanks rank{};
};

char getCardSuit(const Card &c);
char getCardRank(const Card &c);
int getCardValue(const Card &c);
void printCard(const Card &c);
void printDeck(const std::array<Card, DeckSize> deck);
std::array<Card, DeckSize> createDeck();
void shuffleDeck(std::array<Card, DeckSize> &deck);

#endif