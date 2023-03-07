
// #include "MLP.hpp"

#include <iostream>
#include <vector>
#include <initializer_list>
#include "Perceptron.hpp"

typedef std::vector<std::vector<double>> matrix_t;

class MLP {
    double _lr{};
    std::vector<std::unique_ptr<Perceptron>> _network;
    matrix_t _ws{};
    matrix_t _values;

    Perceptron AND { 2, 1.0};
    Perceptron OR {2, 1.0};
    Perceptron NAND {2, 1.0};
    std::vector<double> andWeights {10, 10, -15};
    std::vector<double> orWeights {15, 15, -10};
    std::vector<double> nandWeights {-10, -10, 15};

public:
    MLP(std::vector<std::unique_ptr<Perceptron>>& ps, std::vector<std::vector<double>>&& ws) {
        for (int i = 0; i < ps.size(); i++){
            ps[i]->setWeights(ws[i]);
            _network.emplace_back(std::move(ps[i]));
        }
    }
    MLP(std::initializer_list<Perceptron*> il){
        for (const auto p : il) {
            _network.emplace_back(p);
        }
    }
    explicit MLP(std::vector<std::unique_ptr<Perceptron>> ps): _network {std::move(ps)}
    {}
    double forward(std::vector<double> x) {
        auto out0 = _network[0]->forward(x);
        auto out1 = _network[1]->forward(x);
        return _network[2]->forward({out0, out1});
    }
};
