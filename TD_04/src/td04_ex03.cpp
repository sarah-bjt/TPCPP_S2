


#include <iostream>
#include <algorithm>
#include <string>

// Exercice 3 - Palindrome

// q.1

bool is_palindrome(const std::string &mot) {
    return std::equal(mot.begin(), mot.begin() + mot.size() / 2, mot.rbegin());
}

int main() {
    std::string test1 = "hannah";
    std::string test2 = "salut";

    std::cout << test1 << " is palindrome: " << is_palindrome(test1) << std::endl;
    std::cout << test2 << " is palindrome: " << is_palindrome(test2) << std::endl;

    return 0;
}