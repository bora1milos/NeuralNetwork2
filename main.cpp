#include <iostream>
#include "NeuralNet.h"

int main()
{
    BorisNetAi::NeuralNet* nn = new BorisNetAi::NeuralNet();
    nn->init(10, 5, 4);
    nn->addLayer(10);
    nn->addLayer(3);
    nn->addLayer(4);

    nn->forwardProp();

    delete nn;
    std::cout << "test " << std::endl;
    return 0;
}