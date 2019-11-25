#include "Layer.h"

namespace BorisNetAi
{

    Layer::Layer(int neuronCount) 
            : m_neuronCount { neuronCount }
            , m_activations {nullptr}
            , m_deltaActivations {nullptr}
            , m_sums {nullptr}
            , m_deltaSums {nullptr}
            , m_weights {nullptr}
            , m_deltaWeights {nullptr}
            , m_bias {nullptr}
            , m_deltaBias {nullptr}
            , m_previousLayer {nullptr}
            , m_nextLayer {nullptr}
    {

    }

    Layer::~Layer()
    {
        if (m_activations != nullptr)
            delete m_activations;

        if (m_deltaActivations != nullptr)
            delete m_deltaActivations;
        
        if (m_sums != nullptr)
            delete m_sums;
        
        if (m_deltaSums != nullptr)
            delete m_deltaSums;
        
        if (m_weights != nullptr)
            delete m_weights;

        if (m_deltaWeights !=nullptr)    
            delete m_deltaWeights;
        
        if (m_bias != nullptr)
            delete m_bias;
        
        if (m_deltaBias != nullptr)
            delete m_deltaBias;
    }

    void Layer::setInputLayerActivationMatrix(int neuronCount, int batchSize)
    {
        m_activations = new Matrix(neuronCount, batchSize);
        m_deltaActivations = new Matrix(neuronCount, batchSize);

        m_sums = new Matrix(neuronCount, batchSize);
        m_deltaSums = new Matrix(neuronCount, batchSize);

        m_weights = new Matrix(neuronCount, batchSize);
        m_deltaWeights = new Matrix(neuronCount, batchSize);

        m_bias = new Matrix(neuronCount, 1);
        m_deltaBias = new Matrix(neuronCount, 1);
    }

    void Layer::setPreviousLayer(Layer* previousLayer, int batchSize) 
    {
        m_activations = new Matrix(m_neuronCount, batchSize);
        m_deltaActivations = new Matrix(m_neuronCount, batchSize);

        m_sums = new Matrix(m_neuronCount, batchSize);
        m_deltaSums = new Matrix(m_neuronCount, batchSize);

        m_weights = new Matrix(m_neuronCount, batchSize);
        m_weights->randomize();
        m_deltaWeights = new Matrix(m_neuronCount, batchSize);

        m_bias = new Matrix(m_neuronCount, 1);
        m_deltaBias = new Matrix(m_neuronCount, 1);

        m_previousLayer = previousLayer;
        m_previousLayer->m_nextLayer = this;
    } 

    void Layer::feedForward()
    {
        if (m_previousLayer != nullptr)
        {
            m_sums->MUL(*m_weights, *m_previousLayer->m_activations);
            m_sums->ADD_COLL_VEC(*m_bias);
        }

        if (m_nextLayer != nullptr)
        {
            // Perform tha activation function
            if (m_previousLayer != nullptr)
                m_sums->applyFunction(*m_activations, m_funcAct);

            m_nextLayer->feedForward();
        }
    }

    void Layer::setActivationFunction(NEURON_ACTIVATION_FUNCTION funcAct, NEURON_ACTIVATION_FUNCTION funcDerv)
    {
        m_funcAct = funcAct;
        m_funcDerv = funcDerv;


    }
}