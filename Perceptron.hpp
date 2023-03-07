#ifndef BASICS_PERCEPTRON_HPP
#define BASICS_PERCEPTRON_HPP

#include <vector>
#include <iostream>
#include <cmath>


struct Perceptron{
    explicit Perceptron(size_t inputs, double _bias = 1.0);
    static double sigmoid(double x);
    std::vector<double> _weights {};
    double _bias {};
    double forward(std::vector<double>& input) const;
    double forward(const std::initializer_list<double>& il);
    void setWeights(const std::vector<double>& weights);
};


#endif //BASICS_PERCEPTRON_HPP
