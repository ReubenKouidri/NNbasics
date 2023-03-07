
#include <vector>
#include "Perceptron.hpp"
#include "MLP.hpp"


MLP::MLP(const std::initializer_list<Perceptron*>& il){
    for (const auto p : il)
        _network.emplace_back(p);
}

double MLP::forward(const std::vector<double>& x) const{
    auto out0 = _network[0]->forward(x);  // OR
    auto out1 = _network[1]->forward(x);  // NAND
    return _network[2]->forward({out0, out1});  // NAND
}
