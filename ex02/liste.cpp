#include <iostream>
#include <list>

int main() {
    std::list<int> liste;
    for (int i = 1; i < 60; i += 2) {
        liste.push_back(i);
    }

    std::cout << "Contenu de la liste : ";
    for (const auto& elem : liste) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    if (liste.size() >= 3) {
        auto it = liste.begin();
        std::advance(it, 2);  // Avancer de deux positions pour atteindre le troisième élément.
        liste.erase(it);
    }

    std::cout << "Contenu de la liste après suppression du troisième élément : ";
    for (const auto& elem : liste) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    //Insérer les 20 entiers impairs suivants.
    for (int i = 61; i < 100; i += 2) {
        liste.push_back(i);
    }

    std::cout << "Contenu de la liste après insertion des 20 entiers suivants : ";
    for (const auto& elem : liste) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
