#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <cctype>
#include <cmath>

// Exercice 1 - évaluation NPI
// 1)
std::string cin_to_string() {
    std::string expression;
    std::cout << "Votre expression en NPI avec des espaces: ";
    std::getline(std::cin, expression);
    std::cout << "Voici votre expression: " << expression << std::endl;
    return expression;
}

// 2)
std::vector<std::string> split_string(std::string const& strin) {
    std::istringstream in(strin);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

// 3)
bool is_floating(std::string const& s) {
    for (char c : s) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

// 4)
float npi_evaluate(std::vector<std::string> const& tokens) {
    std::stack<float> stack;
    float result {0};

    for (std::string token : tokens) {
        if (is_floating(token)) {
            stack.push(std::stof(token));
        } else {
            if (stack.size() < 2) {
                std::cerr << "Erreur: expression invalide" << std::endl;
                return 0;
            }
            float rightOperand { stack.top() };
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            if (token == "+") {
                result = leftOperand + rightOperand;
            } else if (token == "-") {
                result = leftOperand - rightOperand;
            } else if (token == "*") {
                result = leftOperand * rightOperand;
            } else if (token == "/") {
                result = leftOperand / rightOperand;
            } else if (token == "^") {
                result = std::pow(leftOperand, rightOperand);
            } else {
                std::cerr << "Erreur: opérateur inconnu " << token << std::endl;
                return 0;
            }
            stack.push(result);
        }
    }
    if (stack.size() != 1) {
        std::cerr << "Erreur: expression invalide" << std::endl;
        return 0;
    }
    return stack.top();
}

int main() {
    std::string expression = cin_to_string();

    std::vector<std::string> tokens = split_string(expression);
    float result = npi_evaluate(tokens);

    std::cout << "Le résultat est: " << result << std::endl;
    return 0;
}
