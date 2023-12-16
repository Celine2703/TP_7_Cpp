#include <iostream>
#include <stack>

// Fonction pour copier une pile
std::stack<int> stack_copy(const std::stack<int>& pile) {
    std::stack<int> pile_copie = pile;  //constructeur par copie

    return pile_copie;
}

// Fonction pour inverser une pile
std::stack<int> stack_reverse(const std::stack<int>& model) {
    std::stack<int> pile_inversee;

    std::stack<int> pile = model;
    while (!pile.empty()) {
        pile_inversee.push(pile.top());
        pile.pop();
    }

    return pile_inversee;
}

int main() {
    std::stack<int> pile;

    // pile = [1, 2, 3]
    pile.push(3);
    pile.push(2);
    pile.push(1);

    //copier
    std::stack<int> pile_copie = stack_copy(pile);

    //inverser
    std::stack<int> pile_inversee = stack_reverse(pile);

    //afficher
    std::cout << "pile : ";
    while (!pile.empty()) {
        std::cout << pile.top() << " ";
        pile.pop();
    }
    std::cout << std::endl;

    std::cout << "copie : ";
    while (!pile_copie.empty()) {
        std::cout << pile_copie.top() << " ";
        pile_copie.pop();
    }
    std::cout << std::endl;

    // Afficher la pile inversée
    std::cout << "inverse : ";
    while (!pile_inversee.empty()) {
        std::cout << pile_inversee.top() << " ";
        pile_inversee.pop();
    }
    std::cout << std::endl;

    return 0;
}
