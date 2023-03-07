#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include "Perceptron.hpp"


double frand() {
    // static so that only initialised once and reused for all function calls
    static std::mt19937_64 rng(std::random_device{}());
    static std::uniform_real_distribution<double> dist(-1.0, 1.0);
    return dist(rng);
}

Perceptron::Perceptron(size_t inputs, double bias) {
    _bias = bias;
    _weights.resize(inputs + 1);
    std::generate(_weights.begin(), _weights.end(), frand);
};

double Perceptron::sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double Perceptron::forward(std::vector<double>& input) const {
    input.emplace_back(_bias);
    double sum = std::inner_product(_weights.begin(), _weights.end(), input.begin(), (double) 0.0);
    return Perceptron::sigmoid(sum);
}

double Perceptron::forward(const std::vector<double>& il) const {
    std::vector<double> v {il.begin(), il.end()};
    v.emplace_back(_bias);
    double sum = std::inner_product(_weights.begin(), _weights.end(), v.begin(), (double) 0.0);
    return Perceptron::sigmoid(sum);
}

void Perceptron::setWeights(const std::vector<double>& weights){
    if (_weights.size() != weights.size()) {
        throw std::invalid_argument("Input vector size does not match target size");
    }
        _weights = weights;
}
