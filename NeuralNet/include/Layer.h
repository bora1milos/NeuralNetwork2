#ifndef _LAYER_
#define _LAYER_

#include "Matrix.h"

namespace BorisNetAi
{
    class Layer
    {
        public:
            Layer(int neuronCount);

            ~Layer();

            void forwardProp();

            void backProp();

            void setPreviousLayer(Layer* previousLayer) {m_previousLayer = previousLayer;} 

        private:
            Matrix* m_activations;
            Matrix* m_sums;
            Matrix* m_bias;
            Matrix* m_weights; 

            Matrix* m_deltaSums;
            Matrix* m_deltaBias;
            Matrix* m_deltaActivations;
            Matrix* m_deltaWeights; 

            int m_neuronCount;

            Layer *m_previousLayer;
            Layer *m_nextLayer;

    };
}

#endif // _Layer_