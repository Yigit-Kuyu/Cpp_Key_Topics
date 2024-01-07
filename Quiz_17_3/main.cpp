#include <iostream>

struct Card{
    enum Rank
{
    rank_ace,
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,

    max_ranks
};


    enum Suit
{
    suit_club,
    suit_diamond,
    suit_heart,
    suit_spade,

    max_suits
};


Rank rankk{};
Suit suit{};



    void printCard() const
    {
        const char *rank_names[] = {
            "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

        const char *suit_names[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

        std::cout << rank_names[rankk] << " of " << suit_names[suit];
    }


            };


int main()
{
    // Print one card
   // The first argument corresponds to Rank rankk{} and the second argument corresponds to Suit suit{} in the Card struct.
   Card card{Card::rank_5, Card::suit_heart}; // initialize  member functions --> rankk{rank_5} and suit(suit_heard)
   card.printCard();
    std::cout << '\n';

    return 0;


}



// Related page: https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz/
