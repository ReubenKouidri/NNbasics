
#ifndef BASICS_MLP_HPP
#define BASICS_MLP_HPP

#include <iostream>
#include <vector>
#include <initializer_list>
#include "Perceptron.hpp"


class MLP {
    std::vector<Perceptron*> _network;
public:
    MLP(const std::initializer_list<Perceptron*>& il);

    [[nodiscard]] double forward(const std::vector<double>& x) const;
};

#endif //BASICS_MLP_HPP
