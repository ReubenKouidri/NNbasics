#include <iostream>
#include "Perceptron.hpp"


int main() {
    std::unique_ptr<Perceptron> p = std::make_unique<Perceptron>(2, 1.0);
    //p->setWeights({15, 15, -10});  // OR gate
    p->setWeights({10, 10, -15});  // AND gate
    std::cout << "Gate: \n";
    std::cout << p->forward({0, 0}) << '\n';
    std::cout << p->forward({0, 1}) << '\n';
    std::cout << p->forward({1, 0}) << '\n';
    std::cout << p->forward({1, 1}) << '\n';
    return 0;
}
