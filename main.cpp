#include <iostream>
#include <vector>
#include "MLP.hpp"


int main() {
    auto* AND = new Perceptron {2, 1.0};
    auto* NAND = new Perceptron(2, 1.0);
    auto* OR = new Perceptron(2, 1.0);
    OR->setWeights({15, 15, -10});  // OR gate
    AND->setWeights({10, 10, -15});  // AND gate
    NAND->setWeights({-10, -10, 15});
    MLP mlp ({OR, NAND, AND});
    
    std::cout << mlp.forward({0, 0}) << '\n';
    std::cout << mlp.forward({0, 1}) << '\n';
    std::cout << mlp.forward({1, 0}) << '\n';
    std::cout << mlp.forward({1, 1}) << '\n';
    return 0;
}
