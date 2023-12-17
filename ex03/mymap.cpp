#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, float> facture;

    facture["Salade"] = 10.5;
    facture["Gigot"] = 15.0;
    facture["Tiramisu"] = 6.0;
    facture["Burger"] = 12.0;

    std::cout << "Contenu de la facture:" << std::endl;
    for ( auto& plat : facture)
    {
        std::cout << plat.first << ": " << plat.second << " euros" << std::endl;
    }

    float total = 0;
    for (auto plat : facture)
    {
        total += plat.second;
    }

    std::cout << "Prix total: " << total << " euros" << std::endl;

    return 0;
}