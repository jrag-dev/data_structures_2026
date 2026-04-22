// cardobj.cpp
// cards as objects
#include <iostream>

enum Suit { clubs, diamonds, hearts, spades };
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class Card {
    private:
        int number;         // 2 to 10, jack, queen, king, ace
        Suit suit;          // clubs, diamonds, hearts, spades
    public:
        Card() {}
        Card(int n, Suit s) : number(n), suit(s) {}

        void display();
        bool isEqual(Card);
};

void Card::display() {
    if (number >= 2 && number <= 10)
        std::cout << number << " of ";
    else
        switch (number) {
            case jack: std::cout << "jack of "; break;
            case queen: std::cout << "queen of "; break;
            case king: std::cout << "king of "; break;
            case ace: std::cout << "ace of "; break;
        }
    switch (suit) {
        case clubs: std::cout << "clubs"; break;
        case diamonds: std::cout << "diamonds"; break;
        case hearts: std::cout << "hearts"; break;
        case spades: std::cout << "spades"; break;
    }
}

bool Card::isEqual(Card c2) {
    return (number==c2.number && suit==c2.suit) ? true : false;
}

int main() {
    Card temp, chosen, prize;
    int position;

    Card card1(7, clubs);
    std::cout << "\n\033[31mCard 1 is the ";
    card1.display();
    std::cout << std::endl;
    
    Card card2(jack, hearts);
    std::cout << "\n\033[35mCard 2 is the ";
    card2.display();
    std::cout << std::endl;

    Card card3(ace, spades);
    std::cout << "\n\033[32mCard 3 is the ";
    card3.display();
    std::cout << std::endl;

    prize = card3;

    std::cout << "\nI'm swapping card 1 and card 3";
    temp = card3; card3 = card1; card1 = temp;

    std::cout << "\nI'm swapping card 2 and card 3";
    temp = card2; card2 = card1; card2 = temp;

    std::cout << "\nI'm swapping card 1 and card 2";
    temp = card2; card2 = card1; card1 = temp;

    std::cout << "\nNow, where (1, 2, or 3) is the ";
    prize.display();
    std::cout << "? ";
    std::cin >> position;

    switch (position) {
        case 1: chosen = card1; break;
        case 2: chosen = card2; break;
        case 3: chosen = card3; break;
    }

    if (chosen.isEqual(prize))
        std::cout << "\nThat's right! You win!";
    else
        std::cout << "\nSorry. You lose.";

    std::cout << "  You chose the ";
    chosen.display();
    std::cout << std::endl;

    return 0;
}