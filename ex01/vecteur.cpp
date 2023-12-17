#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// on met des references constantes pour ne pas copier les vecteurs
void affiche(const std::vector<std::string>& vecteur) {
    for (auto elem : vecteur) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

std::string concatene(const std::vector<std::string>& vecteur) {
    std::string resultat;

    // Utilisation d'un itérateur pour parcourir le vecteur
    for (auto it = vecteur.begin(); it != vecteur.end(); ++it) {
        resultat += *it;  // Concaténer l'élément actuel
        if (it + 1 != vecteur.end()) {
            resultat += " ";  // Ajouter un espace sauf pour le dernier élément
        }
    }
    return resultat;
}

int main() {

    std::vector<std::string> monVecteur = {"bonjour", "comment", "allez", "vous", "?"};

    //on peut aussi faire des push_back pour rajouter des elements

    std::cout << "Taille du vecteur : " << monVecteur.size() << std::endl;
    std::cout << "Capacité du vecteur : " << monVecteur.capacity() << std::endl;

    /*
     La taille du vecteur est le nombre d'éléments réellement stockés,
     tandis que la capacité représente l'espace alloué pour le vecteur,
     qui est superieur ou egales a size pour permettre l'ajout efficace d'éléments supplémentaires sans avoir à réallouer de la mémoire fréquemment.
    */

   //Afficher le contenu du vecteur en utilisant la notation indexée.
    std::cout << "Contenu du vecteur (notation indexée) : ";
    for (size_t i = 0; i < monVecteur.size(); ++i) {
        std::cout << monVecteur[i] << " ";
    }
    std::cout << std::endl;

    //Afficher le contenu du vecteur en utilisant les itérateurs.
    std::cout << "Contenu du vecteur (itérateurs) : ";
    for (std::vector<std::string>::iterator it = monVecteur.begin(); it != monVecteur.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::swap(monVecteur[1], monVecteur[3]);

    //Afficher le contenu du vecteur après l'échange.
    std::cout << "Contenu du vecteur après l'échange : ";
    affiche(monVecteur);

    std::sort(monVecteur.begin(), monVecteur.end());

    std::cout << "Contenu du vecteur après le tri : ";
    affiche(monVecteur);
    //Les symboles sont avant les lettres. Les majuscules sont avant les minuscules. Puis ordre alphabétique.

    std::cout << "Concaténation du vecteur : " << concatene(monVecteur) << std::endl;

    monVecteur.insert(monVecteur.begin() + 1, "à tous");

    std::cout << "Contenu du vecteur après l'insertion : ";
    affiche(monVecteur);

    return 0;
}
