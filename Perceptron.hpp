#ifndef BASICS_PERCEPTRON_HPP
#define BASICS_PERCEPTRON_HPP

#include <vector>
#include <iostream>


struct Perceptron{
    explicit Perceptron(size_t inputs, double _bias = 1.0);
    static double sigmoid(double x);
    std::vector<double> _weights {};
    double _bias {};
    double forward(std::vector<double>& input) const;
    double forward(const std::vector<double>& il) const;
    void setWeights(const std::vector<double>& weights);
};


#endif //BASICS_PERCEPTRON_HPP
