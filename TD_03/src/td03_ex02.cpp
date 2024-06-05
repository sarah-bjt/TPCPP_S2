#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <cctype>
#include <cmath>

std::string cin_to_string() {
    std::string expression;
    std::cout << "Votre expression en NPI avec des espaces: ";
    std::getline(std::cin, expression);
    std::cout << "Voici votre expression: " << expression << std::endl;
    return expression;
}

std::vector<std::string> split_string(std::string const& strin) {
    std::istringstream in(strin);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

bool is_floating(std::string const& s) {
    for (char c : s) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}


enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value){
    return Token{TokenType::OPERAND, value, Operator::ADD};
}

Token make_token(Operator op){
    return Token{TokenType::OPERATOR, 0.0f, op};
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> tokens{};
    for(std::string word : words){
        if(is_floating(word)){
            tokens.push_back(make_token(std::stof(word)));
        }
        else if(word == "+"){
            tokens.push_back(make_token(Operator::ADD));
        }
        else if(word == "-"){
            tokens.push_back(make_token(Operator::SUB));
        }
        else if(word == "*"){
            tokens.push_back(make_token(Operator::MUL));
        }
        else if(word == "/"){
            tokens.push_back(make_token(Operator::DIV));
        }
        else if(word == "^"){
            tokens.push_back(make_token(Operator::POW));
        }
        else{
            std::cout << "Error: expression invalide" << std::endl;
        }
    }
    return tokens;
}

float npi_evaluate(std::vector<Token> const& tokens) {
    std::stack<float> stack;
    float result {0};

    for (Token token : tokens) {
        if (token.type == TokenType::OPERAND) {
            stack.push(token.value);
        } else {
            float rightOperand = stack.top();
            stack.pop();
            float leftOperand = stack.top();
            stack.pop();

            switch (token.op) {
                case Operator::ADD:
                    result = leftOperand + rightOperand;
                    break;
                case Operator::SUB:
                    result = leftOperand - rightOperand;
                    break;
                case Operator::MUL:
                    result = leftOperand * rightOperand;
                    break;
                case Operator::DIV:
                    result = leftOperand / rightOperand;
                    break;
                case Operator::POW:
                    result = std::pow(leftOperand, rightOperand);
                    break;
                default:
                    std::cerr << "Erreur: opérateur inconnu" << std::endl;
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
    std::vector<std::string> words = split_string(expression);
    std::vector<Token> tokens = tokenize(words);
    float result = npi_evaluate(tokens);

    std::cout << "Le résultat est: " << result << std::endl;
    return 0;
}