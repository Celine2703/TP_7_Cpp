#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void affiche(const std::vector<std::string>& vecteur) {
    for (const auto& elem : vecteur) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

std::string concatene(const std::vector<std::string>& vecteur) {
    std::string resultat;

    // Utilisation d'un itérateur pour parcourir le vecteur
    for (std::vector<std::string>::const_iterator it = vecteur.begin(); it != vecteur.end(); ++it) {
        resultat += *it;  // Concaténer l'élément actuel
        if (it + 1 != vecteur.end()) {
            resultat += " ";  // Ajouter un espace sauf pour le dernier élément
        }
    }
    return resultat;
}

int main() {
    std::vector<std::string> vecteur;

    vecteur.push_back("Bonjour");
    vecteur.push_back("comment");
    vecteur.push_back("allez");
    vecteur.push_back("vous");
    vecteur.push_back("?");

    // ou std::vector<std::string> vecteur = {"bonjour", "comment", "allez", "vous", "?"};

    std::cout << "Taille du vecteur : " << vecteur.size() << std::endl;
    std::cout << "Capacité du vecteur : " << vecteur.capacity() << std::endl;

    /*
     La taille du vecteur est le nombre d'éléments réellement stockés,
     tandis que la capacité représente l'espace alloué pour le vecteur,
     qui peut être plus grand que sa taille actuelle pour permettre l'ajout efficace d'éléments supplémentaires sans avoir à réallouer de la mémoire fréquemment.
    */

   //Afficher le contenu du vecteur en utilisant la notation indexée.
    std::cout << "Contenu du vecteur (notation indexée) : ";
    for (size_t i = 0; i < vecteur.size(); ++i) {
        std::cout << vecteur[i] << " ";
    }
    std::cout << std::endl;

    //Afficher le contenu du vecteur en utilisant les itérateurs.
    std::cout << "Contenu du vecteur (itérateurs) : ";
    for (std::vector<std::string>::iterator it = vecteur.begin(); it != vecteur.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::swap(vecteur[1], vecteur[3]);

    //Afficher le contenu du vecteur après l'échange.
    std::cout << "Contenu du vecteur après l'échange : ";
    affiche(vecteur);

    std::sort(vecteur.begin(), vecteur.end());

    std::cout << "Contenu du vecteur après le tri : ";
    affiche(vecteur);
    //Les symboles sont avant les lettres. Les majuscules sont avant les minuscules. Puis ordre alphabétique.

    std::cout << "Concaténation du vecteur : " << concatene(vecteur) << std::endl;

    vecteur.insert(vecteur.begin() + 1, "à tous");

    std::cout << "Contenu du vecteur après l'insertion : ";
    affiche(vecteur);

    return 0;
}
