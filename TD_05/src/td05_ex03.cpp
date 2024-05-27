#include<iostream>
#include <string>
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;
    int hash() const; //q.2
};

// q.1
bool operator== (Card const& card1, Card const& card2) {
    return card1.kind == card2.kind && card1.value == card2.value;
}

//q.2

int Card::hash() const{
    int hash {0};
    hash = static_cast<int>(value) + 13*static_cast<int>(kind);
    return hash;
}


//q.3

// utilise hash pour la struc Card
namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

// génére des cartes
#include <vector>
std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}


// 
std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}


int main (){
    Card carte {CardKind::Heart,CardValue::Six};
    std::cout<< carte.hash()<<std::endl;

    //génére 100 cartes 
    std::vector<Card> lot_de_carte {get_cards(100)};
    std::unordered_map<Card, int> tableau {};

    for (const auto& carte : lot_de_carte) {
        tableau[carte]++;
    }

    // Affiche le résultat
    for (const auto& entry : tableau) {
        std::cout << "Card: " << card_name(entry.first)
                  << " appears " << entry.second << " times." << std::endl;
    }

    return 0;
}