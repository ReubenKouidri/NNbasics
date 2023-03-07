#ifndef BASICS_MLP_HPP
#define BASICS_MLP_HPP

#include <iostream>
#include <vector>
#include "Perceptron.hpp"


class MLP {
    double lr{};
    double bias{};
    std::vector<std::vector<Perceptron>> network;
    std::vector<std::vector<double>> values;
public:
    MLP(size_t _numLayers, double bias = 1.0, double lr = 0.5);

    MLP(std::vector<int>&& layers);

    void createLayer(const size_t numNeurons);

    void setWeights(std::vector<std::vector<std::vector<double>>> ws);

    void printWeights();

    std::vector<double> run(std::vector<double> x);
};

#endif //BASICS_MLP_HPP
