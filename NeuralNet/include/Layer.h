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

            void feedForward();

            void backProp();

            void setActivationFunction(NEURON_ACTIVATION_FUNCTION funcAct, NEURON_ACTIVATION_FUNCTION funcDerv);

            // Getters
            
            // Setters
            void setInputLayerActivationMatrix(int neuronCount, int batchSize);
            void setPreviousLayer(Layer* previousLayer, int batchSize);

        private:
            // Activations after activation function
            Matrix* m_activations;
            // Activation prior to activation function
            Matrix* m_sums;
            //
            Matrix* m_bias;
            // Weights to privious layer
            Matrix* m_weights; 

            Matrix* m_deltaSums;
            Matrix* m_deltaBias;
            Matrix* m_deltaActivations;
            Matrix* m_deltaWeights; 

            int m_neuronCount;

            Layer *m_previousLayer;
            Layer *m_nextLayer;

            NEURON_ACTIVATION_FUNCTION m_funcAct;
            NEURON_ACTIVATION_FUNCTION m_funcDerv;

    };
}

#endif // _Layer_