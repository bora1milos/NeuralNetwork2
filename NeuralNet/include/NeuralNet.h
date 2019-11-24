#ifndef _NEURAL_NET_
#define _NEURAL_NET_

#include <vector>

#include "Layer.h"
#include "TraningSet.h"

namespace BorisNetAi
{
    class NeuralNet
    {
        public:
            NeuralNet();

            ~NeuralNet();

            void init(int inputNeuronCount, int trainingSetBatchSize, int outputNeuroncount);
            
            void addLayer(int neuronCount);

            void forwardProp();

            void backProp();

        private:
            std::vector<Layer* > m_layer;
            TraningSet* m_traningSet;
            int m_trangSetBatchSize;

    };
}

#endif // _NEURALNET_