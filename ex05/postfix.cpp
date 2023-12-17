#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>

bool isFulldigit(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int operate(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default:
            std::cerr << "Invalid operator: " << operation << std::endl;
            return 0;
    }
}

int calcule(const std::string& expression) {
    std::stack<int> operands;

    std::istringstream scaner(expression); // Permet de lire un string comme un stream (pour moi : c'est comme le split de 42)
    std::string str;

    while (scaner >> str) {
        if (isFulldigit(str)) { // si c'est un nombre -> on l'ajoute a la pile
            operands.push(std::stoi(str));
        } else if (isOperator(str[0]) && str.size() == 1) { // si c'est un operateur -> on l'applique aux 2 derniers nombres de la pile
            if (operands.size() < 2) {
                throw std::invalid_argument("Pas assez d'operande pour l'operation: '" + str + "' :(");
            }
            int operand2 = operands.top();
            operands.pop();

            int operand1 = operands.top();
            operands.pop();

            int result = operate(str[0], operand1, operand2);
            operands.push(result);
        } else {
            throw std::invalid_argument("Caractere invalide: " + str);
        }
    }

    if (operands.size() == 1) { // si il reste un seul nombre dans la pile -> c'est le resultat
        return operands.top();
    }
    else if (operands.size() > 1) {
        throw std::invalid_argument("Il reste des operandes dans la pile :(");
    }
    else {
        throw std::invalid_argument("L'operation est vide :(");
    }
}

int main() {
    std::string postfixExpression;

    std::cout << "Entrez une expression postfixee: ";
    std::getline(std::cin, postfixExpression);

    try {
        int result = calcule(postfixExpression);
        std::cout << "Voici le resultat: " << result << std::endl;
    } catch (std::invalid_argument& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}
